#include <iostream>
#include <string>

using namespace std;

enum sex{
	female,
	man,	
};
class Student{
public:
	Student(string name,int id,int age,sex s):name(name),id(id),age(age),s(s){
	}
//	//常函数中不能修改对象的值 报错 
//	void plusAge() const{
//		age++;
//	}
	void plusAge() {
		age++;
	}
	void changeSex() const{
		if(s==female){
			s=man;
		}else{
			s=female;
		}
	} 
	void showStudent() const{
		string sex=(s==man)?"男":"女";
		cout<<"姓名："<<name<<" 学号："<<id<<" 年龄："<<age<<" 性别："<<sex<<endl; 
	}
	string name;
protected:
	int id;
	int age;
	//加了mutable修饰，即使在常函数中，也可以修改这个值 
	mutable sex s;
};
int main(){
	Student s1("姚家乐",2025050374,19,man);
	s1.showStudent();
//常函数演示 
//	s1.plusAge();
	s1.changeSex();
	s1.showStudent();
//常对象只能调用常函数
	const Student s2(s1);
//	s2.name="233"; //不能修改值 
//	s2.plusAge(); //调用失败 
	s2.showStudent();
	return 0;
}
