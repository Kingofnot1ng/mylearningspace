#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class person{
public:
	int age;
	string name;
};
int main(){
	ofstream ofs;
	ofs.open("test2.txt",ios::out|ios::binary);
	person p1={20,"张三"};
	ofs.write((const char *)&p1,sizeof(p1));
	ofs.close();
	
	ifstream ifs;
	ifs.open("test2.txt",ios::in|ios::binary);
	if(ifs.is_open()){
		person p2;
		ifs.read((char *)&p2,sizeof(p2));
		cout<<p2.age<<endl;
		cout<<p2.name<<endl;
	}else{
		cout<<"打开失败"<<endl; 
	}
	ifs.close();
	return 0;
}
