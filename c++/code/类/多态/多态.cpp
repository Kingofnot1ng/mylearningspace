#include <iostream>

using namespace std;

class animal{
public:
	//�麯�� 
	virtual void speak(){
		cout<<"�����"<<endl;
	}
};
class cat:public animal{
public:
	void speak(){
		cout<<"è��"<<endl;
	}
};
class dog:public animal{
public:
	void speak(){
		cout<<"����"<<endl;
	}
};
class littlecat:public cat{
public:
	void speak(){
		cout<<"Сè��"<<endl;
	}
};
class bigcat:public cat{
public:
	void speak(){
		cout<<"��è��"<<endl;
	}
}; 
//��ַ���
/*
	��̬��̬��������
	1.�м̳й�ϵ
	2.������д������麯��
	
	��̬��̬��ʹ��
	����ָ�������ָ��������� 
*/ 
void doSpeak(animal &a){
	a.speak();
} 
int main(){
	animal a1;
	doSpeak(a1);
	cat c1;
	//animal &a =c1 
	doSpeak(c1); 
	dog d1;
	doSpeak(d1);
	littlecat lc1;
	doSpeak(lc1);
	bigcat bc1;
	doSpeak(bc1);  
	return 0;
}



