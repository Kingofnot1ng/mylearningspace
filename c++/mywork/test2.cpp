#include <iostream>
#include "SequenceTable.hpp"
#include <cstdlib> 
#include <ctime>
using namespace std;


template<class T> 
bool cmpElement(T x,T y)
{
	return x>=y?true:false;
}
template<class T> 
void visit(T &num)
{
//	num=num+0.1;
	++num;
//	cout<<num.father<<"��"<<num.mother<<"����"<<num.son<<"���Ҹ���һ����"<<endl;
}
int main(){
	srand((unsigned)time(NULL));
	SequenceTableOfNumber<int> s1;
	for(int i=0;i<5;i++){
		s1.longer();
		s1[i]=rand()%11;
	}
	cout<<"��ֵ:\n"<<s1;
	s1.remove(0);
	cout<<"ɾ��:\n"<<s1;
	s1.insert(3,999);
	cout<<"����:\n"<<s1;
	s1.sort(cmpElement<int>);
	cout<<"����:\n"<<s1;
	s1.traverse(visit<int>);
	cout<<"����:\n"<<s1; 
	SequenceTableOfNumber<int> s2(s1);
	cout<<"����:\n"<<s2;
	SequenceTableOfNumber<int> s3;
	cout<<"��:\n"<<(s3=s2);
	

	try{
		int n=1000;
		for(int i=0;i<n;i++){
			cout<<s1[i]<<endl;
		}
	}catch(const char* e){
		cout<<e<<endl;
	}
	SequenceTableWithOutStream<char> s4;
	
	for(int i=0;i<5;i++){
		s4.longer();
		s4[i]=(char)(rand()%26+'a');
	} 
	cout<<"��ֵ:\n"<<s4;
	
	return 0;
}
