#include <iostream>
#include <set>

using namespace std;

class MyCompare{
public:
	bool operator()(int n1,int n2){
		return n1>n2;
	}
};
int main(){
	//默认从小到大
	//利用仿函数修改排序规则
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(2); 
	s1.insert(4);
	s1.insert(5);
	for(set<int>::iterator it=s1.begin();it!=s1.end();it++){
		cout<<*it<<",";
	} 
	cout<<endl;
	
	
	set<int,MyCompare> s2;
	s2.insert(3);
	s2.insert(1);
	s2.insert(2); 
	s2.insert(4);
	s2.insert(5);
	for(set<int,MyCompare>::iterator it=s2.begin();it!=s2.end();it++){
		cout<<*it<<",";
	} 
	return 0;
}
