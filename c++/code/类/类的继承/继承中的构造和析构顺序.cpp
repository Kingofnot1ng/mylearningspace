#include <iostream>

using namespace std;

class A{
public:
	A(){
		cout<<"���๹�캯��������"<<endl;
	}
	~A(){
		cout<<"������������������"<<endl;
	}
};
class B1:public A{
public:	
	B1(){
		cout<<"����1���캯��������"<<endl;
	}
	~B1(){
		cout<<"����1��������������"<<endl;
	}
};
class B2:protected A{
public:	
	B2(){
		cout<<"����2���캯��������"<<endl;
	}
	~B2(){
		cout<<"����2��������������"<<endl;
	}
};
class B3:private A{
public:	
	B3(){
		cout<<"����3���캯��������"<<endl;
	}
	~B3(){
		cout<<"����3��������������"<<endl;
	}
};
class C3:public B3{
public:
	C3(){
		cout<<"����3�����๹�캯��������"<<endl;
	}
	~C3(){
		cout<<"����3��������������������"<<endl;
	} 
}; 
int main(){
	//�ȹ��츸���ڹ�������
	//�������������������� 
	A a1;
	B1 b1;
	B2 b2;
	B3 b3;
//	C3 c3; 
	return 0;
}
