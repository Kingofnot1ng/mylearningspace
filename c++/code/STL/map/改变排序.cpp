#include <iostream>
#include <map>

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
	map<int,int> m1;
	m1.insert(make_pair(3,1));
	m1.insert(make_pair(1,2));
	m1.insert(make_pair(2,3));
	m1.insert(make_pair(4,4));
	m1.insert(make_pair(5,5));
	for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++){
		cout<<it->first<<","<<it->second<<endl;
	} 
	cout<<endl;
	
	map<int,int,MyCompare> m2;
	m2.insert(make_pair(3,1));
	m2.insert(make_pair(1,2));
	m2.insert(make_pair(2,3));
	m2.insert(make_pair(4,4));
	m2.insert(make_pair(5,5));
	for(map<int,int,MyCompare>::iterator it=m2.begin();it!=m2.end();it++){
		cout<<it->first<<","<<it->second<<endl;
	} 
	cout<<endl;
	return 0;
}
