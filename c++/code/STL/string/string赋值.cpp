#include <iostream>
#include <string>
using namespace std;

int main(){
	//string& operator=(const char* s) 
	string str1;
	str1="test1";
	cout<<"str1 = \""<<str1<<"\""<<endl;
	
	//string& operator=(const string &s) 
	string str2;
	str2=str1;
	cout<<"str2 = \""<<str2<<"\""<<endl;
	
	//string& operator=(char c) 
	string str3;
	str3='a';
	cout<<"str3 = \""<<str3<<"\""<<endl;
	
	
	//assign ·ÖÅä
	//string& assign(const char* s)
	string str4; 
	str4.assign("test2");
	cout<<"str4 = \""<<str4<<"\""<<endl;
	
	//string& assign(const char* s,int n)
	string str5;
	str5.assign("aaaaa",3);
	cout<<"str5 = \""<<str5<<"\""<<endl;
	
	//string& assign(const string &s)
	string str6;
	str6.assign(str5);
	cout<<"str6 = \""<<str6<<"\""<<endl;
	
	//string& assign(int n,char c)
	string str7;
	str7.assign(5,'h');
	cout<<"str = \""<<str7<<"\""<<endl; 
	return 0;
}
