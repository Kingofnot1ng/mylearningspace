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
//	//�������в����޸Ķ����ֵ ���� 
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
		string sex=(s==man)?"��":"Ů";
		cout<<"������"<<name<<" ѧ�ţ�"<<id<<" ���䣺"<<age<<" �Ա�"<<sex<<endl; 
	}
	string name;
protected:
	int id;
	int age;
	//����mutable���Σ���ʹ�ڳ������У�Ҳ�����޸����ֵ 
	mutable sex s;
};
int main(){
	Student s1("Ҧ����",2025050374,19,man);
	s1.showStudent();
//��������ʾ 
//	s1.plusAge();
	s1.changeSex();
	s1.showStudent();
//������ֻ�ܵ��ó�����
	const Student s2(s1);
//	s2.name="233"; //�����޸�ֵ 
//	s2.plusAge(); //����ʧ�� 
	s2.showStudent();
	return 0;
}
