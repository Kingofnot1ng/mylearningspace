#include <iostream>
/*
	����ָ����delete�� ����ָ���ڴ�ռ��ͷ� �������ݲ�һ���ı䣨����Ϊdelete����ֻ�����ǿ���������ڴ�Ķ�дȨ�ޣ��ڴ��е����ݲ�һ���ı䣩  
	��ʱ���ָ���Ǹ�Ұָ�� ��Ȼ�ܹ���->���ʲ��Ϸ����ڴ� Ҫע����һ�� 
*/
using namespace std;

struct node{
	int a;
	node * next;
};
int main(){
	node * p1=new node;
	p1->a=0;
	p1->next=new node;
	node *p2=p1->next;
	p2->a=1;
	p2->next=new node;
	node *p3=p2->next;
	p3->a=2;
	p3->next=new node;
	node *p4=p3->next;
	p4->a=3;
	p4->next=NULL;
	cout<<p1->a<<","<<p2->a<<","<<p3->a<<","<<p4->a<<endl;
	cout<<p1<<","<<p2<<","<<p3<<","<<p4<<endl;
	cout<<"         "<<p1->next<<","<<p2->next<<","<<p3->next<<","<<p4->next<<endl;
	
	
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	cout<<p1->a<<","<<p2->a<<","<<p3->a<<","<<p4->a<<endl;
	cout<<p1<<","<<p2<<","<<p3<<","<<p4<<endl;
	cout<<"         "<<p1->next<<","<<p2->next<<","<<p3->next<<","<<p4->next<<endl;
	cout<<"���Կ�������ʹdelete��������ָ������ڴ��е�����"<<endl;		
	return 0;
}
