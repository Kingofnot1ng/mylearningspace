#include <iostream>

using namespace std;

class A{
public:
	int a;
protected:
	int b;
private:
	int c;//私有成员只是被隐藏了，但还是会继承下去 
};
class B1:public A{
public:
	int d;
};
class B2:protected A{
public:
	int d;
};
class B3:private A{
public:
	int d;
};
int main(){
	cout<<sizeof(B1)<<endl;
	cout<<sizeof(B2)<<endl; 
	cout<<sizeof(B3)<<endl;  
	return 0;
}
