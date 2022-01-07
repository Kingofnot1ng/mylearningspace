#include <iostream>

using namespace std;

//����[] 
template <class T>
//��С������������ 
void sort(T arr[],int len){
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-1;j++){
			//�ȶ���> 
			if(arr[j]>arr[j+1]){
				//����= 
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
		//����<< 
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//��ת���� 
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
