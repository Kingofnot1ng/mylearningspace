#include <iostream>
#include <limits>
#include "SequenceTable.hpp"

#define TYPE "����"

using namespace std;

template<class T>
void initList(SequenceTableOfNumber<T> &mySequenceTable){
	cout<<"�����"<<TYPE<<"�˳�"<<endl; 
	cout<<"������һЩ"<<TYPE<<":"<<endl;	
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
	cout<<"���ȳ�ʼ������1\n"<<endl; 
	initList(s1); 
	cout<<"Ȼ���ʼ������2\n"<<endl;
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
	cout<<"����ϲ�L\n"<<s3;
}
void home(){
	cout<<"+----------------------------------+"<<endl;
	cout<<"|1.     ��ʼ��һ�����Ա�           |"<<endl;
	cout<<"|2.     �������Ա�                 |"<<endl;
	cout<<"|3.     ������Ա�                 |"<<endl;
	cout<<"|4.     �ж����Ա��Ƿ�Ϊ��         |"<<endl;
	cout<<"|5.     �����Ա���               |"<<endl;
	cout<<"|6.     ��ȡ���Ա���ָ��λ�õ�Ԫ�� |"<<endl;
	cout<<"|7.     ��ȡ���Ա�Ԫ�ص�λ��       |"<<endl;
	cout<<"|8.     ��ǰ��                     |"<<endl;
	cout<<"|9.     ����                     |"<<endl;
	cout<<"|10.    �����Ա�ָ��λ�ò���Ԫ��   |"<<endl;
	cout<<"|11.    ɾ�����Ա�ָ��λ�õ�Ԫ��   |"<<endl;
	cout<<"|12.    ��ʾ���Ա�                 |"<<endl;
	cout<<"|13.    �����Ա����򣨵�����       |"<<endl; 
	cout<<"|14.    �ϲ������ǵݼ���������Ա� |"<<endl;
	cout<<"+----------------------------------+"<<endl;
	cout<<"����һ��1-13����ַ��˳�:"; 
}

template<class T>
void function(SequenceTableOfNumber<T> &mySequenceTable,int &flag){
	int index;
	T n1,n2;
	home();
	cin>>flag;
	cin.clear();
	//std::numeric_limits< std::streamsize >::max() �൱��IO��������ַ�����
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
			if(listEmepty<T>(mySequenceTable))cout<<"��Ϊ�գ�"<<endl;
			else cout<<"�ǿձ�"<<endl;
			break;
		case 5:
			cout<<"��Ϊ"<<listLength<T>(mySequenceTable)<<endl;
			break;
		case 6:
			cout<<"������Ԫ�ص����к�"<<endl;
			cin>>index;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			getElem<T>(mySequenceTable,index,n1);
			cout<<"list["<<index<<"]="<<n1<<endl;
			cout<<mySequenceTable;
			break;
		case 7:
			cout<<"������һ��Ҫ�Ƚϵ�"<<TYPE<<endl;
			cin>>n1;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout<<"����ֵΪ"<<locateElem<T>(mySequenceTable,n1,cmpElement<T>)<<endl;
			cout<<mySequenceTable;
			break;
		case 8:
			cout<<"������һ��Ҫ��ǰ����"<<TYPE<<endl;
			cin>>n1;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			priorElem<T>(mySequenceTable,n1,n2);
			cout<<n1<<"��ǰ��Ϊ"<<n2<<endl; 
			cout<<mySequenceTable;
			break;
		case 9:
			cout<<"������һ��Ҫ���̵�"<<TYPE<<endl;
			cin>>n1;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			nextElem<T>(mySequenceTable,n1,n2);
			cout<<n1<<"�ĺ��Ϊ"<<n2<<endl; 
			cout<<mySequenceTable;
			break;
		case 10:
			cout<<"������Ҫ�����Ԫ��"<<endl;
			cin>>n1;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout<<"������Ҫ�����λ��"<<endl;
			cin>>index;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			listInsert<T>(mySequenceTable,index,n1);
			cout<<"list["<<index<<"]="<<mySequenceTable[index]<<endl;
			cout<<mySequenceTable;
			break;
		case 11:
			cout<<"������Ҫɾ����Ԫ�ص�����"<<endl;
			cin>>index;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			listDelete<T>(mySequenceTable,index,n1); 
			cout<<"list["<<index<<"]="<<n1<<"�Ѿ���ɾ��"<<endl;
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


