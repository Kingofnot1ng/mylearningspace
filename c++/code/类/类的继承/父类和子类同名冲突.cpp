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
		cout<<"������ó�Ա����"<<endl;
	}
	
	static void sfunc(){
		cout<<"������þ�̬��Ա����"<<endl;
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
		cout<<"������ó�Ա����"<<endl;
	}
	
	static void sfunc(){
		cout<<"������þ�̬��Ա����"<<endl;
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
	//ͨ��������ʸ����е�ͬ������ 
	cout<<b1.A::a<<endl;
	//ͨ��������ʸ����е�ͬ������ 
	b1.A::func();
	//ͨ��ʵ�������������ʸ����е�ͬ����̬���� 
	cout<<b1.A::b<<endl;
	// ͨ�����������ʸ����е�ͬ����̬����
	cout<<B1::A::b<<endl;
	return 0;
}
