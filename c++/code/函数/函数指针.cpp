#include <iostream>

using namespace std;

int CmpAsc(int x, int y)
{
    //���x>y����1�����򷵻�0��
    if(x>y)return 1;
    else return 0;
}
void sort(int a[], int n, int (*cmp)(int,int))//���һ������Ϊ����ָ�����Ͳ���
{
    /*������a��������ԭ����cmpָ������cmpΪ�棬��ʾ��Ԫ������*/
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(cmp(a[i],a[j]))//���ô������ĺ���ָ��
                swap(a[i],a[j]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a[6] ={8,2,1,3,4,5};
    sort(a, 6, CmpAsc);//CmpAsc��������Ϊ�������ݸ�����sort
    for(int i=0;i<6;i++){
    	cout<<a[i]<<" "<<endl;
	}
    return 0;
}
