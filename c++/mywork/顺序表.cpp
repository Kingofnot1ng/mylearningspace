#include <iostream>
#include <limits>
#include "SequenceTable.hpp"

#define TYPE "整数"

using namespace std;

template<class T>
void initList(SequenceTableOfNumber<T> &mySequenceTable){
	cout<<"输入非"<<TYPE<<"退出"<<endl; 
	cout<<"请输入一些"<<TYPE<<":"<<endl;	
	T element;
	while(cin>>element){
		mySequenceTable.insert(mySequenceTable.getLength(),element);
	}
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
template<class T>
void destoryList(SequenceTableOfNumber<T> &mySequenceTable){
	mySequenceTable.clear();	
}
template<class T>
void clearList(SequenceTableOfNumber<T> &mySequenceTable){
	mySequenceTable.clear();	
}
template<class T>
bool listEmepty(SequenceTableOfNumber<T> mySequenceTable){
	return mySequenceTable.isEmpty();
}
template<class T>
int listLength(SequenceTableOfNumber<T> mySequenceTable){
	return mySequenceTable.getLength();
}
template<class T>
void getElem(SequenceTableOfNumber<T> mySequenceTable,int index,T &n){
	n=mySequenceTable[index];	
}
template<class T>
bool cmpElement(T x,T y){
	return x==y?true:false;
}
template<class T>
int locateElem(SequenceTableOfNumber<T> mySequenceTable,T e,bool (*cmp)(T,T)){
	for(int i=0;i<mySequenceTable.getLength();i++){
		if(cmp(e,mySequenceTable[i])){
			return i;
		}
	}
	return -1;
}
template<class T>
void priorElem(SequenceTableOfNumber<T> mySequenceTable,T cur_e,T &pre_e){
	for(int i=1;i<mySequenceTable.getLength();i++){
		if(cur_e==mySequenceTable[i]){
			pre_e=mySequenceTable[i-1];
			return;
		}
	}
	pre_e=0;
	return;
}
template<class T>
void nextElem(SequenceTableOfNumber<T> mySequenceTable,T cur_e,T &next_e){
	for(int i=0;i<mySequenceTable.getLength()-1;i++){
		if(cur_e==mySequenceTable[i]){
			next_e=mySequenceTable[i+1];
			return;
		}
	}
	next_e=0;
	return;
}
template<class T>
void listInsert(SequenceTableOfNumber<T> &mySequenceTable,int index,T e){
	mySequenceTable.insert(index,e);
}
template<class T>
void listDelete(SequenceTableOfNumber<T> &mySequenceTable,int index,T &e){
	e=mySequenceTable[index];
	mySequenceTable.remove(index);
}
template<class T>
bool cmpElement_sort(T x,T y){
	return x>=y?true:false;
}
template<class T>
void mergeList(){
	SequenceTableOfNumber<T> s1,s2,s3;
	cout<<"首先初始化链表1\n"<<endl; 
	initList(s1); 
	cout<<"然后初始化链表2\n"<<endl;
	initList(s2);
	s1.sort(cmpElement_sort<T>);
	s2.sort(cmpElement_sort<T>);
	cout<<s1<<s2;	
	T * p1=&s1[0];
	T * p2=&s2[0];
	while(((p1-&s1[0])!=s1.getLength())&&((p2-&s2[0])!=s2.getLength())){	
		if(*p1<*p2){
			s3.insert(s3.getLength(),*p1);
			++p1;
		}else{
			s3.insert(s3.getLength(),*p2);
			++p2;
		}
	}
	while((p1-&s1[0])!=s1.getLength()){
		s3.insert(s3.getLength(),*p1);
		++p1;
	}
	while((p2-&s2[0])!=s2.getLength()){
		s3.insert(s3.getLength(),*p2);
		++p2;
	}
	cout<<"并归合并L\n"<<s3;
}
void home(){
	cout<<"+----------------------------------+"<<endl;
	cout<<"|1.     初始化一个线性表           |"<<endl;
	cout<<"|2.     销毁线性表                 |"<<endl;
	cout<<"|3.     清空线性表                 |"<<endl;
	cout<<"|4.     判断线性表是否为空         |"<<endl;
	cout<<"|5.     求线性表长度               |"<<endl;
	cout<<"|6.     获取线性表中指定位置的元素 |"<<endl;
	cout<<"|7.     获取线性表元素的位置       |"<<endl;
	cout<<"|8.     求前驱                     |"<<endl;
	cout<<"|9.     求后继                     |"<<endl;
	cout<<"|10.    在线性表指定位置插入元素   |"<<endl;
	cout<<"|11.    删除线性表指定位置的元素   |"<<endl;
	cout<<"|12.    显示线性表                 |"<<endl;
	cout<<"|13.    给线性表排序（递增）       |"<<endl; 
	cout<<"|14.    合并两个非递减有序的线性表 |"<<endl;
	cout<<"+----------------------------------+"<<endl;
	cout<<"输入一个1-13外的字符退出:"; 
}

template<class T>
void function(SequenceTableOfNumber<T> &mySequenceTable,int &flag){
	int index;
	T n1,n2;
	home();
	cin>>flag;
	cin.clear();
	//std::numeric_limits< std::streamsize >::max() 相当于IO流的最大字符个数
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout<<endl;
	switch(flag){
		case 1:
			initList<T>(mySequenceTable);
			cout<<mySequenceTable;
			break;
		case 2:
			destoryList<T>(mySequenceTable);
			break;
		case 3:
			clearList<T>(mySequenceTable);
			cout<<mySequenceTable;
			break;
		case 4:
			if(listEmepty<T>(mySequenceTable))cout<<"表为空！"<<endl;
			else cout<<"非空表"<<endl;
			break;
		case 5:
			cout<<"表长为"<<listLength<T>(mySequenceTable)<<endl;
			break;
		case 6:
			cout<<"请输入元素的序列号"<<endl;
			cin>>index;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			getElem<T>(mySequenceTable,index,n1);
			cout<<"list["<<index<<"]="<<n1<<endl;
			cout<<mySequenceTable;
			break;
		case 7:
			cout<<"请输入一个要比较的"<<TYPE<<endl;
			cin>>n1;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout<<"返回值为"<<locateElem<T>(mySequenceTable,n1,cmpElement<T>)<<endl;
			cout<<mySequenceTable;
			break;
		case 8:
			cout<<"请输入一个要求前驱的"<<TYPE<<endl;
			cin>>n1;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			priorElem<T>(mySequenceTable,n1,n2);
			cout<<n1<<"的前驱为"<<n2<<endl; 
			cout<<mySequenceTable;
			break;
		case 9:
			cout<<"请输入一个要求后继的"<<TYPE<<endl;
			cin>>n1;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			nextElem<T>(mySequenceTable,n1,n2);
			cout<<n1<<"的后继为"<<n2<<endl; 
			cout<<mySequenceTable;
			break;
		case 10:
			cout<<"请输入要插入的元素"<<endl;
			cin>>n1;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout<<"请输入要插入的位置"<<endl;
			cin>>index;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			listInsert<T>(mySequenceTable,index,n1);
			cout<<"list["<<index<<"]="<<mySequenceTable[index]<<endl;
			cout<<mySequenceTable;
			break;
		case 11:
			cout<<"请输入要删除的元素的索引"<<endl;
			cin>>index;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			listDelete<T>(mySequenceTable,index,n1); 
			cout<<"list["<<index<<"]="<<n1<<"已经被删除"<<endl;
			cout<<mySequenceTable;
			break; 
		case 12:
			cout<<mySequenceTable;
			break;
		case 13: 
			mySequenceTable.sort(cmpElement_sort<T>);
			cout<<mySequenceTable;
			break;
		case 14:
			mergeList<T>();
		default:
			break; 
	}
}

int main(){
	SequenceTableOfNumber<int> mySequenceTable;
	int flag=0;	
	function<int>(mySequenceTable,flag);	
	while(flag>=1&&flag<=14){	
		function<int>(mySequenceTable,flag);
	} 
	return 0;
}


