#include <iostream>
#include "LinkedList.hpp"

using namespace std;

//cmp函数 
template<class T> 
bool cmpElement(T x,T y)
{
	return x>=y?true:false;
}
//遍历函数 
template<class T> 
void visit(T &num)
{
//	num=num+0.1;
	++num;
//	cout<<num.father<<"和"<<num.mother<<"还有"<<num.son<<"是幸福的一家人"<<endl;
}

class family{
friend ostream & operator<< (ostream &cout,family &f){
	string str;
	str+=f.father;
	str+=f.mother;
	str+=f.son;
	cout<<str;
	return cout;
}	
public:
	string father;
	string mother;
	string son;
	family(){
		this->father="father";
		this->mother="mother";
		this->son="son";	
	}
	family(string father,string mother,string son):father(father),mother(mother),son(son){			
	}
	family(int n){
		this->father="father";
		this->mother="mother";
		this->son="son";	
	}
	family(const family &f){
		this->father=f.father;
		this->mother=f.mother;
		this->son=f.son;	
	}
	family & operator=(const family &f){
		this->father=f.father;
		this->mother=f.mother;
		this->son=f.son;
		return *this;
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
};
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
//	排序函数，cmp函数返回值为true,则当前元素在向下冒泡中沉底 	
	LinkedListOfNumber &sort(bool (*cmp)(T ,T)){
		LinkedListOfNumber &l=*this;
		for(int i=0;i<l.length-1;i++){
		 	*p=l.head->next;
			for(int j=0;j<l.length-1;j++){
				if(cmp(p->num,p->next->num)){
					T num=p->num;
					p->num=p->next->num;
					p->next->num=num;
				} 
				p=p->next;
			}
		}
		return l; 
	}
};
int main(){
//	LinkedList<double> l1,l2,l3;
//	for(double i=0;i<0.5;i=i+0.1){
//		l1.push(i);
//	}
//	l2=l1;	
//	cout<<"赋值：\n"<<l1; 
//	l1.insert(2,9.9);
//	cout<<"插入:\n"<<l1;
//	cout<<"l[1]="<<l1[1]<<","<<"&l[1]="<<l1(1)<<endl;
//	l1.remove(4);
//	cout<<"删除:\n"<<l1;
//	l1.sort(cmpElement<double>);
//	cout<<"排序:\n"<<l1;
//	l1.traverse(visit<double>);
//	cout<<"遍历:\n"<<l1;
//	l3=l2+l1;
//	
//	l1.clear();
//	cout<<"清除:\n"<<l1;
//	cout<<"并集:\n"<<l3.sort(cmpElement);

	
	LinkedListOfNumber<int> l1;
	for(int i=0;i<5;++i){
		l1.push(i);
	}	
	cout<<"赋值：\n"<<l1; 
	l1.insert(2,99);
	cout<<"插入:\n"<<l1;
	cout<<"l[1]="<<l1[1]<<","<<"&l[1]="<<l1(1)<<endl;
	l1.remove(4);
	cout<<"删除:\n"<<l1;
	l1.sort;
	cout<<"排序:\n"<<l1;
	l1.traverse(visit<int>);
	cout<<"遍历:\n"<<l1;		
	l1.clear();
	cout<<"清除:\n"<<l1;
	

	
//	family f1("王爸","王妈","小王"),f2("李爸","李妈","小李"), f3("赵爸","赵妈","小赵"),f4("孙爸","孙妈","小孙");
//	LinkedListWithOutStream<family> l1;
//	l1.push(f1);
//	l1.push(f2);
//	l1.push(f3);
//	l1.push(f4);
//	
//	cout<<"赋值：\n"<<l1;
//	
//	family f5(f4);
//	l1.insert(0,f5);
//	cout<<"插入:\n"<<l1; 
//	l1.remove(4);
//	cout<<"删除:\n"<<l1;
//	cout<<"遍历:\n";
//	l1.traverse(visit<family>);
//	l1.clear();
//	cout<<"清除:\n"<<l1;
	return 0;
}
