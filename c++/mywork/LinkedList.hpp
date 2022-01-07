/*
	һ������ļ�ʵ��
	2021/9/28 byҦ���� 
*/
#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>

using namespace std;


//Ҫ�洢������T��element������� =��ֵ����,��ȿ������캯�� 
template <class T>
class LinkedList{
struct Node
{
	T element;
	Node * next;
};
public:

	//�������� 
	LinkedList(){
		head=new Node;
		T e;
		head->element=e;
		head->next=NULL;
		length=0;
	}
    //��ȿ������캯�� 
	LinkedList(const LinkedList &l){
		head=new Node;
		T e;
		head->element=e;
		head->next=NULL;
		length=0;
		for(int i=0;i<l.length;i++){
			this->push(this->location(l.head,i)->element);
		}
	}
	//�������� 
	virtual ~LinkedList(){
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
	LinkedList & insert(int index,T element){
		if(index>=0&&index<=length){
			Node * p=this->location(head,index-1);
			Node * n=new Node;
			n->element=element;
			n->next=p->next;
			p->next=n;
			++length;
		}else{
			throw "�Ƿ�����ֵ"; 
		} 
		return *this;
	}
	//push���� 
	virtual LinkedList & push(T element){
		Node * p=head;
		while(p->next)p=p->next; 
		Node * n=new Node;
		n->element=element;
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
			throw "�Ƿ�����ֵ"; 			
		}
		return *this;
	} 
	//�������� 
	LinkedList &traverse(void (*visit)(T &)){
		for(int i=0;i<length;i++){
			visit(this->location(head,i)->element);
		}
		return *this; 
	}
	
	//�жϷǿ� 
	bool isEmpty(){
		return length?false:true;
	}
	int getlength(){
		return length;
	}	
	//���� [] ����ͨ��������������Ԫ�� 
	T & operator[] (const int index){
		if(index>=0&&index<length){
			return (T &)this->location(head,index)->element; 
		} else{
			throw "�Ƿ�����ֵ"; 		 
			return (T &)head->element; 
		}
	}
	//���� () ����ͨ��������������Ԫ�صĵ�ַ
	const Node * operator() (const int index){
		if(index>=0&&index<length){
			return this->location(head,index); 
		} else{
			throw "�Ƿ�����ֵ"; 		 
			return (const Node *)head; 
		}
	}
	
	//���صȺ�ʵ�����¸�ֵ 
	LinkedList & operator=(const LinkedList &l1){
		this->clear();
		for(int i=0;i<l1.length;i++){
			this->push(this->location(l1.head,i)->element);
		}
		return *this;
	}
protected:
	int length;
	Node * head;
	Node * location(Node * pn,int index){
		Node * pi=pn; 
		for(int i=-1;i!=index;i++){
			pi=pi->next;			
		}
		return pi; 
	} 
};

template<class T>
class LinkedListWithOutStream:public LinkedList<T>
{
friend ostream & operator<< (ostream &cout,LinkedListWithOutStream &l){
	if(l.length==0){
		printf("+------------------------+\n");
		printf("|empty!                  |\n");
		printf("+------------------------+\n");
	}else{
		printf("+-----+-------------+---------+\n");
		printf("|index|element      |pointer  |\n");
		printf("+-----+-------------+---------+\n");
		for(int i=0;i<l.length;i++){
			cout <<"|"<<left<<setw(5)<<i<<"|"<<left<<setw(13)<<l[i]<<"|"<<left<<setw(9)<<l(i)<<"|"<< endl;
			printf("+-----+-------------+---------+\n");
		}
	}
	return cout;
}
};


template<class T>
class LinkedListOfNumber:public LinkedList<T>
{

friend ostream & operator<< (ostream &cout,LinkedListOfNumber &l){
	if(l.length==0){
		printf("+------------------------+\n");
		printf("|empty!                  |\n");
		printf("+------------------------+\n");
	}else{
		printf("+-----+--------+---------+\n");
		printf("|index|number  |pointer  |\n");
		printf("+-----+--------+---------+\n");
		for(int i=0;i<l.length;i++){
			cout <<"|"<<left<<setw(5)<<i<<"|"<<left<<setw(8)<<l[i]<<"|"<<left<<setw(9)<<l(i)<<"|"<< endl;
			printf("+-----+--------+---------+\n");
		}
	}
	return cout;
};
public:
//	��������cmp��������ֵΪtrue,��ǰԪ��������ð���г��� 	
	LinkedListOfNumber &sort(bool (*cmp)(T ,T)){
		LinkedListOfNumber &l=*this;
		for(int i=0;i<l.length-1;i++){
		 	LinkedList<int>::Node *p=l.head->next;
			for(int j=0;j<l.length-1;j++){
				if(cmp(p->element,p->next->element)){
					T element=p->element;
					p->element=p->next->element;
					p->next->element=element;
				} 
				p=p->next;
			}
		}
		return l; 
	}
//ƴ�� 
	LinkedListOfNumber operator+(const LinkedListOfNumber &l1){
		LinkedListOfNumber result;
		LinkedListOfNumber &l2=*this;
		for(int i=0;i<l1.length;i++){			
			result.push(result.location(l1.head,i)->element);
		}
		for(int i=0;i<l2.length;i++){			
			result.push(result.location(l2.head,i)->element);
		}
		return result;
	}
};










