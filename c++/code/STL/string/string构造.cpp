#include <iostream>
#include <string>
using namespace std;

int main(){
	//string();
	string str1;
	cout<<"str1 = \""<<str1<<"\""<<endl;
	
	//string(const char* s);
	string str2("test2");
	cout<<"str2 = \""<<str2<<"\""<<endl;
	
	//string(const string &s);
	string str3(str2);
	cout<<"str3 = \""<<str3<<"\""<<endl;
	
	//string(int n,char c);
	string str4(5,'h');
	cout<<"str4 = \""<<str4<<"\""<<endl;
	return 0;
}
