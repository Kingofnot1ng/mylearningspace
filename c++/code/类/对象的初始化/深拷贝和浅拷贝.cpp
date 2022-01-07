#include <iostream>

using namespace std;

//深拷贝和浅拷贝 
class Phone{
public:
	Phone(){
		owner="无";
		brand="无";
		price=NULL;	
	}
	Phone(string owner,string brand,int price){
		this->owner=owner;
		this->brand=brand;
		this->price=new int(price);	
	}
//	//浅拷贝,编译器默认拷贝构造函数 
//	Phone(const Phone &p){
//		this->owner=p.owner;
//		this->brand=p.brand;
//		//这里拷贝后的对象中的price指向原来对象中的内存 
//		this->price=p.price;	
//	}
	//深拷贝,重新从堆区开辟内存 
	Phone(const Phone &p){
		this->owner=p.owner;
		this->brand=p.brand;
		this->price=new int(*p.price);	
	}
	//析构函数释放堆区的数据 
	~Phone(){
		if(price!=NULL){
			delete price;
			price=NULL; 
		}	
	}
	void showPhone(){
		cout<<"品牌："<<brand<<" 价格："<<*price<<" 所有者："<<owner<<endl;
	}
protected:
	string owner;
	string brand;
	int *price; 
};
int main(){
	Phone p1("姚家乐","realme",1999);
	p1.showPhone();
	Phone p2(p1);
	p2.showPhone(); 
	return 0;
}
