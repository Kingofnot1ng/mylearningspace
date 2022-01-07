#include <iostream>

using namespace std;

class A{
public:
	int a;
protected:
	int b;
private:
	int c;
};
class B1:public A{
//等价于下列代码  
/*
public:
	int a;
protected:
	int b;
不可访问:
	int c; 
*/ 
}; 
class B2:protected A{
//等价于下列代码  
/*	
protected:
	int a;
	int b;
不可访问:
	int c;
*/ 
};
class B3:private A{
//等价于下列代码  
/*
private:
	int a;
	int b;
不可访问:
	int c;
*/ 
};
int main(){	
	return 0;
}
