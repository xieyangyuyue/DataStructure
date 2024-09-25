#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10 // 定义队列最大容量

// 队列结构体
typedef struct {
	int data[MaxSize]; // 存储队列元素的数组
	int front, rear;   // 队头和队尾指针
} SqQueue;

// 检查队列是否为空
bool QueueEmpty(SqQueue Q) {
	return Q.front == Q.rear; // 如果队头等于队尾，则队列为空
}

// 初始化队列
void InitQueue(SqQueue &Q) {
	Q.rear = Q.front = 0; // 初始化队头和队尾指针
}

// 入队操作，向队列中添加元素
bool EnQueue(SqQueue &Q, int x) {
	// 判断队列是否已满
	if ((Q.rear + 1) % MaxSize == Q.front) {
		return false; // 队列满，入队失败
	}
	Q.data[Q.rear] = x; // 添加元素
	Q.rear = (Q.rear + 1) % MaxSize; // 更新队尾指针
	return true; // 入队成功
}

// 出队操作，从队列中删除元素
bool DeQueue(SqQueue &Q, int &x) {
	// 判断队列是否为空
	if (Q.rear == Q.front) {
		return false; // 队列空，出队失败
	}
	x = Q.data[Q.front]; // 取出队头元素
	Q.front = (Q.front + 1) % MaxSize; // 更新队头指针
	return true; // 出队成功
}

// 获取队头元素但不删除
bool GetHead(SqQueue Q, int &x) {
	// 判断队列是否为空
	if (Q.rear == Q.front) {
		return false; // 队列空，无法获取队头元素
	}
	x = Q.data[Q.front]; // 获取队头元素
	return true; // 获取成功
}

// 打印队列中的所有元素（辅助函数）
void PrintQueue(SqQueue Q) {
	if (QueueEmpty(Q)) {
		printf("Queue is empty.\n");
		return;
	}

	int index = Q.front;
	printf("Queue elements: ");
	while (index != Q.rear) {
		printf("%d ", Q.data[index]); // 打印当前元素
		index = (index + 1) % MaxSize; // 移动到下一个元素
	}
	printf("\n");
}

// 主程序示例
int main() {
	SqQueue queue;
	InitQueue(queue); // 初始化队列

	// 测试入队操作
	for (int i = 0; i < 5; ++i) {
		if (EnQueue(queue, i * 10)) { // 添加元素
			printf("Enqueued: %d\n", i * 10);
		} else {
			printf("Failed to enqueue: %d\n", i * 10);
		}
	}

	// 打印当前队列状态
	PrintQueue(queue);

	// 测试出队操作
	int item;
	while (DeQueue(queue, item)) { // 循环出队直到队列为空
		printf("Dequeued: %d\n", item);
	}

	// 再次打印队列状态
	PrintQueue(queue);

	return 0; // 程序结束
}

