#include <stdio.h>
#include <stdlib.h>

/**
 * typedef struct LNode{	//定义单链表结点类型
  int data;			//每个节点存放一个数据元素
  struct LNode*next;	//指针指向下一个结点
  };
  typedef struct LNode LNode;
  typedef struct LNode* LinkList;
  //前者强调返回一个节点，后者强调这是一个单链表
  LNode* L ;//声明一个指向单链表第一个结点的指针
  LinkList L;//声明一个指向单链表第一个结点的指针
 */

typedef struct LNode {	//定义单链表结点类型
	int data;			//每个节点存放一个数据元素
	struct LNode*next;	//指针指向下一个结点
} LNode, * LinkList;

//判断单链表是否为空
bool Empty(LinkList L) {
	return L->next == nullptr;
}

//初始化一个单链表(带头结点)
bool InitList(LinkList &L) {
	L = (LNode*) malloc(sizeof(LNode));	//分配一个头结点
	if (Empty(L)) return false;			//内存不够，分配失败
	L->next = NULL;
	return true;						//头结点之后暂时没有结点
}

// 定义获取链表中第i个元素的函数
LNode* GetElem(LinkList L, int i) {
	// 初始化计数器j为1，因为链表的头结点通常不计入元素计数
	int j = 1;
	// p指向链表的第一个结点，即头结点的下一个结点
	LNode* p = L->next;
	// 如果i为0，表示获取头结点，直接返回头结点指针
	if (i == 0) return L;
	// 如果i小于1，表示位置不合法，返回NULL
	if (i < 1) return NULL;
	// 当p不为空且j小于i时，继续遍历链表
	while (p != NULL && j < i) {
		// p指向下一个结点
		p = p->next;
		// 计数器j加1
		j++;
	}
	// 返回第i个结点的指针，如果不存在第i个结点，则p将为NULL
	return p;
}



int main() {
	LinkList L;	//声明一个指向单链表的指针
	InitList(L);//初始化一个空表

}
