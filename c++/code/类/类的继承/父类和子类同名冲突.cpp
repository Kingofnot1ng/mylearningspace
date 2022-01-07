#include <iostream>

using namespace std;

class A{
public:
	int a; 
	static int b; 
	A(){
		a=100;
	}
	
	void func(){
		cout<<"父类调用成员函数"<<endl;
	}
	
	static void sfunc(){
		cout<<"父类调用静态成员函数"<<endl;
	}
};
class B1:public A{
public:	
	int a;
	static int b;
	B1(){
		a=200;
	}
	
	void func(){
		cout<<"子类调用成员函数"<<endl;
	}
	
	static void sfunc(){
		cout<<"子类调用静态成员函数"<<endl;
	}
};
int A::b = 1000;
int B1::b = 2000;
int main(){ 
	A a1;
	cout<<a1.a<<endl;
	cout<<A::b<<endl;
	a1.func();
	cout<<"-------------------"<<endl;
	B1 b1; 
	cout<<b1.a<<endl;
	cout<<b1.b<<endl;
	b1.func();
	cout<<"-------------------"<<endl; 
	//通过子类访问父类中的同名变量 
	cout<<b1.A::a<<endl;
	//通过子类访问父类中的同名函数 
	b1.A::func();
	//通过实例化子类对象访问父类中的同名静态变量 
	cout<<b1.A::b<<endl;
	// 通过子类名访问父类中的同名静态变量
	cout<<B1::A::b<<endl;
	return 0;
}
