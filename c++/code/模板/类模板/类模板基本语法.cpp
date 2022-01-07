#include <iostream>

using namespace std;

//默认参数 
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
int main(){
	//必须要有参数列表 
	Person<string> p1("tom",18);
	cout<<p1.name<<p1.age<<endl;
	Person<int> p2(374,18);
	cout<<p2.name<<p2.age<<endl;
	return 0;
}
