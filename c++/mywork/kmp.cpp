#include <iostream>
#include <cstring>
using namespace std;

int kmp(const char s1[],const char s2[]);
int main(){
	char str1[]="";
	char str2[]="";
	int result=kmp(str1,str2);
	cout<<"result = "<<result<<endl;
}
int kmp(const char s1[],const char s2[]){
	int l1=strlen(s1);
	int l2=strlen(s2);	
	if(l2==0){
		return -1;
	}
	int i=0,j=-1;
	int next[l2]={-1};
	while(i<l2){
		if(j==-1||s2[i]==s2[j]){
			++i;
			++j;
			next[i]=j;
		}else{
			j=next[j];
		}
	}
	i=0,j=0;
	while(i<l1&&j<l2){
		if(j==-1||s1[i]==s2[j]){
			++i;
			++j;
		}else{
			j=next[j];
		}
	}
	
	if(j==l2)return i-l2;
	else return -1;
}
