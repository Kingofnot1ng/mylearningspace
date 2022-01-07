#include <iostream>
#include <cstring>

using namespace std;

int mykmp(const char s1[],const char s2[]);
int main(){
	char str1[]="acabaabaabcacaabc";	
	char str2[]="abaabcac";
	//abaabcac 
	int result=mykmp(str1,str2);
	cout<<"result = "<<result<<endl;
	return 0;
}
int mykmp(const char s1[],const char s2[]){
	int l1=strlen(s1);
	int l2=strlen(s2);
	int next[l2];
	int m=1,n=0;
	int i=0,j=0;
	
////	ÆÕÍ¨±©Á¦Æ¥Åä 
//	while(i<l1&&j<l2){
//		if(s1[i]==s2[j]){
//			++i;
//			++j;
//		}
//		else{
//			i-=j;
//			++i;
//			j=0;
//		}	
//	}
//	return i-j;

//	kmpËã·¨
	
	while(m<l2){
		if(n>=1){
			if(s2[n-1]==s2[n]){	
				next[n]=next[n-1]+1;
				++m;
				n=m;
			}else{
				n=next[n];
			}
		}else{
			next[n]=-1;
		}	
	}
//	while(i<l1&&j<l2){
//		if(j==-1||s1[i]==s2[j]){
//			++i;
//			++j;
//		}
//		else{ 
//			j=next[j];
//		}	
//	}
	return 0; 
}
