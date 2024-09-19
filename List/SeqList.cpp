#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
typedef struct {
	int *data;		//指示动态分配数组的指针
	int MaxSize;	//顺序表的最大容量
	int length;		//顺序表的当前长度
} SeqList;

void InitList(SeqList&L) {
	//用malloc函数申请一片连续的存储空间
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = InitSize;
	L.MaxSize = InitSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList&L, int len) {
	int *p = L.data;
	//申请另一片空间
	L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];		//将数据复制到新区域
	}
	L.MaxSize = L.MaxSize + len; //顺序表最大长度增加len
	free(p);				//释放空间
}
/**顺序表位序查找
 * @param L 顺序表
 * @param i 元素位置
 *
 * @return 返回表中第i个位置的元素的值
 */
int GetElem(SeqList L, int i) {
	printf("表中第%d个位置的元素的值=%d\n", i, L.data[i - 1]);
	return L.data[i - 1];
}
/**
 * @brief 按值查找
 *
 * @param L
 * @param e
 *
 * @return
 */
int  LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			printf("表中元素的值为%d在第%d个位置的\n", e, i + 1);
			return i + 1;
		}
		return 0;
	}
}
void printList(SeqList&L) {
	for (int i = 0; i < L.MaxSize; i++) {
		printf("data[%d]=%d\n", i, L.data[i]);
	}
}

int main() {
	SeqList L;			//声明一个顺序表
	InitList(L);		//初始化顺序表
	IncreaseSize(L, 5);	//增加长度
	GetElem(L, 5);		//顺序表位序查找
	LocateElem(L, 1330143041); //按值查找
	printList(L);
	return 0;
}
