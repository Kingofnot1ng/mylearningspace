#include <iostream>

using namespace std;

//����ģ�嶯̬��̬ 
template <typename T>
T add(const T &a,const T &b){
	return a+b;
}
template <typename T>
void test(){
	cout<<"test"<<endl; 
}
int main(){
	int i1=1,i2=2,i3;
//	//�Զ��Ƶ� 
//	i3=add(i1,i2);
	//��ʽָ������ 
	i3=add<int>(i1,i2);
	cout<<i3<<endl;
	//��̬ 
	double d1=0.1,d2=0.2,d3;
	d3=add<double>(d1,d2);
	cout<<d3<<endl;
	//ģ�����ȷ��T�����Ͳ���ʹ�� 
	//�Ƿ����� 
//	test();
	//�Ϸ�����   
	test<int>(); 
	return 0;
}
