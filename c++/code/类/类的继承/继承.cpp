#include <iostream>

using namespace std;

//���࣬���� 
class father{
public:
	void line(){
		cout<<"+--------------------+"<<endl;
	}
};
//���࣬������ 
class son1:public father{
public:
	void content(){
		cout<<"|     ���Ǵ����     |"<<endl;
	}
};
class son2:public father{
public:
	void content(){
		cout<<"|     ���Ƕ�����     |"<<endl;
	}
};
int main(){
	father f1;
	f1.line();
	cout<<"|     ���Ǹ���       |"<<endl;
	f1.line();
	son1 s1;
	s1.line();
	s1.content();
	s1.line();
	son2 s2;
	s2.line();
	s2.content();
	s2.line();
	return 0;
}
