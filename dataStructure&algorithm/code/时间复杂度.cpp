#include <iostream>
#include <ctime>
using namespace std;

int main(){
	clock_t start,ends;
	long long n=100000000;
	
	long long sum=0;
	//O(1) 
	start=clock();
	sum=n*(1+n)/2;
	cout<<"sum1:"<<sum<<endl;
	ends=clock();
	cout<<"run time 1: "<<ends-start<<"ms"<<endl;
	
	//O(logn)
	start=clock();
	long long i=2;
	while(i<n){
		i=i*i;
	}
	cout<<"sum1:"<<sum<<endl;
	ends=clock();
	cout<<"run time 3: "<<ends-start<<"ms"<<endl;

	//O(n) 
	start=clock();
	for(long long i=1;i<=n;i++){
		sum+=i;
	}
	cout<<"sum1:"<<sum<<endl;
	ends=clock();
	cout<<"run time 2: "<<ends-start<<"ms"<<endl;
	
	return 0;
}
