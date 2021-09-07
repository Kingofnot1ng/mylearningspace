#include<iostream>
#include<time.h>

using namespace std;

int main(){
	clock_t start,ends;//计时 
	unsigned long long sum=0;
	long long n=100000000;//1加到1亿 
	//不用算法 
	start=clock();
	for(long long i=1;i<=n;i++){
		sum+=i;
	}
	cout<<"sum1:"<<sum<<endl;
	ends=clock();
	cout<<"run time 1: "<<ends-start<<"ms"<<endl;
	//用算法 
	start=clock();
	sum=n*(1+n)/2;
	cout<<"sum1:"<<sum<<endl;
	ends=clock();
	cout<<"run time 2: "<<ends-start<<"ms"<<endl;  
	
	return 0;
}
