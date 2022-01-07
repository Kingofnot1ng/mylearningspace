#include <iostream>
#include <string>

using namespace std;

//前置类声明 不能通过其访问类中具体的成员  详见https://blog.csdn.net/u012043391/article/details/104115888 
class Goodfirend;
class Building; 
class Anotherfriend{
public:
	Anotherfriend();
	void visit();
	string name;
	Building *building;
};
class Building{
//友元函数 可以访问类中的私有成员 
friend void myfirend(Building &b);
//友元类 
friend class Goodfirend;
//友元成员函数
friend void Anotherfriend::visit(); 
public:
	Building(){
		sittingroom="客厅";
		bedroom="卧室"; 
	}
	string sittingroom;
private:
	string bedroom; 
};
//类做友元 
class Goodfirend{
public:
	Goodfirend();
	void visit(); 
	string name;
	Building *building;
};
//成员函数做友元 
 
//外部实现成员函数 
Goodfirend::Goodfirend(){
	name="张三";
	building=new Building(); 
}
void Goodfirend::visit(){
	cout<<"友元类正在访问"<<building->sittingroom<<endl;
	cout<<"友元类正在访问"<<building->bedroom<<endl;
}
Anotherfriend::Anotherfriend(){
		name="张三";
		building=new Building(); 
	}
void Anotherfriend::visit(){
		cout<<"成员函数正在访问"<<building->sittingroom<<endl;
		cout<<"成员函数正在访问"<<building->bedroom<<endl;
	}
void myfirend(Building &b);//全局函数做友元 

int main(){
	Building b1;
	myfirend(b1);
	Goodfirend f1;
	f1.visit();
	Anotherfriend f2;
	f2.visit(); 
	return 0;
} 
void myfirend(Building &b){
	cout<<"友元函数正在访问"<<b.sittingroom<<endl;
	cout<<"友元函数正在访问"<<b.bedroom<<endl;
}
