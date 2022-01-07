/*
	һ������ļ�ʵ��
	2021/9/28 byҦ���� 
*/
#include <iostream>
#include <cstdio>
#include <string>

#define TYPE "����"
using namespace std;

//����Ԫ������ 
typedef int elementType;

//������ 
class LinkedList{
//����ڵ� 
struct Node
{
	elementType num;
	Node * next;
};
//������� 
friend ostream & operator<< (ostream &cout,LinkedList &l);
public:
	int length;
	//�������� 
	LinkedList(){
		head=new Node;
		head->num=0;
		head->next=NULL;
		length=0;
	}
    //��ȿ������캯�� 
	LinkedList(const LinkedList &l){
		head=new Node;
		head->num=0;
		head->next=NULL;
		length=0;
		for(int i=0;i<l.length;i++){
			this->push(this->location(l.head,i)->num);
		}
	}
	//�������� 
	~LinkedList(){
		Node * pn=head;
		while(pn->next){
			Node * next=pn->next;
			pn->next=NULL;
			delete pn;
			pn=next;
		}
		delete pn;
		pn=NULL;
	}
	//������� 
	LinkedList & clear(){
		if(length==0)return *this;
		Node * pn=head->next;
		while(pn->next){
			Node * next=pn->next;
			pn->next=NULL;
			delete pn;
			pn=next;
		}
		delete pn;
		pn=NULL;
		head->next=NULL;
		length=0;
		return *this;		
	}
	//������������ֵ
	LinkedList & insert(int index,elementType number){
		if(index>=0&&index<=length){
			Node * p=head;
			for(int i=0;i!=index;i++){
				p=p->next;
			} 
			Node * n=new Node;
			n->num=number;
			n->next=p->next;
			p->next=n;
			++length;
		} else{
			//����ֵ���Ϸ�			
		}
		return *this;
	}
	//push���� 
	LinkedList & push(elementType number){
		Node * p=head;
		while(p->next)p=p->next; 
		Node * n=new Node;
		n->num=number;
		n->next=NULL;
		p->next=n;
		++length;
		return *this;		
	}
	//��������ɾ��ָ���ڵ� 
	LinkedList &remove(const int index){
		if(index>=0&&index<length){
			Node * pn1=head;
			Node * pn2=head->next;
			for(int i=0;i!=index;i++){
				pn1=pn1->next;
				pn2=pn2->next;
			} 
			pn1->next=pn2->next;
			delete pn2;
			pn2=NULL;
			--length;
		} else{
			//����ֵ���Ϸ�			
		}
		return *this;
	} 
	//�������� 
	LinkedList &traverse(void (*visit)(elementType &)){
		LinkedList &l=*this;
		for(int i=0;i<length;i++){
			visit(l.location(l.head,i)->num);
		}
		return l; 
	}
	//��������cmp��������ֵΪtrue,��ǰԪ��������ð���г��� 	
	LinkedList &sort(bool (*cmp)(elementType ,elementType)){
		LinkedList &l=*this;
		for(int i=0;i<l.length-1;i++){
			Node *p=head->next;
			for(int j=0;j<l.length-1;j++){
				if(cmp(p->num,p->next->num)){
					elementType num=p->num;
					p->num=p->next->num;
					p->next->num=num;
				} 
				p=p->next;
			}
		}
		return l; 
	}
	//�жϷǿ� 
	bool isEmpty(){
		return length?false:true;
	}	
	//���� [] ����ͨ��������������Ԫ�� 
	elementType & operator[] (const int index){
		if(index>=0&&index<length){
			Node * pn=head;
			for(int i=-1;i!=index;i++){
				pn=pn->next;
			}
			return (elementType &)pn->num; 
		} else{
			//����ֵ���Ϸ��������ڱ��ڵ��num		 
			return (elementType &)head->num; 
		}
	}
	//���� () ����ͨ��������������Ԫ�صĵ�ַ
	const Node * operator() (const int index){
		if(index>=0&&index<length){
			Node * pn=head;
			for(int i=-1;i!=index;i++){
				pn=pn->next;
			}
			return pn; 
		} else{
			//����ֵ���Ϸ�������NULL		 
			return (const Node *)NULL; 
		}
	}
	//���� + ʵ�ֲ��� 
	LinkedList operator+(LinkedList &l1){
		LinkedList result;		
		LinkedList &l2=*this;
		for(int i=0;i<l1.length;i++){
			
			result.push(l1.location(l1.head,i)->num);
		}
		for(int i=0;i<l2.length;i++){	
			result.push(l2.location(l2.head,i)->num);
		}
		return result;
	}
	//���صȺ�ʵ�����¸�ֵ 
	LinkedList & operator=(const LinkedList &l1){
		this->clear();
		for(int i=0;i<l1.length;i++){
			Node * pn=l1.head;
			for(int j=-1;j!=i;j++){
				pn=pn->next;
			}
			this->push(pn->num);
		}
		return *this;
	}
	void test(){
		cout<<"test"<<endl;
	}
protected:
	Node * head;
	Node * location(Node * pn,int index){
		Node * pi=(pn==head)?pn->next:pn; 
		for(int i=0;i!=index;i++){
			pi=pi->next;			
		}
		return pi; 
	} 
};


//������� 
ostream & operator<< (ostream &cout,LinkedList &l);
//cmp���� 
bool cmpElement(elementType x,elementType y);
//�������� 
void visit(elementType &num);
int main(){
	LinkedList l1,l2,l3;
	for(int i=0;i<5;i++){
		l1.push(i);
	}
	l2=l1;	
	cout<<"��ֵ��\n"<<l1; 
	l1.insert(2,999);
	cout<<"����:\n"<<l1;
	cout<<"l[1]="<<l1[1]<<","<<"&l[1]="<<l1(1)<<endl;
	l1.remove(4);
	cout<<"ɾ��:\n"<<l1;
	l1.sort(cmpElement);
	cout<<"����:\n"<<l1;
	l1.traverse(visit);
	cout<<"����:\n"<<l1;
	l3=l2+l1;
	l1.clear();
	cout<<"���:\n"<<l1;
	cout<<"����:\n"<<l3.sort(cmpElement);
	l3.test(); 
	return 0;
}

ostream & operator<< (ostream &cout,LinkedList &l){
	if(l.length==0){
		printf("+------------------------+\n");
		printf("|empty!                  |\n");
		printf("+------------------------+\n");
	}else{
		printf("+-----+--------+---------+\n");
		printf("|index|number  |pointer  |\n");
		printf("+-----+--------+---------+\n");
		for(int i=0;i<l.length;i++){
			printf("|%-4d |%-7d |0x%x |\n",i,l[i],l(i));
			printf("+-----+--------+---------+\n");
		}
	}
	return cout;
}
bool cmpElement(elementType x,elementType y){
	return x>=y?true:false;
}
void visit(elementType &num){
	++num;
}
