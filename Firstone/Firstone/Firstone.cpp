// Firstone.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int fobi(const int&);
class Mammal
{
public:
	Mammal();
	~Mammal();
	int GetItsAge() const;
	int GetItsName() const;
protected:
	int itsAge;
	int itsName;
};
int main()
{   
	char response;
	char R79N[18] = {'\0'};
	int Myname[5] = {0,1,2,3,4};
	int(*yourName)[5] = &Myname;
	unsigned int a=1, b=2, c;
	int const *p =NULL;
	c = a - b;
	int d = c,e;
	int &m = d;
	(e = a )= 2;
	m = 13;
	int L;
	char w[a];
	(L = 10) = 100;
	cout << "利用引用m输出:"<<m<<endl;
	cout << "利用普通d输出:" << d << endl;
	cout << "左值测试输出:" << L<< endl;
	cout << "左值测试2，此时e：" << e << "此时a:" << a << endl;
	enum a {monday,tuesday,wednesday,thursday,friday,saturday,sunday};
	std::cout << monday << std::endl;
	std::cout << "c=" << c ;
	std::cout << "\nd=" << d << std::endl;
	int mm = 6;
	std::cout<<"the end fobi is"<<fobi(6)<<std::endl;
	Mammal &myMammal = *(new Mammal);
	(&myMammal)->GetItsAge();
	////////////////////////
	//int **z = new int *[3];
	//int(**p)[2] = new (int(*)[2]);
	//int*(*w)[3] = new int*[3][3];//new了一个二维指针数组 一个一维指针数组的指针
	//int (*x)[4] = new int[][4];
	////cout << "数组指针的大小：" << sizeof(x) << endl;
	////cout << "数组指针的大小：" << sizeof(*x) << endl;
	////cout << "数组指针的大小：" << sizeof(**x) << endl;
	//delete []x;
	//p[0] = new int[2][2];
	//p[1] = new int[2][2];
	//p[2] = new int[2][2];
	//delete[] p[0];
	//delete[] p[1];
	//delete[] p[2];
	/*delete[] p;*/
	//std::string strl("I need water\n");
	//cout<<  strl<<  endl;//用printf输出会乱码，看来p内部的编码方式不一样
	//strl = "hahahah i need water";
	//cout << strl << endl;
	//std::cout << "hello world\n";
	//std::cin >> response;
	//int x, y;
	//x = 5;
	//y = 7;
	//std::cout << std::endl;
	//std::cout << x + y << " " << x * y;
	//std::cout << std::endl;
	//cout << "hello world\n"<<sizeof(int);
	//cout << "My name initial" << Myname[0] << endl;
	//int i = 0;
	//for (i = 0; i < sizeof(Myname)/sizeof(int); i++)
	//	printf("%d\n",Myname[i]);
	//printf("%d\n", Myname);
	//printf("%d\n", *yourName);
	//printf("%d\n", (*yourName)[2]);//指针的方括号的结合顺序大于指针
	//cin.get(R79N,18);
	//printf("我是帅哥%s", R79N);
    return 0;
}
int fobi(const int &n)
{
	if (n <= 2)
	{
		std::cout << "fobi(" << n << ")=1" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "fobi(" << n << ")=fobi(" << n - 1 << ")+fobi(" << n - 2 << ")" << std::endl;
		return fobi(n - 1) + fobi(n - 2);
	}
}


Mammal::Mammal():
itsAge(30),
itsName(145)
{
	cout << "you are success" << endl;
}
Mammal::~Mammal()
{
	cout << "It is dead" << endl;
}
int Mammal::GetItsAge() const
{
	cout << "Its age is " << itsAge << endl;
	return itsAge;
}
int Mammal::GetItsName() const
{
	cout << "Its name is" << itsName << endl;
	return itsName;
}


