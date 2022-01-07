#include <iostream>
#include <string>
using namespace std;

/*
	三种访问权限
	1.public	类内可访问，类外也可访问（通过 . -> 运算符访问） 
	2.protected   类内可访问，内外不可以访问 
	3.private 	类内可访问，内外不可以访问
*/

class Person{
public:
	string name;
	void setName(string name){
		this->name=name;
	}
	void setCar(string car){
		this->car=car;
	}
	void setPassword(string password){
		this->password=password;
	}
	void showPerson(){
		cout<<"姓名:"<<name<<" 车:"<<car<<" 密码:"<<password<<endl;
	}
protected:
	string car;
private:
	string password;
}; 
int main(){
	Person p1;
	p1.name="张三";
	p1.setCar("宝马");//类似<p1.car="宝马">这种表述错误
	p1.setPassword("123456");
	p1.showPerson();
	return 0;
}
