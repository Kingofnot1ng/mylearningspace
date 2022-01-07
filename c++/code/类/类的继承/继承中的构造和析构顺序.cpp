#include <iostream>

using namespace std;

class A{
public:
	A(){
		cout<<"父类构造函数被调用"<<endl;
	}
	~A(){
		cout<<"父类析构函数被调用"<<endl;
	}
};
class B1:public A{
public:	
	B1(){
		cout<<"子类1构造函数被调用"<<endl;
	}
	~B1(){
		cout<<"子类1析构函数被调用"<<endl;
	}
};
class B2:protected A{
public:	
	B2(){
		cout<<"子类2构造函数被调用"<<endl;
	}
	~B2(){
		cout<<"子类2析构函数被调用"<<endl;
	}
};
class B3:private A{
public:	
	B3(){
		cout<<"子类3构造函数被调用"<<endl;
	}
	~B3(){
		cout<<"子类3析构函数被调用"<<endl;
	}
};
class C3:public B3{
public:
	C3(){
		cout<<"子类3的子类构造函数被调用"<<endl;
	}
	~C3(){
		cout<<"子类3的子类析构函数被调用"<<endl;
	} 
}; 
int main(){
	//先构造父类在构造子类
	//先析构子类在析构父类 
	A a1;
	B1 b1;
	B2 b2;
	B3 b3;
//	C3 c3; 
	return 0;
}
