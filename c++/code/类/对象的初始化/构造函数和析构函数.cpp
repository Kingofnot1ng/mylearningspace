#include <iostream>
#include <string>

using namespace std;

class Dormitory{
public:
	//构造函数 
	Dormitory(const Dormitory &p){
		id=p.id;
		balance=p.balance;
	}
	Dormitory(int id,double balance){
		this->id=id;
		this->balance=balance;
	}
	Dormitory(int id){
		this->id=id;
		this->balance=0;
	}
	Dormitory(){
		this->id=0;
		this->balance=0;
	}
	
	~Dormitory(){
		
	}
	
	int getId(){
		return id;
	}
	void setBalance(double balance){
		this->balance=balance;
	}
	double getBalance(){
		return balance;
	}
	
	void showDormitory(){
		cout<<"宿舍号："<<id<<" 余额："<<balance<<endl; 
	}
private:
	int id;
	double balance;
};
int main(){
	//无参构造 
	Dormitory d1;
	d1.showDormitory();
	//有参构造 
	Dormitory d2(627,100.0);
	d2.showDormitory();
	//构造函数重载 
	Dormitory d3(123);
	d3.showDormitory();
	//拷贝构造 
	Dormitory d4(d2);
	d4.showDormitory();
	//显式构造(先创建一个匿名对象，然后给这个对象取名字)
	Dormitory d5=Dormitory(101,99.8);
	d5.showDormitory();
	Dormitory d6=Dormitory(d5);
	d6.showDormitory();
	//隐式构造
	Dormitory d7=d5;
	d7.showDormitory();
	Dormitory d8=102;
	d8.showDormitory();
	return 0;
}
