#include <iostream>

using namespace std;

//�����ǳ���� 
class Phone{
public:
	Phone(){
		owner="��";
		brand="��";
		price=NULL;	
	}
	Phone(string owner,string brand,int price){
		this->owner=owner;
		this->brand=brand;
		this->price=new int(price);	
	}
//	//ǳ����,������Ĭ�Ͽ������캯�� 
//	Phone(const Phone &p){
//		this->owner=p.owner;
//		this->brand=p.brand;
//		//��������Ķ����е�priceָ��ԭ�������е��ڴ� 
//		this->price=p.price;	
//	}
	//���,���´Ӷ��������ڴ� 
	Phone(const Phone &p){
		this->owner=p.owner;
		this->brand=p.brand;
		this->price=new int(*p.price);	
	}
	//���������ͷŶ��������� 
	~Phone(){
		if(price!=NULL){
			delete price;
			price=NULL; 
		}	
	}
	void showPhone(){
		cout<<"Ʒ�ƣ�"<<brand<<" �۸�"<<*price<<" �����ߣ�"<<owner<<endl;
	}
protected:
	string owner;
	string brand;
	int *price; 
};
int main(){
	Phone p1("Ҧ����","realme",1999);
	p1.showPhone();
	Phone p2(p1);
	p2.showPhone(); 
	return 0;
}
