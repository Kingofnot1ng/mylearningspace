#include <iostream>
#include <string>
using namespace std;

int main(){
	//string substr(int pos,int n=npos)const;
	string str1("12345");
	cout<<str1.length()<<endl;
	string str2=str1.substr(1,str1.length()-1);
	cout<<str2;
	return 0;
}
