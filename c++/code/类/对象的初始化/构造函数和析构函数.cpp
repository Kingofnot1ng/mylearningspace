#include <iostream>
#include <string>

using namespace std;

class Dormitory{
public:
	//���캯�� 
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
		cout<<"����ţ�"<<id<<" ��"<<balance<<endl; 
	}
private:
	int id;
	double balance;
};
int main(){
	//�޲ι��� 
	Dormitory d1;
	d1.showDormitory();
	//�вι��� 
	Dormitory d2(627,100.0);
	d2.showDormitory();
	//���캯������ 
	Dormitory d3(123);
	d3.showDormitory();
	//�������� 
	Dormitory d4(d2);
	d4.showDormitory();
	//��ʽ����(�ȴ���һ����������Ȼ����������ȡ����)
	Dormitory d5=Dormitory(101,99.8);
	d5.showDormitory();
	Dormitory d6=Dormitory(d5);
	d6.showDormitory();
	//��ʽ����
	Dormitory d7=d5;
	d7.showDormitory();
	Dormitory d8=102;
	d8.showDormitory();
	return 0;
}
