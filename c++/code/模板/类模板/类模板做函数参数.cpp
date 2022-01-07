#include <iostream>
#include <typeinfo>

using namespace std;


template<class NameType,class AgeType=int>
class Person{
public:
	NameType name;
	AgeType age; 
	Person(NameType name,AgeType age){
		this->name=name;
		this->age=age;
	}
};

//普通类继承类模板 
class test1:public Person<string>{
public:
	test1(string name,int age):Person(name,age)
	{	
	}
	test1(string name,int age,int tall):Person(name,age)
	{	
		this->tall=tall;
	}
	int tall;
};
//类模板继承类模板 
template<class T1,class T2,class T3>
class test2:public Person<T1,T2>{
public:
	test2(T1 name,T2 age):Person<T1,T2>(name,age)
	{	
	}
	test2(T1 name,T2 age,T3 tall):Person<T1,T2>(name,age)
	{	
		this->tall=tall;
	}
	T3 tall;
};
//指定传入类型 
void printfPerson1(Person<string> &p){
	cout<<p.name<<p.age<<endl;
}
//参数模板化 
template<class T1,class T2>
void printfPerson2(Person<T1,T2> &p){
	cout<<p.name<<p.age<<endl;
	cout<<"传入的模板类型:"<<endl;
	//typeid()头文件 #include <typeinfo>
	cout<<typeid(T1).name()<<endl;
	cout<<typeid(T2).name()<<endl;
}
//整个类模板化 
template<class T>
void printfPerson3(T &p){
	cout<<p.name<<p.age<<endl;
	cout<<"传入的模板类型:"<<endl;
	cout<<typeid(T).name()<<endl;
}
int main(){
	Person<string> p1("tom",18);
	printfPerson1(p1);
	Person<string,string> p2("jerry","20");
	printfPerson2(p2);
	Person<string,int> p3("bob",35);
	printfPerson2(p3);
	Person<string> p4("jim",41);
	printfPerson3(p4);
	Person<string,string> p5("smith","99");
	printfPerson3(p5);
	test1 t1("smith",99,180);
	cout<<t1.name<<t1.age<<t1.tall<<endl;
	test2<string,string,string> t2("smith","99","180");
	cout<<t2.name<<t2.age<<t2.tall<<endl;
	return 0;
}
