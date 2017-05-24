#include <iostream>
using namespace std;
//二分法

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
		cout<<"没有查找到K"<<endl;
	else
		cout<<"K在数组中的下标是"<<ret<<endl;
	return 0;
}*/

//缺省参数 &&  函数重载
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
1、引用在定义时必须初始化，指针没有要求。
2、一旦一个引用被初始化为指向一个对象，就不能再指向
其他对象，而指针可以在任何时候指向任何一个同类型对象
3、没有NULL引用，但有NULL指针。
4、在sizeof中含义不同：引用结果为引用类型的大小，
但指针始终是地址空间所占字节个数。
5、引用自加改变变量的内容，指针自加改变了指针指向
6、有多级指针，但是没有多级引用
7、引用比指针使用起来相对更安全
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

//大小端
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
		return 0; //小端存储
	else if(c == 0)
		return 1; //大端存储
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
		cout<<"小端存储"<<endl;
	else if (ret == 1)
		cout<<"大端存储"<<endl;
	return 0;
}
*/

/*C++的三大特性：封装、继承、多态。 函数是封装的一种形式：函数所执行的细节行为被封装在函数本
身这个更大的实体中，被封装的元素
隐藏了他们的实现细节---可以调用一个函数但是不能够访问函数所执行的语句。
封装：隐藏对象的属性和实现细节，仅对外公开接口和对象进行交互，将数据和操作数据的方法
进行有机结合。*//*类的四个作用域：局部域，全局域，空间域，类域*/