#include <iostream>

using namespace std;

void input(int arr1[],int*parr1length,int arr2[],int*parr2length);
void jiao(int arr1[],int arr1length,int arr2[],int arr2length);
void bing(int arr1[],int arr1length,int arr2[],int arr2length);
void cha(int arr1[],int arr1length,int arr2[],int arr2length);
void show(int arr[],int arrlength); 
bool exist(int arr[],int arrlength,int number);
int main(){
	int flag;
	int arr1[100],arr2[100];
	int arr1length,arr2length;
	 
	cout<<"+------------------------------------+"<<endl;
	cout<<"|集合A和B的数据元素类型为整数。      |\n|输入数字1-4进行对应操作，           |\n|输入任意其他值退出。                |"<<endl;
	cout<<"+------------------------------------+"<<endl; 
	cout<<"|1---输入集合A和B                    |"<<endl;
	cout<<"|2---求集合A交B                      |"<<endl;
	cout<<"|3---求集合A并B                      |"<<endl;
	cout<<"|4---求集合A-B                       |"<<endl;
	cout<<"+------------------------------------+"<<endl;
	cout<<"请输入:";
	cin>>flag;
	switch(flag){
		case 1:
			input(arr1,&arr1length,arr2,&arr2length);
			break;
		case 2:
			jiao(arr1,arr1length,arr2,arr2length);
			break;
		case 3:
			bing(arr1,arr1length,arr2,arr2length);
			break;
		case 4:
			cha(arr1,arr1length,arr2,arr2length);
			break;
	}	
	while(flag>0&&flag<=4){
		cout<<"+------------------------------------+"<<endl;
		cout<<"|集合A和B的数据元素类型为整数。      |\n|输入数字1-4进行对应操作，           |\n|输入任意其他值退出。                |"<<endl;
		cout<<"+------------------------------------+"<<endl; 
		cout<<"|1---输入集合A和B                    |"<<endl;
		cout<<"|2---求集合A交B                      |"<<endl;
		cout<<"|3---求集合A并B                      |"<<endl;
		cout<<"|4---求集合A-B                       |"<<endl;
		cout<<"+------------------------------------+"<<endl;
		cout<<"请输入:";
		cin>>flag;
		switch(flag){
			case 1:
				input(arr1,&arr1length,arr2,&arr2length);
				break;
			case 2:
				jiao(arr1,arr1length,arr2,arr2length);
				break;
			case 3:
				bing(arr1,arr1length,arr2,arr2length);
				break;
			case 4:
				cha(arr1,arr1length,arr2,arr2length);
				break;
		}	
	}
	return 0;
}

void input(int arr1[],int*parr1length,int arr2[],int*parr2length){
	
	*parr1length=0;
	*parr2length=0;
	cout<<"请输入整数作为集合的元素，输入非数字值退出"<<endl; 
	for(int i=0;;i++){
		int number=0;
		cout<<"正在输入arr1"<<"["<<i<<"]:";
		if(cin>>number&&(!exist(arr1,*parr1length,number))){
			arr1[i]=number;
			(*parr1length)++;
		}else if(exist(arr1,*parr1length,number)){
			cout<<"集合中已经存在元素 "<<number<<" ,请重新输入"<<endl;
			i--;
			continue; 
		}else{
			cout<<"输入非整数值,切换到arr2"<<endl;
			cin.clear();
			cin.sync();
			break;	
		}
	}
	for(int i=0;;i++){
		int number=0;
		cout<<"正在输入arr2"<<"["<<i<<"]:";;
		if(cin>>number&&(!exist(arr2,*parr2length,number))){
			arr2[i]=number;
			(*parr2length)++;
		}else if(exist(arr2,*parr2length,number)){
			cout<<"集合中已经存在元素 "<<number<<" ,请重新输入"<<endl;
			i--;
			continue; 
		}else{
			cout<<"输入非整数值,退出输入"<<endl;
			cin.clear();
			cin.sync();
			break;	
		}
	}
	cout<<"输入完成,下面是结果"<<endl;
	cout<<"A:"; 
	show(arr1,*parr1length);
	cout<<"B:";
	show(arr2,*parr2length);
	return;
}

void jiao(int arr1[],int arr1length,int arr2[],int arr2length){
	int minl=(arr1length<=arr2length)?arr1length:arr2length;
	int jiaoji[minl];
	int l=0;
	cout<<"当前集合各项为:"<<endl;
	cout<<"A:"; 
	show(arr1,arr1length);
	cout<<"B:";
	show(arr2,arr2length);
	if(minl==arr1length){
		for(int i=0;i<arr1length;i++){
			if(exist(arr2,arr2length,arr1[i])){
				jiaoji[l]=arr1[i];
				l++;
			}
		}
	}else if(minl==arr2length){
		for(int i=0;i<arr2length;i++){
			if(exist(arr1,arr1length,arr2[i])){
				jiaoji[l]=arr2[i];
				l++;
			}
		}
	}
	cout<<"A交B:";
	show(jiaoji,l);	
}
void bing(int arr1[],int arr1length,int arr2[],int arr2length){
	int bingji[arr1length+arr2length];
	int l=0;
	cout<<"当前集合各项为:"<<endl;
	cout<<"A:"; 
	show(arr1,arr1length);
	cout<<"B:";
	show(arr2,arr2length);
	for(int i=0;i<arr1length;i++){
		if(!exist(bingji,l,arr1[i])){
			bingji[l]=arr1[i];
			l++; 
		}
	}
	for(int i=0;i<arr2length;i++){
		if(!exist(bingji,l,arr2[i])){
			bingji[l]=arr2[i];
			l++; 
		}
	}
	cout<<"A并B:";
	show(bingji,l);
}
void cha(int arr1[],int arr1length,int arr2[],int arr2length){ 
	int chaji[arr1length];
	int l=0;
	cout<<"当前集合各项为:"<<endl;
	cout<<"A:"; 
	show(arr1,arr1length);
	cout<<"B:";
	show(arr2,arr2length);
	for(int i=0;i<arr1length;i++){
		if(!exist(arr2,arr2length,arr1[i])){
			chaji[l]=arr1[i];
			l++;
		}
	}
	cout<<"A-B:";
	show(chaji,l);
}
bool exist(int arr[],int arrlength,int number){
	for(int i=0;i<arrlength;i++)
	{
		if(arr[i]==number){
			return true;
		}		
	}
	return false;
}
void show(int arr[],int arrlength){
	cout<<"{ ";
	for(int i=0;i<arrlength;i++){
		cout<<" "<<arr[i]<<",";
	}
	cout<<"}"<<endl;
	return; 
}
