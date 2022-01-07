//数组容器
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



class Person{
public:
	string name;
	int age;
	Person(){
		name="";
		age=0;
	}
	Person(string name,int age):name(name),age(age){		
	}
};

void myPrintf(int n){
	cout<<n<<endl;
}
void myPrintf_P(const Person &p){
	cout<<p.name<<p.age<<endl;
}
int main(){
	vector<int> v1;
	//插入数据
	for(int i=0;i<5;i++){
		v1.push_back(i);
	}
	//访问数据
//	vector<int>::iterator itBegin=v1.begin();//起始迭代器，指向第一个元素的位置  
//	vector<int>::iterator itEnd=v1.end();//结束迭代器，指向最后一个元素的下一个位置
//	
//	while(itBegin!=itEnd){
//		cout<<*itBegin++<<endl;
//	} 

//	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
//		cout<<*it<<endl;
//	}
	for_each(v1.begin(),v1.end(),myPrintf);
	
	vector<Person> v2;
	Person p1("a",10);
	Person p2("b",20);
	Person p3("c",30);
	Person p4("d",40);
	Person p5("e",50);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	for_each(v2.begin(),v2.end(),myPrintf_P);	
	return 0;
} 
