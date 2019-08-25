#include "stdafx.h"
#include "AboutC11.h"

class A
{
public:
	A() { my_tc = new int(24); std::cout << "construct:" << my_tc << std::endl; }
	A(int tc) { my_tc = new int(tc); std::cout << "construct:" << my_tc << std::endl; }
	~A() { std::cout << "deconstruct:" << my_tc << std::endl; delete my_tc; }
	A(const A& myA)
	{
		my_tc = new int(); *my_tc = *myA.my_tc; std::cout << "copy construct" << std::endl;
	}
	A(A&& myA) noexcept
	{
		my_tc = myA.my_tc;
		myA.my_tc = nullptr;
		std::cout << "move construct" << std::endl;
	}
	A& operator = (A&& myA)
	{
		my_tc = myA.my_tc;
		myA.my_tc = nullptr;
		std::cout << "Move Assignment construct" << std::endl;
		return *this;
	}
	A& operator =(A& myA)
	{
		my_tc = new int();
		*my_tc = *myA.my_tc; std::cout << "copy Assignment construct" << std::endl;
		return *this;
	}
	void Getmy_tc()const { std::cout << "your tc:" << *my_tc << std::endl; }
private:
	int* my_tc;
};
A getA()
{
	return A(25);
}
void usetheC11()
{
	using namespace std;
	cout << "first let me check about the move constructor" << endl;
	//A* firsta = new A(6);
	//cout << "*************************" << endl;
	//A second = A(7);
	//cout << "*************************" << endl;
	//A third = second;
	//cout << "*************************" << endl;
	//A sixth = second;
	//cout << "*************************" << endl;
	//sixth = second;
	//cout << "*************************" << endl;
	//A&& forth = std::move(second);
	//cout << "*************************" << endl;
	//A fiveth = std::move(second);;
	//cout << "*************************" << endl;
	//sixth = A(8);
	//cout << "*************************" << endl;
	//delete firsta;
	//firsta = nullptr;
	//A w;
	A w = getA();
	/**************ÊÔÑé ²Ù×÷·ûdecltype***********/
	//int a = 1;
	//int *b = &a;
	//decltype(*b) c = 1;
	/******************************************/
	//cout << typeid(4.5).name() << endl;
	//int a = 1, b = 2, c = 3;
	//a = b = 3;
	/*cout << "a:" << a << "b:" << b << endl;*/
}
