#include <iostream>
#include <string>

using namespace std;

class Circle{
	public:
		double r;
		static const double PI=3.1416;
		double calculateZC(){
			return 2*PI*r;
		}
};

class Student{
public:
	string name;
	string id;
	void showStudent(){
		cout<<"姓名："<<name<<" 学号："<<id<<endl;
	}
	void setName(string name){
		this->name=name;
	}
	void setId(string id){
		this->id=id;
	}
};

int main(){
	Circle c1;
	c1.r=5.0;
	cout<<"圆的周长为"<<c1.calculateZC()<<endl;
	
	Student s1;
	s1.name="yjl";
	s1.id="2025050374";
	s1.showStudent();
	s1.setName("nobody");
	s1.setId("2025050000");
	s1.showStudent();
	return 0;
}
