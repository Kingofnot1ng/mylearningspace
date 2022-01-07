#include <iostream>

using namespace std;

class animal{
public:
	//虚函数 
	virtual void speak(){
		cout<<"动物叫"<<endl;
	}
};
class cat:public animal{
public:
	void speak(){
		cout<<"猫叫"<<endl;
	}
};
class dog:public animal{
public:
	void speak(){
		cout<<"狗叫"<<endl;
	}
};
class littlecat:public cat{
public:
	void speak(){
		cout<<"小猫叫"<<endl;
	}
};
class bigcat:public cat{
public:
	void speak(){
		cout<<"大猫叫"<<endl;
	}
}; 
//地址早绑定
/*
	动态多态满足条件
	1.有继承关系
	2.子类重写父类的虚函数
	
	动态多态的使用
	父类指针或引用指向子类对象 
*/ 
void doSpeak(animal &a){
	a.speak();
} 
int main(){
	animal a1;
	doSpeak(a1);
	cat c1;
	//animal &a =c1 
	doSpeak(c1); 
	dog d1;
	doSpeak(d1);
	littlecat lc1;
	doSpeak(lc1);
	bigcat bc1;
	doSpeak(bc1);  
	return 0;
}



