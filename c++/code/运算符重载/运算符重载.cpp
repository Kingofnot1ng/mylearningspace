#include <iostream>
#include <string>

using namespace std;

//运算符重载注意
//1.不能对已经定义的运算重载
//2.不要滥用重载 
class Numbers{
friend ostream & operator<< (ostream &cout,const Numbers &n);
public:
	int n1;
	int n2;
	
	Numbers(){
		this->n1=0;
		this->n2=0;
	}
	Numbers(int n1,int n2){
		this->n1=n1;
		this->n2=n2;
	}
	//成员函数重载+号 
	Numbers operator+ (const Numbers &n){
		Numbers temp;
		temp.n1=this->n1+n.n1;
		temp.n2=this->n2+n.n2;
		return temp;
	}
	//重载前置递增运算符
	Numbers & operator++ (){
		this->n1++;
		this->n2++;
		return *this;
	}
	//重置后置递增运算 
	Numbers operator++ (int){
		Numbers temp=*this; 
		this->n1++;
		this->n2++;
		return temp;
	}
	//重载了（）运算符 也叫仿函数 
	void operator() (string test){
		cout<<test<<endl;
	}
	void showNumbers(){
		cout<<n1<<","<<n2<<endl;
	}
	
};

Numbers operator- (const Numbers &n1,const Numbers &n2);
ostream & operator<< (ostream &cout,const Numbers &n);
int main(){
	Numbers n1(1,1);
	Numbers n2(2,2);
	Numbers n3=n1+n2;//n3=n1.operator+(n2);
	n3.showNumbers();
	Numbers n4=n1-n2;//n3= operator-(n1,n2); 
	n4.showNumbers();
	cout<<n4<<endl;
	cout<<++n4<<endl;
	cout<<n4<<endl;
	cout<<n4++<<endl;
	cout<<n4<<endl;
	n4("test");
	return 0;
}
//全局函数重载-号 
Numbers operator- (const Numbers &n1,const Numbers &n2){
	Numbers temp;
		temp.n1=n1.n1-n2.n1;
		temp.n2=n1.n2-n2.n2;
		return temp;
}
//全局函数重载左移运算符 
ostream & operator<< (ostream &cout,const Numbers &n){
	cout<<n.n1<<","<<n.n2;
	return cout;
}
