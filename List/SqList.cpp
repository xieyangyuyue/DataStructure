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

void printList(SqList&L) {
	for (int i = 0; i < MaxSize; i++) {
		printf("data[%d]=%d\n", i, L.data[i]);
	}
}

int main() {
	SqList L;		//声名一个顺序表
	InitList(L);	//初始化顺序表
	printList(L);	//打印顺序表
	return 0;
}

