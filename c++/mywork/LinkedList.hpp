/*
	一个链表的简单实现
	2021/9/28 by姚家乐 
*/
#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>

using namespace std;

/*
	要存储的类型T的element必须具有 
	1.=赋值运算 特别是=0； 
	2.<<输出
	3.>< 大小比较 
*/
//template <class T>
//class LinkedList{
////定义节点 
//struct Node
//{
//	T num;
//	Node * next;
//};
////输出重载 
//friend ostream & operator<< (ostream &cout,LinkedList &l){
//	if(l.length==0){
//		printf("+------------------------+\n");
//		printf("|empty!                  |\n");
//		printf("+------------------------+\n");
//	}else{
//		printf("+-----+--------+---------+\n");
//		printf("|index|number  |pointer  |\n");
//		printf("+-----+--------+---------+\n");
//		for(int i=0;i<l.length;i++){
//			cout <<"|"<<left<<setw(5)<<i<<"|"<<left<<setw(8)<<l[i]<<"|"<<left<<setw(9)<<l(i)<<"|"<< endl;
//			printf("+-----+--------+---------+\n");
//		}
//	}
//	return cout;
//}
//public:
//	//构造链表 
//	LinkedList(){
//		head=new Node;
////		head->num=0;
//		head->next=NULL;
//		length=0;
//	}
//    //深度拷贝构造函数 
//	LinkedList(const LinkedList &l){
//		head=new Node;
////		head->num=0;
//		head->next=NULL;
//		length=0;
//		for(int i=0;i<l.length;i++){
//			this->push(this->location(l.head,i)->num);
//		}
//	}
//	//销毁链表 
//	~LinkedList(){
//		Node * pn=head;
//		while(pn->next){
//			Node * next=pn->next;
//			pn->next=NULL;
//			delete pn;
//			pn=next;
//		}
//		delete pn;
//		pn=NULL;
//	}
//	//清空链表 
//	LinkedList & clear(){
//		if(length==0)return *this;
//		Node * pn=head->next;
//		while(pn->next){
//			Node * next=pn->next;
//			pn->next=NULL;
//			delete pn;
//			pn=next;
//		}
//		delete pn;
//		pn=NULL;
//		head->next=NULL;
//		length=0;
//		return *this;		
//	}
//	//依据索引插入值
//	LinkedList & insert(int index,T number){
//		if(index>=0&&index<=length){
//			Node * p=head;
//			for(int i=0;i!=index;i++){
//				p=p->next;
//			} 
//			Node * n=new Node;
//			n->num=number;
//			n->next=p->next;
//			p->next=n;
//			++length;
//		} else{
//			//索引值不合法			
//		}
//		return *this;
//	}
//	//push操作 
//	LinkedList & push(T number){
//		Node * p=head;
//		while(p->next)p=p->next; 
//		Node * n=new Node;
//		n->num=number;
//		n->next=NULL;
//		p->next=n;
//		++length;
//		return *this;		
//	}
//	//依据索引删除指定节点 
//	LinkedList &remove(const int index){
//		if(index>=0&&index<length){
//			Node * pn1=head;
//			Node * pn2=head->next;
//			for(int i=0;i!=index;i++){
//				pn1=pn1->next;
//				pn2=pn2->next;
//			} 
//			pn1->next=pn2->next;
//			delete pn2;
//			pn2=NULL;
//			--length;
//		} else{
//			//索引值不合法			
//		}
//		return *this;
//	} 
//	//遍历函数 
//	LinkedList &traverse(void (*visit)(T &)){
//		LinkedList &l=*this;
//		for(int i=0;i<length;i++){
//			visit(l.location(l.head,i)->num);
//		}
//		return l; 
//	}
//	//排序函数，cmp函数返回值为true,则当前元素在向下冒泡中沉底 	
//	LinkedList &sort(bool (*cmp)(T ,T)){
//		LinkedList &l=*this;
//		for(int i=0;i<l.length-1;i++){
//			Node *p=head->next;
//			for(int j=0;j<l.length-1;j++){
//				if(cmp(p->num,p->next->num)){
//					T num=p->num;
//					p->num=p->next->num;
//					p->next->num=num;
//				} 
//				p=p->next;
//			}
//		}
//		return l; 
//	}
//	//判断非空 
//	bool isEmpty(){
//		return length?false:true;
//	}
//	int getlength(){
//		return length;
//	}	
//	//重载 [] 可以通过索引访问链表元素 
//	T & operator[] (const int index){
//		if(index>=0&&index<length){
//			Node * pn=head;
//			for(int i=-1;i!=index;i++){
//				pn=pn->next;
//			}
//			return (T &)pn->num; 
//		} else{
//			//索引值不合法，返回哨兵节点的num		 
//			return (T &)head->num; 
//		}
//	}
//	//重载 () 可以通过索引访问链表元素的地址
//	const Node * operator() (const int index){
//		if(index>=0&&index<length){
//			Node * pn=head;
//			for(int i=-1;i!=index;i++){
//				pn=pn->next;
//			}
//			return pn; 
//		} else{
//			//索引值不合法，返回NULL		 
//			return (const Node *)NULL; 
//		}
//	}
//	//重载 + 实现拼接 
//	LinkedList operator+(LinkedList &l1){
//		LinkedList result;		
//		LinkedList &l2=*this;
//		for(int i=0;i<l2.length;i++){	
//			result.push(l2.location(l2.head,i)->num);
//		}
//		for(int i=0;i<l1.length;i++){
//			
//			result.push(l1.location(l1.head,i)->num);
//		}
//		return result;
//	}
//	//重载等号实现重新赋值 
//	LinkedList & operator=(const LinkedList &l1){
//		this->clear();
//		for(int i=0;i<l1.length;i++){
//			Node * pn=l1.head;
//			for(int j=-1;j!=i;j++){
//				pn=pn->next;
//			}
//			this->push(pn->num);
//		}
//		return *this;
//	}
//protected:
//	int length;
//	Node * head;
//	Node * location(Node * pn,int index){
//		Node * pi=(pn==head)?pn->next:pn; 
//		for(int i=0;i!=index;i++){
//			pi=pi->next;			
//		}
//		return pi; 
//	} 
//};


//要存储的类型T的element必须具有 =赋值运算,深度拷贝构造函数 
template <class T>
class LinkedList{


public:
struct Node
{
	T element;
	Node * next;
};
	//构造链表 
	LinkedList(){
		head=new Node;
		T e;
		head->element=e;
		head->next=NULL;
		length=0;
	}
    //深度拷贝构造函数 
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
	//销毁链表 
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
	//清空链表 
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
	//依据索引插入值
	LinkedList & insert(int index,T element){
		if(index>=0&&index<=length){
			Node * p=this->location(head,index-1);
			Node * n=new Node;
			n->element=element;
			n->next=p->next;
			p->next=n;
			++length;
		} else{
			//索引值不合法			
		}
		return *this;
	}
	//push操作 
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
	//依据索引删除指定节点 
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
			//索引值不合法			
		}
		return *this;
	} 
	//遍历函数 
	LinkedList &traverse(void (*visit)(T &)){
		for(int i=0;i<length;i++){
			visit(this->location(head,i)->element);
		}
		return *this; 
	}
	//判断非空 
	bool isEmpty(){
		return length?false:true;
	}
	int getlength(){
		return length;
	}	
	//重载 [] 可以通过索引访问链表元素 
	T & operator[] (const int index){
		if(index>=0&&index<length){
			return (T &)this->location(head,index)->element; 
		} else{
			//索引值不合法，返回哨兵节点的num		 
			return (T &)head->element; 
		}
	}
	//重载 () 可以通过索引访问链表元素的地址
	const Node * operator() (const int index){
		if(index>=0&&index<length){
			return this->location(head,index); 
		} else{
			//索引值不合法，返回head		 
			return (const Node *)head; 
		}
	}
	
	//重载 + 实现拼接 
	LinkedList operator+(LinkedList &l1){
		LinkedList result;		
		LinkedList &l2=*this;
		for(int i=0;i<l2.length;i++){	
			result.push(l2.location(l2.head,i)->element);
		}
		for(int i=0;i<l1.length;i++){			
			result.push(l1.location(l1.head,i)->element);
		}
		return result;
	}
	//重载等号实现重新赋值 
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









