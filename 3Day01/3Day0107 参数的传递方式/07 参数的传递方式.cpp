#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//1、值传递
void  mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << " b = " << b << endl;
}
//2、址传递
void  mySwap02(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	cout << "a = " << *a << " b = " << *b << endl;
}
//3、引用传递：相当于建立起了链接：int &a = a;
void  mySwap03(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << " b = " << b << endl;
}
void test01()
{
	int a = 10;
	int b = 20;
	//mySwap01(a, b);
	//cout << "a = " << a << " b = " << b << endl;
	//mySwap02(&a, &b);
	//cout << "a = " << a << " b = " << b << endl;
	mySwap03(a, b);
	cout << "a = " << a << " b = " << b << endl;
}

int& func()
{
	int a = 10;
	return a;
}
//4、引用注意事项
void test02()
{
	//4.1 引用必须引用一块合法内存空间
	//int& a = 10;
	//4.2 不要返回局部变量的引用
	int& ret = func();
	cout << "ret = " << ret << endl;
	cout << "ret = " << ret << endl;
}
//4.3可以返回局部静态变量的引用
int& func2()
{
	static int a = 10;
	return a;
}
void test03()
{
	int& ret = func2();
	cout << "ret = " << ret << endl;
	cout << "ret = " << ret << endl;
	//4.4 当函数返回值是引用，那么函数的调用可以作为左值
	func2() = 1000;
	cout << "ret = " << ret << endl;
}
int main(void)
{
	//test01();
	//test02();
	test03();
	return EXIT_SUCCESS;
}