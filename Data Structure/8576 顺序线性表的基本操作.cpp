#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100 // 线性表的初始分配存储空间
#define LISTINCREMENT 10   // 线性表存储空间的增量
#define ElemType int       // 线性表存储的数据类型

// 定义顺序表的结构体
typedef struct
{
	int *elem;  // 存储空间的基地址
	int length; // 当前元素个数
	int listsize; // 当前存储空间大小（以sizeof(ElemType)为单位）
} SqList;

// 初始化顺序表
int InitList_Sq(SqList &L)
{
	// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
	// 请补全代码
	L.elem = new ElemType[LIST_INIT_SIZE]; // 分配存储空间
	if(!L.elem) // 分配失败
	{
		return 0;
	}
	L.length = 0; // 初始化当前元素个数为0
	L.listsize = LIST_INIT_SIZE; // 初始化存储空间大小为LIST_INIT_SIZE
	return 1; // 初始化成功
}

// 输出顺序表中的所有元素
int Load_Sq(SqList &L)
{
	int i;
	if(L.length == 0) printf("The List is empty!"); // 线性表为空
	else
	{
		printf("The List is: ");
		for(i = 0; i < L.length; i++) printf("%d ",L.elem[i]); // 输出每个元素
	}
	printf("\n");
	return OK;
}

// 在顺序线性表L中第i个位置之前插入新的元素e
int ListInsert_Sq(SqList &L,int i,int e)
{
	// 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e
	// i的合法值为1≤i≤L.length +1
	// 请补全代码
	if(i < 1 || i > L.length + 1) // 判断i是否合法
	{
		return 0;
	}
	for(int j = L.length - 1; j >= i - 1; j--) // 将第i个位置之后的元素都往后移动一位，腾出位置插入新元素
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e; // 将新元素插入到第i个位置
	L.length++; // 当前元素个数加1
	return 1; // 插入成功
}

// 在顺序线性表L中删除第i个位置的元素，并用e返回其值
int ListDelete_Sq(SqList &L,int i, int &e)
{
	// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
	// i的合法值为1≤i≤L.length
	// 请补全代码
	if(i < 1 || i > L.length) // 判断i是否合法
	{
		return 0;
	}
	e = L.elem[i - 1]; // 用e返回被删除的元素的值
	for(int j = i - 1; j < L.length - 1; j++) // 将第i个位置之后的元素都往前移动一位，覆盖掉被删除的元素
	{
		L.elem[j] = L.elem[j + 1];
	}
	L.length--; // 当前元素个数减1
	return 1; // 删除成功
}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if(InitList_Sq(T))    // 判断顺序表是否创建成功
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
		case 1:
			scanf("%d%d",&i,&x);
			if(!ListInsert_Sq(T, i, x)) printf("Insert Error!\n"); // 执行插入函数，根据返回值判断i值是否合法
			else printf("The Element %d is Successfully Inserted!\n", x);
			break;
		case 2:
			scanf("%d",&i);
			if(!ListDelete_Sq(T, i, e)) printf("Delete Error!\n"); // 执行删除函数，根据返回值判断i值是否合法
			else printf("The Element %d is Successfully Deleted!\n", e);
			break;
		case 3:
			Load_Sq(T);
			break;
		case 0:
			return 1;
		}
	}
}

