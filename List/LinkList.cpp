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

typedef struct LNode {
	// 定义单链表结点类型
	int data;			// 每个节点存放一个数据元素
	struct LNode *next; // 指针指向下一个结点
} LNode, *LinkList;

// 判断单链表是否为空
bool Empty(LinkList L) {
	return L->next == nullptr;
}

// 初始化一个单链表(带头结点)
bool InitList(LinkList &L) {
	L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
	if (Empty(L))
		return false; // 内存不够，分配失败
	L->next = NULL;
	return true; // 头结点之后暂时没有结点
}

// 定义获取链表中第i个元素的函数
LNode *GetElem(LinkList L, int i) {
	if (i < 0) return NULL;
	LNode*cur = L; // 指针cur指向当前 L指向头结点
	int j = 0; // 当前cur指向第几个结点
	while (cur != NULL && j < i) {
		// 循环找到第i-1个结点
		cur = cur->next;
		j++;
	}
	return cur;

}



// 前插操作:在p结点之前插入元素e
bool InsertPriorNode(LNode *p, int e) {
	if (p == NULL)
		return false;
	LNode *prior = (LNode *)malloc(sizeof(LNode));
	if (prior == NULL)
		return false;
	prior->next = p->next;
	p->next = prior;
	// prior结点在p后面 将p结点的数据复制到prior位置，p结点填充e
	prior->data = p->data;
	p->data = e;
	return true;
}

// 后插操作：在p结点之后插入元素e
bool InsertNextNode(LNode *p, int e) {
	if (p == NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = e; // 结点保存数据元素e
	s->next = p->next;
	p->next = s; // 将结点s连接到p之后
	return true;
}

// 在第i个位置插入元素e(带头结点)
bool ListInsert(LinkList &L, int i, int e) {
	if (i < 1)
		return false;
	LNode* cur = GetElem(L, i - 1);//找到第i-1个结点
	// 后插操作：在p结点之后插入元素e
	return InsertNextNode(cur, e);
}

/**
 * @brief 按位序删除 有头结点
 *
 * @param L
 * @param e 删除值
 * @param i 位序
 *
 */
bool ListDelete(LinkList &L, int i, int &e) {
	if (i < 1)
		return false;
	LNode *pre = GetElem(L, i - 1);//找到第i-1个结点
	// 结点位置不对
	if (!pre || !pre->next)
		return false;
	LNode *temp = pre->next;
	e = temp->data;
	pre->next = temp->next;
	free(temp);
	return true;
}
/**
 * @brief 按指定节点删除
 *
 * @param p 删除结点
 */
bool DeleteNode(LNode *p) {

	if (p == NULL)
		return false;
	LNode *temp = p->next;
	// p结点数据被temp数据覆盖
	p->data = temp->data;
	// 将temp链接断开
	p->next = temp->next;
	free(temp);
	return true;
}

int main() {
	LinkList L;	 // 声明一个指向单链表的指针
	InitList(L); // 初始化一个空表
}
