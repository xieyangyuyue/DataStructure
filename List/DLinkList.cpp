#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
	int data;
	struct DNode* next;
	struct DNode* prior;
} DNode;

typedef DNode* DLinkList;

// 初始化链表
int InitDlinkList(DLinkList* list) {
	*list = (DNode*)malloc(sizeof(DNode));
	if (*list == NULL) return 0; // 内存分配失败
	(*list)->next = NULL;
	(*list)->prior = NULL;
	return 1; // 成功
}

// 在链表尾部插入新节点
void InsertNextDNode(DLinkList list, DNode* newNode) {
	if (list == NULL || newNode == NULL) return;

	DNode* last = list;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = newNode;
	newNode->prior = last;
	newNode->next = NULL; // 新节点的next指向NULL
}

// 打印链表
void PrintDLinkList(DLinkList list) {
	DNode* current = list->next; // 从第一个实际节点开始
	while (current != NULL) {
		printf("%d->", current->data);
		current = current->next;
	}
	printf("\n");
}

// 删除某节点后继节点
void DeleteNextDNode(DNode* node) {
	if (node == NULL || node->next == NULL) return;

	DNode* toDelete = node->next; // 要删除的节点
	node->next = toDelete->next; // 跳过toDelete

	if (toDelete->next != NULL) {
		toDelete->next->prior = node; // 更新后续节点的prior
	}

	free(toDelete); // 释放内存
}

// 释放链表内存
void FreeDLinkList(DLinkList list) {
	DNode* current = list;
	DNode* nextNode;
	while (current != NULL) {
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
}

int main() {
	DLinkList list;
	if (!InitDlinkList(&list)) {
		printf("初始化链表失败\n");
		return -1;
	}

	// 插入节点
	for (int i = 1; i <= 5; i++) {
		DNode* newNode = (DNode*)malloc(sizeof(DNode));
		newNode->data = i;
		newNode->next = NULL; // 新节点的next指向NULL
		newNode->prior = NULL; // 新节点的prior暂时不设置
		InsertNextDNode(list, newNode); // 在尾部插入新节点
	}

	// 打印链表内容
	printf("链表内容: ");
	PrintDLinkList(list);

	// 删除第一个节点后的链表内容
	if (list->next != NULL) {
		DeleteNextDNode(list); // 删除第一个节点
	}

	printf("删除第一个节点后的链表内容: ");
	PrintDLinkList(list);

	// 释放链表内存
	FreeDLinkList(list);

	return 0;
}

