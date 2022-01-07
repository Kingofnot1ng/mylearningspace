#include <iostream>

using namespace std;

int CmpAsc(int x, int y)
{
    //如果x>y返回1，否则返回0；
    if(x>y)return 1;
    else return 0;
}
void sort(int a[], int n, int (*cmp)(int,int))//最后一个参数为函数指针类型参数
{
    /*对数组a排序，排序原则由cmp指定，若cmp为真，表示两元素逆序*/
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(cmp(a[i],a[j]))//调用传进来的函数指针
                swap(a[i],a[j]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a[6] ={8,2,1,3,4,5};
    sort(a, 6, CmpAsc);//CmpAsc函数名作为参数传递给函数sort
    for(int i=0;i<6;i++){
    	cout<<a[i]<<" "<<endl;
	}
    return 0;
}
