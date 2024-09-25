#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // 包含 bool 类型的定义

// 定义链表节点结构
typedef struct LinkNode {
	int data;                   // 节点数据
	struct LinkNode* next;      // 指向下一个节点的指针
} LinkNode;

// 定义链式队列结构
typedef struct {
	LinkNode *front, *rear;    // 队列的前端和后端指针
} LinkQueue;

// 判断队列是否为空
bool IsEmpty(LinkQueue Q) {
	return Q.front == Q.rear;  // 如果 front 和 rear 指向同一节点，说明队列为空
}

// 初始化队列
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode)); // 创建一个头结点
	if (Q.front == NULL) {
		fprintf(stderr, "内存分配失败\n");  // 检查内存分配是否成功
		exit(EXIT_FAILURE);
	}
	Q.front->next = NULL; // 初始化时，头结点的 next 指针设为 NULL
}

// 入队操作
void EnQueue(LinkQueue &Q, int x) {
	// 创建新节点并赋值
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) {
		fprintf(stderr, "内存分配失败\n");  // 检查内存分配是否成功
		exit(EXIT_FAILURE);
	}
	s->data = x;          // 设置节点数据
	s->next = NULL;      // 新节点的 next 指针设为 NULL

	Q.rear->next = s;    // 将新节点链接到当前队列的尾部
	Q.rear = s;          // 更新队列的尾指针
}

// 出队操作
bool DeQueue(LinkQueue &Q, int &x) {
	// 检查队列是否为空
	if (Q.front == Q.rear)
		return false;  // 如果空，返回 false

	LinkNode *p = Q.front->next; // 获取第一个有效节点
	x = p->data;                  // 保存该节点的数据

	// 将队列头指针向后移动
	Q.front->next = p->next;

	// 如果队列只有一个元素，更新 rear 指针
	if (Q.rear == p)
		Q.rear = Q.front;

	free(p);  // 释放出队节点的内存
	return true; // 返回 true 表示出队成功
}

// 主函数，用于测试链式队列的功能
int main() {
	LinkQueue Q;     // 声明队列变量
	InitQueue(Q);    // 初始化队列

	// 示例：入队操作
	for (int i = 1; i <= 5; i++) {
		EnQueue(Q, i);  // 入队 1, 2, 3, 4, 5
		printf("入队: %d\n", i);
	}

	// 示例：出队操作
	int value;
	while (!IsEmpty(Q)) {
		if (DeQueue(Q, value)) {  // 出队
			printf("出队: %d\n", value);
		} else {
			printf("出队失败\n");
		}
	}

	return 0;  // 正常结束程序
}

