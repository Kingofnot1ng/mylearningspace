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
//�ȼ������д���  
/*
public:
	int a;
protected:
	int b;
���ɷ���:
	int c; 
*/ 
}; 
class B2:protected A{
//�ȼ������д���  
/*	
protected:
	int a;
	int b;
���ɷ���:
	int c;
*/ 
};
class B3:private A{
//�ȼ������д���  
/*
private:
	int a;
	int b;
���ɷ���:
	int c;
*/ 
};
int main(){	
	return 0;
}
