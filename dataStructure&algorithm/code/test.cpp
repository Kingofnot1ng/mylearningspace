#include<iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int main(){
	//clock_t ʱ���� ��ȷ�����루ms�� 
	clock_t start,ends;
	//clock��ȡ��ǰʱ�� 
	start=clock();
	cout<<"Hello world!"<<endl;
	Sleep(50);
	ends=clock(); 
	cout<<"run time:"<<ends-start<<endl; 
	return 0;
}
