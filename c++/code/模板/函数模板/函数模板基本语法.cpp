#include <iostream>

using namespace std;

//函数模板动态多态 
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
//	//自动推导 
//	i3=add(i1,i2);
	//显式指定类型 
	i3=add<int>(i1,i2);
	cout<<i3<<endl;
	//多态 
	double d1=0.1,d2=0.2,d3;
	d3=add<double>(d1,d2);
	cout<<d3<<endl;
	//模板必须确定T的类型才能使用 
	//非法调用 
//	test();
	//合法调用   
	test<int>(); 
	return 0;
}
