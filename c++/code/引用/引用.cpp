#include <iostream>

using namespace std;

void func1(int &n1,int &n2);//���������� 
int& func2();//����������ֵ 
int main(){
	/*
		����ʹ�õ�ע������
		1.���ñ����ʼ��
		2.����һ������ĳ���ڴ�Ͳ��ɸ��ģ��޷���ָ�������ڴ� 
		3.���ñ�����һ��ָ�볣�� 
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
		������Ҫע�� &c����c�����ã�����c�ĵ�ַ������Ϊint* 
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
	
	//��������
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
