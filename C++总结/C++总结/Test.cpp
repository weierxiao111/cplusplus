#include <iostream>
using namespace std;
//���ַ�

/* 
#include <iostream>
#include <assert.h>
using namespace std;

int BinaryFind(const int *arr, size_t left, size_t right, int key)
{
	assert(arr);
	int mid = left + ((right - right)>>1);
	if (left <= right)
	{
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid] < key)
		{
			return BinaryFind(arr,mid+1,right, key);
		}
		else
		{
			return BinaryFind(arr,left,mid-1, key);
		}
	}
	return -1;
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int sz = sizeof(arr)/sizeof(arr[0])-1;
	int K = 5;
	int ret = BinaryFind(arr,0,sz, K);
	if(ret == -1)
		cout<<"û�в��ҵ�K"<<endl;
	else
		cout<<"K�������е��±���"<<ret<<endl;
	return 0;
}*/

//ȱʡ���� &&  ��������
/*#include <iostream>

using namespace std;

//void Funtest (){cout<<" "<<endl;}
void Funtest (int i , int j, int k= 0){cout<<i<<j<<k<<endl;}
int Funtest ( int j = 1, int k){cout<<j<<k<<endl;return 1;}

int main()
{
	Funtest(1);
	return 0;
}
*/
/*
1�������ڶ���ʱ�����ʼ����ָ��û��Ҫ��
2��һ��һ�����ñ���ʼ��Ϊָ��һ�����󣬾Ͳ�����ָ��
�������󣬶�ָ��������κ�ʱ��ָ���κ�һ��ͬ���Ͷ���
3��û��NULL���ã�����NULLָ�롣
4����sizeof�к��岻ͬ�����ý��Ϊ�������͵Ĵ�С��
��ָ��ʼ���ǵ�ַ�ռ���ռ�ֽڸ�����
5�������ԼӸı���������ݣ�ָ���ԼӸı���ָ��ָ��
6���ж༶ָ�룬����û�ж༶����
7�����ñ�ָ��ʹ��������Ը���ȫ
*/
//
//void Swap(int &left, int &right)
//{
//int temp = left;
//left = right;
//right = temp;
//}

/*
#define Offset(s,num)   ((size_t)&((s*)0)->num)
struct A{
	int a;
	char b;
A():a(1),b('0'){}
};
class B{};
int main()
{
A c;
cout<<(A*)&c.a<<endl;
cout<<Offset(A,a)<<endl;
cout<<sizeof(A)<<endl;
cout<<sizeof(B)<<endl;

return 0;

}
*/

//��С��
/*
union un{
	int a;
	char c;
}un;

int BigorLittleEndian1()
{
	int i = 1;
	char c = *(char*)&i;
	if (c == 1)
		return 0; //С�˴洢
	else if(c == 0)
		return 1; //��˴洢
}

int BigorLittleEndian2()
{
	un.a = 1;
	if (un.c == 1)
		return 0;
	else if (un.c == 0)
		return 1;
}



int main()
{
	int ret = BigorLittleEndian2();
	if  (ret == 0)
		cout<<"С�˴洢"<<endl;
	else if (ret == 1)
		cout<<"��˴洢"<<endl;
	return 0;
}
*/

/*C++���������ԣ���װ���̳С���̬�� �����Ƿ�װ��һ����ʽ��������ִ�е�ϸ����Ϊ����װ�ں�����
����������ʵ���У�����װ��Ԫ��
���������ǵ�ʵ��ϸ��---���Ե���һ���������ǲ��ܹ����ʺ�����ִ�е���䡣
��װ�����ض�������Ժ�ʵ��ϸ�ڣ������⹫���ӿںͶ�����н����������ݺͲ������ݵķ���
�����л���ϡ�*//*����ĸ������򣺾ֲ���ȫ���򣬿ռ�������*/