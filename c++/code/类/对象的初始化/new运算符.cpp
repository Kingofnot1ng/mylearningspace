#include <iostream>

using namespace std;

//new������ڶ��������ڴ� 
int * func1(){
	int *p=new int(10);
	return p;
}

int * func2(){
	int *parr=new int[10];
	for(int i=0;i<10;i++){
		*(parr+i)=i;
	}
	return parr;
}

int main(){
	int *p1=func1();
	cout<<*p1<<endl;
	//�ͷ��ڴ� 
	delete p1;
	
	int *p2=func2();
	for(int i=0;i<10;i++){
		cout<<p2[i]<<endl;
	}
	//�ͷ������ڴ� 
	delete [] p2;
	return 0;
}


