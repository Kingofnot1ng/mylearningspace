#include <iostream>
#include <string>

using namespace std;

class Test{
public:
	void hello(){
		cout<<"Hello ";
		this->world();
	}
	void world(){
		cout<<"world!"<<endl;
	}
	static void nihao(){
		cout<<"���!"<<endl;
	}	
};
int main(){
	Test::nihao();
	Test t1;
	t1.hello();
	//ֻҪ���漰thisָ��ʹ�ã�������NULLָ�������ʳ�Ա����  
	Test *p1=NULL;
	p1->world(); 
	return 0;
}
