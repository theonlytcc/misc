#include "stdafx.h"
#include "how_vector.h"
using namespace std;
class Mytt 
{
public:
	static int count;
	Mytt(int a1, int b1) :my_a(a1), my_b(b1) { count++; cout << "constructor:" <<count<< endl; }
	Mytt():my_a(0), my_b(0) { cout << "constructor" << endl; }
	Mytt(const Mytt& a1) : my_a(a1.GetA()), my_b(a1.GetB()) { cout << "constructor" << endl; }
	Mytt(Mytt&& a1) { cout << "constructor" << endl; }
	Mytt& operator=(Mytt& a1) {}
	Mytt& operator=(Mytt&& a1) { my_a = a1.GetA();my_b=a1.GetB(); cout << "constructor" << endl; }
	virtual ~Mytt() { cout << "deconstructor" << endl; }
	virtual int GetA() const { return my_a; }
	virtual int GetB() const { return my_b; }
private:
	int my_a;
	int my_b;
};
int Mytt::count = 0;//静态成员变量类外定义以及初始化
class Little_Mytt :public Mytt
{
public:
	Little_Mytt(int a1,int b1) :Mytt(a1-1,b1-1),my_La(a1), my_Lb(b1) { count++; cout << "Lconstructor:" << count << endl; }
	Little_Mytt() :Mytt(),my_La(0), my_Lb(0) { cout << "Lconstructor" << endl; }
	~Little_Mytt() { cout << "Ldeconstructor" << endl; }
	int GetA() const { return my_La; }
	int GetB() const { return my_Lb; }
private:
	int my_La;
	int my_Lb;
};
void use_vector()
{
	int a;
	std::remove_reference<decltype((a))>::type b = 10;//利用remove获得类型，这个很重要啊
//	std::remove_reference_t<decltype((a))> b = 10;//利用remove获得类型，这个很重要啊
	cout << "This will test a lot of attribution about the vector" << endl;
	vector<int> my_first(2, 10);
	for (vector<int>::iterator a = my_first.begin(); a != my_first.end(); ++a)
		cout << *a;
	cout << endl;
	my_first[0] = 1;
	my_first[1] = 2;
	cout << "after using the operator []:" << endl;
	for (vector<int>::iterator a = my_first.begin(); a != my_first.end(); ++a)
		cout << *a;
	cout << endl;
	my_first.push_back(3);
	my_first.insert(my_first.end(), 4);
	vector<int> my_second(1, 5);
	my_first.insert(my_first.end(), my_second.begin(),my_second.end());
	my_first.insert(my_first.end(),4,10);
	for (vector<int>::iterator a = my_first.begin(); a != my_first.end(); ++a)
		cout << *a;
	cout << endl;
	/***************my class***********************************/
	vector<Mytt> mytt_group(1, {1,2});
	cout<<"let me see"<<endl;
	/**************测试隐藏的效果**********************************/
	Little_Mytt my_little(12,16);
	cout<<"the children:"<<my_little.GetA()<<endl;
	cout << "the base:" << my_little.Mytt::GetA()<<endl;
}
