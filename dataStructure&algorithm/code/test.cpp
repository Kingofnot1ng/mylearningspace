#include<iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main(){
	//clock_t 时间型 精确到毫秒（ms） 
	clock_t start,ends;
	//clock获取当前时间 
	start=clock();
	cout<<"Hello world!"<<endl;
	Sleep(50);
	ends=clock(); 
	cout<<"run time:"<<ends-start<<endl; 
	return 0;
}
