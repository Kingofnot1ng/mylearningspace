/*
	一个链表的简单实现
	2021/9/28 by姚家乐 
*/
#include <iostream>
#include <cstdio>
#include <string>

#define TYPE "整数"
using namespace std;

//定义元素类型 
typedef int elementType;

//链表类 
class LinkedList{
//定义节点 
struct Node
{
	elementType num;
	Node * next;
};
//输出重载 
friend ostream & operator<< (ostream &cout,LinkedList &l);
public:
	int length;
	//构造链表 
	LinkedList(){
		head=new Node;
		head->num=0;
		head->next=NULL;
		length=0;
	}
    //深度拷贝构造函数 
	LinkedList(const LinkedList &l){
		head=new Node;
		head->num=0;
		head->next=NULL;
		length=0;
		for(int i=0;i<l.length;i++){
			this->push(this->location(l.head,i)->num);
		}
	}
	//销毁链表 
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
			//索引值不合法			
		}
		return *this;
	}
	//push操作 
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
	LinkedList &traverse(void (*visit)(elementType &)){
		LinkedList &l=*this;
		for(int i=0;i<length;i++){
			visit(l.location(l.head,i)->num);
		}
		return l; 
	}
	//排序函数，cmp函数返回值为true,则当前元素在向下冒泡中沉底 	
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
	//判断非空 
	bool isEmpty(){
		return length?false:true;
	}	
	//重载 [] 可以通过索引访问链表元素 
	elementType & operator[] (const int index){
		if(index>=0&&index<length){
			Node * pn=head;
			for(int i=-1;i!=index;i++){
				pn=pn->next;
			}
			return (elementType &)pn->num; 
		} else{
			//索引值不合法，返回哨兵节点的num		 
			return (elementType &)head->num; 
		}
	}
	//重载 () 可以通过索引访问链表元素的地址
	const Node * operator() (const int index){
		if(index>=0&&index<length){
			Node * pn=head;
			for(int i=-1;i!=index;i++){
				pn=pn->next;
			}
			return pn; 
		} else{
			//索引值不合法，返回NULL		 
			return (const Node *)NULL; 
		}
	}
	//重载 + 实现并集 
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
	//重载等号实现重新赋值 
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


//重载输出 
ostream & operator<< (ostream &cout,LinkedList &l);
//cmp函数 
bool cmpElement(elementType x,elementType y);
//遍历函数 
void visit(elementType &num);
int main(){
	LinkedList l1,l2,l3;
	for(int i=0;i<5;i++){
		l1.push(i);
	}
	l2=l1;	
	cout<<"赋值：\n"<<l1; 
	l1.insert(2,999);
	cout<<"插入:\n"<<l1;
	cout<<"l[1]="<<l1[1]<<","<<"&l[1]="<<l1(1)<<endl;
	l1.remove(4);
	cout<<"删除:\n"<<l1;
	l1.sort(cmpElement);
	cout<<"排序:\n"<<l1;
	l1.traverse(visit);
	cout<<"遍历:\n"<<l1;
	l3=l2+l1;
	l1.clear();
	cout<<"清除:\n"<<l1;
	cout<<"并集:\n"<<l3.sort(cmpElement);
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
