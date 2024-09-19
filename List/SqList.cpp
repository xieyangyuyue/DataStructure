/*
顺序表的实现--静态分配
*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10  //定义最大长度
typedef struct {
	int data[MaxSize];//用静态数组存放数据元素
	int length;	//顺序表的当前长度
} SqList; //顺序表的类型定义

//基本操作 初始化 顺序表
void InitList(SqList&L) {
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = 0;
		L.length = 0;
	}
}

/**
  
 * @param L 顺序表
 * @param e 插入值
 * @param i 位置插入
 *
 * @return
 */
bool ListInsert(SqList&L, int i, int e) {
	if (i < 1 || i > L.length + 1) return false;//判定范围是否有效
	if (L.length >= MaxSize) return false;		//储存空间已满
	for (int j = L.length; j >= i; j--) {				//将第i个元素及其以后元素后移
		L.data[j] = L.data[j - 1];					//会将i-1数组值赋值i下标 j>=i
	}
	L.data[i - 1] = e;								//在位置i处放入e
	L.length++;
	return true;
	
}
/**
  按照元素位置删除，使用引用元素值
 * @param L 顺序表
 * @param e	使用引用 返回元素值
 * @param i
  
 */
bool ListDelete(SqList&L, int i, int &e) {
	if (i < 1 || i > L.length) {			//判断i范围是否有效
		printf("位序不合法\n");
		return false;
	}
	e = L.data[i - 1];					//被删除的元素赋值e
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];		//将第i个位置后元素前移 覆盖前值
	}
	L.length--;
	printf("已删除第%d个元素，删除元素值为=%d\n", i, e);
	return true;
}

void printList(SqList&L) {
	for (int i = 0; i < MaxSize; i++) {
		printf("data[%d]=%d\n", i, L.data[i]);
	}
}

int main() {
	SqList L;		//声名一个顺序表
	InitList(L);	//初始化顺序表
	//需要插入几个元素 否则length=0，函数返回false
	ListInsert(L, 1, 3);
	ListInsert(L, 2, 4);
	ListInsert(L, 3, 5);
	ListInsert(L, 4, 6);
	//删除返回值
	int e = -1;
	ListDelete(L, 2, e);
	printList(L);	//打印顺序表
	return 0;
}

