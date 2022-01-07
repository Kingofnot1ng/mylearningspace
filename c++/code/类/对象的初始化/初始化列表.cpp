#include <iostream>

using namespace std;

class Person{
public:
	//初始化列表 
	Person():name("无"),age(0)
	{
	}
	//初始化列表 
	Person(string name,int age):name(name),age(age){	
	}
	~Person(){			
	}
	void showPerson(){
		cout<<"名字："<<name<<" 年龄："<<age<<endl;
	}
protected:
	string name;
	int age; 
};
int main(){
	
	Person p1("姚家乐",19);
	p1.showPerson();
	Person p2(p1);
	p2.showPerson();
	//堆区创建对象 
	Person *p3=new Person("yjl",20);
	p3->showPerson();
	Person *p4=new Person(*p3);
	p4->showPerson();
	cout<<"p1:"<<&p1<<" p2:"<<&p2<<endl;
	cout<<"p3:"<<p3<<" p4:"<<p4<<endl;
	
	delete p3;
	p3=NULL;
	delete p4;
	p4=NULL;
	
	Person p5;
	p5.showPerson();
	return 0;
}
