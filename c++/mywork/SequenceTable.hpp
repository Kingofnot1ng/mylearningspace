#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>

using namespace std;

template <class T>
class SequenceTable{
public:
	
	SequenceTable(){
		size=1000;
		length=0;
		head=new T[size];
	}
	SequenceTable(const int size){
		if(size>=0){
			this->size=size;
			length=0;
			head=new T[size];
		}	
	}
	SequenceTable(const SequenceTable &s){
		size=1000;
		length=0;
		head=new T[size];
		for(int i=0;(i<s.length)&&(i<size);i++){
			head[i]=*(s.head+i);
			this->longer();
		}
	}
	~SequenceTable(){
		delete head;
	}
	SequenceTable & insert(int index,T element){
		if(index>=0&&index<=length&&length<size){
			++length;
			for(int i=length-1;i>index;i--){
				head[i]=head[i-1];
			}
			head[index]=element; 
		} else if(length==size){
			throw "空间不足";	
		}else{
			throw "非法索引值"; 
		} 
		return *this;
	}
	SequenceTable &remove(const int index){
		if(index>=0&&index<length){
			for(int i=index;i<length-1;i++){
				head[i]=head[i+1];
			}
			--length;
		} else{
			throw "非法索引值"; 			
		}
		return *this;
	}
	SequenceTable &traverse(void (*visit)(T &)){
		for(int i=0;i<length;i++){
			visit(head[i]);
		}
		return *this; 
	}
	void clear(){
		length=0;
	}
	void shorter(){
		if(length>0)--length;	
	}
	void longer(){
		if(length<size-1)++length;
	} 
	int getLength(){
		return length;
	}
	bool isEmpty(){
		return length?false:true;
	}
	//重载【】 可以通过索引访问链表元素 
	T & operator[] (const int index){
		if(index>=0&&index<length){
			return (T &)head[index];
		}else{
			throw "非法索引值"; 
			return (T &)head[size];	
		}
	}
	SequenceTable & operator=(const SequenceTable &s){
		this->clear();
		for(int i=0;i<(s.length)&&(i<size);i++){
			head[i]=*(s.head+i);
			this->longer();
		}
		return *this;
	}
protected:
	T * head;
	int length;
	int size;		
};

template<class T>
class SequenceTableWithOutStream:public SequenceTable<T>
{
friend ostream & operator<< (ostream &cout,const SequenceTableWithOutStream<T> &s){
	if(s.length==0){
		printf("+------------------------+\n");
		printf("|empty!                  |\n");
		printf("+------------------------+\n");
	}else{
		printf("+-----+--------+---------+\n");
		printf("|index|number  |pointer  |\n");
		printf("+-----+--------+---------+\n");
		for(int i=0;i<s.length;i++){
			cout <<"|"<<left<<setw(5)<<i<<"|"<<left<<setw(8)<<*(s.head+i)<<"|"<<left<<setw(9)<<(int *)(s.head+i)<<"|"<< endl;
			printf("+-----+--------+---------+\n");
		}
	}
	return cout;
}	
};

template<class T>
class SequenceTableOfNumber:public SequenceTable<T>
{
friend ostream & operator<< (ostream &cout,const SequenceTableOfNumber &s){
	if(s.length==0){
		printf("+------------------------+\n");
		printf("|empty!                  |\n");
		printf("+------------------------+\n");
	}else{
		printf("+-----+--------+---------+\n");
		printf("|index|number  |pointer  |\n");
		printf("+-----+--------+---------+\n");
		for(int i=0;i<s.length;i++){
			cout <<"|"<<left<<setw(5)<<i<<"|"<<left<<setw(8)<<*(s.head+i)<<"|"<<left<<setw(9)<<(int *)(s.head+i)<<"|"<< endl;
			printf("+-----+--------+---------+\n");
		}
	}
	return cout;
}
public:
	SequenceTableOfNumber &sort(bool (*cmp)(T ,T)){
		SequenceTableOfNumber &s=*this;
		for(int i=0;i<s.length-1;i++){
			for(int j=0;j<s.length-1;j++){
				if(cmp(s.head[j],s.head[j+1])){
					T element=s.head[j];
					s.head[j]=s.head[j+1];
					s.head[j+1]=element;
				} 
			}
		}
		return s; 
	}
	SequenceTableOfNumber operator+(const SequenceTableOfNumber &s1){
		SequenceTableOfNumber result;
		SequenceTableOfNumber &s2=*this;
		for(int i=0;i<s1.length;i++){			
			this->head[i]=s1[i];
			this->longer();
		}
		for(int i=0;i<s2.length;i++){			
			this->head[i+s1.length]=s2[i];
			this->longer();
		}
		return result;
	}	
};
