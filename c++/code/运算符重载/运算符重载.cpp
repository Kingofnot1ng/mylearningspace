#include <iostream>
#include <string>

using namespace std;

//���������ע��
//1.���ܶ��Ѿ��������������
//2.��Ҫ�������� 
class Numbers{
friend ostream & operator<< (ostream &cout,const Numbers &n);
public:
	int n1;
	int n2;
	
	Numbers(){
		this->n1=0;
		this->n2=0;
	}
	Numbers(int n1,int n2){
		this->n1=n1;
		this->n2=n2;
	}
	//��Ա��������+�� 
	Numbers operator+ (const Numbers &n){
		Numbers temp;
		temp.n1=this->n1+n.n1;
		temp.n2=this->n2+n.n2;
		return temp;
	}
	//����ǰ�õ��������
	Numbers & operator++ (){
		this->n1++;
		this->n2++;
		return *this;
	}
	//���ú��õ������� 
	Numbers operator++ (int){
		Numbers temp=*this; 
		this->n1++;
		this->n2++;
		return temp;
	}
	//�����ˣ�������� Ҳ�зº��� 
	void operator() (string test){
		cout<<test<<endl;
	}
	void showNumbers(){
		cout<<n1<<","<<n2<<endl;
	}
	
};

Numbers operator- (const Numbers &n1,const Numbers &n2);
ostream & operator<< (ostream &cout,const Numbers &n);
int main(){
	Numbers n1(1,1);
	Numbers n2(2,2);
	Numbers n3=n1+n2;//n3=n1.operator+(n2);
	n3.showNumbers();
	Numbers n4=n1-n2;//n3= operator-(n1,n2); 
	n4.showNumbers();
	cout<<n4<<endl;
	cout<<++n4<<endl;
	cout<<n4<<endl;
	cout<<n4++<<endl;
	cout<<n4<<endl;
	n4("test");
	return 0;
}
//ȫ�ֺ�������-�� 
Numbers operator- (const Numbers &n1,const Numbers &n2){
	Numbers temp;
		temp.n1=n1.n1-n2.n1;
		temp.n2=n1.n2-n2.n2;
		return temp;
}
//ȫ�ֺ���������������� 
ostream & operator<< (ostream &cout,const Numbers &n){
	cout<<n.n1<<","<<n.n2;
	return cout;
}
