#include <iostream>
/*
	对象指针在delete后 其所指的内存空间释放 但是内容不一定改变（我认为delete操作只不过是开放了这块内存的读写权限，内存中的内容不一定改变）  
	这时这个指针是个野指针 仍然能够用->访问不合法的内存 要注意这一点 
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
	cout<<"可以看到，即使delete后，仍能用指针访问内存中的数据"<<endl;		
	return 0;
}
