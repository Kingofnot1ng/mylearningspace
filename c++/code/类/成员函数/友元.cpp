#include <iostream>
#include <string>

using namespace std;

//ǰ�������� ����ͨ����������о���ĳ�Ա  ���https://blog.csdn.net/u012043391/article/details/104115888 
class Goodfirend;
class Building; 
class Anotherfriend{
public:
	Anotherfriend();
	void visit();
	string name;
	Building *building;
};
class Building{
//��Ԫ���� ���Է������е�˽�г�Ա 
friend void myfirend(Building &b);
//��Ԫ�� 
friend class Goodfirend;
//��Ԫ��Ա����
friend void Anotherfriend::visit(); 
public:
	Building(){
		sittingroom="����";
		bedroom="����"; 
	}
	string sittingroom;
private:
	string bedroom; 
};
//������Ԫ 
class Goodfirend{
public:
	Goodfirend();
	void visit(); 
	string name;
	Building *building;
};
//��Ա��������Ԫ 
 
//�ⲿʵ�ֳ�Ա���� 
Goodfirend::Goodfirend(){
	name="����";
	building=new Building(); 
}
void Goodfirend::visit(){
	cout<<"��Ԫ�����ڷ���"<<building->sittingroom<<endl;
	cout<<"��Ԫ�����ڷ���"<<building->bedroom<<endl;
}
Anotherfriend::Anotherfriend(){
		name="����";
		building=new Building(); 
	}
void Anotherfriend::visit(){
		cout<<"��Ա�������ڷ���"<<building->sittingroom<<endl;
		cout<<"��Ա�������ڷ���"<<building->bedroom<<endl;
	}
void myfirend(Building &b);//ȫ�ֺ�������Ԫ 

int main(){
	Building b1;
	myfirend(b1);
	Goodfirend f1;
	f1.visit();
	Anotherfriend f2;
	f2.visit(); 
	return 0;
} 
void myfirend(Building &b){
	cout<<"��Ԫ�������ڷ���"<<b.sittingroom<<endl;
	cout<<"��Ԫ�������ڷ���"<<b.bedroom<<endl;
}
