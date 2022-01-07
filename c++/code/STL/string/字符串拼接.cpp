#include <iostream>
#include <string>
using namespace std;

int main(){
	//string& operator+=(const char* s) 
	string str("1");
	str+="2";
	cout<<"str = \""<<str<<"\""<<endl;
	
	//string& operator+=(const string &s) 
	str+=str;
	cout<<"str = \""<<str<<"\""<<endl;
	
	//string& operator+=(char c) 
	str+='3';
	cout<<"str = \""<<str<<"\""<<endl;
	
	//append ×·¼Ó 
	//string& append(const char* s)
	str.append("4444");
	cout<<"str = \""<<str<<"\""<<endl;
	
	//string& append(const char* s,int n)
	str.append("55555",1);
	cout<<"str = \""<<str<<"\""<<endl;
	
	//string& append(const string &s)
	str.append(str);
	cout<<"str = \""<<str<<"\""<<endl;
	//string& append(const string &s,int pos,int n)
	str.append(str,0,3);
	cout<<"str = \""<<str<<"\""<<endl;
	//string& append(int n,char c)
	str.append(6,'6');
	cout<<"str = \""<<str<<"\""<<endl;
	return 0;
}
