#include <iostream>

using namespace std;

class animal{
public :
	int age;
};
//—Ú¿‡ 
class yang:virtual public animal{
};
//Õ’¿‡ 
class tuo:virtual public animal{
	
};
//—ÚÕ’¿‡
class yangtuo:public yang,public tuo{
}; 
int main(){
	yangtuo yt1;
	yt1.yang::age=18;
	yt1.tuo::age=19;
	cout<<yt1.yang::age<<endl;
	cout<<yt1.tuo::age<<endl;
	return 0;
}
