/*
	�ı��ļ���д
	https://www.cnblogs.com/azraelly/archive/2012/04/14/2446914.html 
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	//ofstream�����������ļ���д���� 
	ofstream ofs;
	ofs.open("test1.txt",ios::out);
	ofs<<"line1\n";
	ofs<<"line2\n";
	ofs<<"line3\n";
	ofs.close();
	//ifstream������ļ������� 
	ifstream ifs;
	ifs.open("test1.txt",ios::in);	
	if(ifs.is_open()){
//		char buf[1000]={0};
//		while(ifs>>buf)cout<<buf<<endl;
//		char buf[1000]={0};
//		while(ifs.getline(buf,sizeof(buf)))cout<<buf<<endl;
		string str;
		while(ifs>>str)cout<<str<<endl;
//		string str;
//		while(getline(ifs,str))cout<<str<<endl;
//		char c;
//		while((c=ifs.get())!=EOF)cout<<c;
	}else{
		cout<<"�ļ���ʧ��"<<endl; 
	}
	ifs.close();
	return 0;
}
