#include <iostream>
#include <string>
using namespace std;

/*
	���ַ���Ȩ��
	1.public	���ڿɷ��ʣ�����Ҳ�ɷ��ʣ�ͨ�� . -> ��������ʣ� 
	2.protected   ���ڿɷ��ʣ����ⲻ���Է��� 
	3.private 	���ڿɷ��ʣ����ⲻ���Է���
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
		cout<<"����:"<<name<<" ��:"<<car<<" ����:"<<password<<endl;
	}
protected:
	string car;
private:
	string password;
}; 
int main(){
	Person p1;
	p1.name="����";
	p1.setCar("����");//����<p1.car="����">���ֱ�������
	p1.setPassword("123456");
	p1.showPerson();
	return 0;
}
