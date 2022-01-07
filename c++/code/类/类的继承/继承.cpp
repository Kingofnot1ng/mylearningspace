#include <iostream>

using namespace std;

//父类，基类 
class father{
public:
	void line(){
		cout<<"+--------------------+"<<endl;
	}
};
//子类，派生类 
class son1:public father{
public:
	void content(){
		cout<<"|     我是大儿子     |"<<endl;
	}
};
class son2:public father{
public:
	void content(){
		cout<<"|     我是二儿子     |"<<endl;
	}
};
int main(){
	father f1;
	f1.line();
	cout<<"|     我是父亲       |"<<endl;
	f1.line();
	son1 s1;
	s1.line();
	s1.content();
	s1.line();
	son2 s2;
	s2.line();
	s2.content();
	s2.line();
	return 0;
}
