#include <iostream>

using namespace std;

void func1(int &n1,int &n2);//引用做参数 
int& func2();//引用做返回值 
int main(){
	/*
		引用使用的注意事项
		1.引用必须初始化
		2.引用一旦绑定了某块内存就不可更改，无法再指向其他内存 
		3.引用本质是一个指针常量 
	*/
	int a=10;
	int &b=a;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	b=20;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	
	int c=1;
	int d=0;
	/*
		这里需要注意 &c不是c的引用，而是c的地址，类型为int* 
	*/ 
	int &andc=c;
	int &andd=d;
	cout<<"c="<<c<<endl;
	cout<<"d="<<d<<endl;
	func1(c,d);
	cout<<"c="<<c<<endl;
	cout<<"d="<<d<<endl;
	
	int &e=func2();
	cout<<"e="<<e<<endl;
	func2()=1000;
	cout<<"e="<<e<<endl;
	
	//常量引用
	const int & ref=10;
	cout<<"ref="<<ref<<endl; 
	return 0;
}

void func1(int &n1,int &n2){
	int temp=n1;
	n1=n2;
	n2=temp; 
	return;
}

int& func2(){
	static int a=100;
	return a;
} 
