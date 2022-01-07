#include <iostream>

using namespace std;

//定义[] 
template <class T>
//从小到大排序数组 
void sort(T arr[],int len){
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-1;j++){
			//先定义> 
			if(arr[j]>arr[j+1]){
				//定义= 
				T temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			} 
		}
	} 
} 
template <class T>
void printArray(T arr[],int len){
	for(int i=0;i<len;i++){
		//定义<< 
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//翻转数组 
template <class T>
void reverse(T arr[],int len){
	for(int i=0;i<len/2;i++){
		T temp=arr[i];
		arr[i]=arr[len-i-1];
		arr[len-i-1]=temp;
	}
}
int main(){
	char charArr[]="badcfe";
	int calen=sizeof(charArr)/sizeof(char)-1;
	sort<char>(charArr,calen);
	printArray<char>(charArr,calen);
	
	int intArr[]={3,2,1,4,5,};
	int ialen=sizeof(intArr)/sizeof(int);
	sort<int>(intArr,ialen);
	reverse<int>(intArr,ialen);
	printArray<int>(intArr,ialen);
	return 0;
} 
