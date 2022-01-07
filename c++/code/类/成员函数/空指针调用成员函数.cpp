#include <iostream>
#include <string>

using namespace std;

class Test{
public:
	void hello(){
		cout<<"Hello ";
		this->world();
	}
	void world(){
		cout<<"world!"<<endl;
	}
	static void nihao(){
		cout<<"你好!"<<endl;
	}	
};
int main(){
	Test::nihao();
	Test t1;
	t1.hello();
	//只要不涉及this指针使用，可以用NULL指针来访问成员函数  
	Test *p1=NULL;
	p1->world(); 
	return 0;
}
