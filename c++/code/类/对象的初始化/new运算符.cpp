#include <iostream>

using namespace std;

//new运算符在堆区开辟内存 
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
	//释放内存 
	delete p1;
	
	int *p2=func2();
	for(int i=0;i<10;i++){
		cout<<p2[i]<<endl;
	}
	//释放数组内存 
	delete [] p2;
	return 0;
}


