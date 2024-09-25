#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int top;
} SqStack;

// 检查栈是否为空
bool StackEmpty(SqStack S) {
	return S.top == -1;
}

// 初始化栈
void InitStack(SqStack &S) {
	S.top = -1;
}

// 入栈操作
bool Push(SqStack &S, int x) {
	if (S.top == MaxSize - 1)
		return false; // 栈满
	S.top = S.top + 1;
	S.data[S.top] = x; // 将元素x放入栈顶
	return true;
}

// 出栈操作
bool Pop(SqStack &S, int &x) {
	if (S.top == -1)
		return false; // 栈空
	x = S.data[S.top]; // 取出栈顶元素
	S.top = S.top - 1; // 栈顶指针下移
	return true;
}

// 获取栈顶元素
bool GetTop(SqStack S, int &x) {
	if (S.top == -1)
		return false; // 栈空
	x = S.data[S.top]; // 获取栈顶元素
	return true;
}

int main() {
	SqStack S;
	InitStack(S); // 初始化栈

	// 入栈操作
	printf("入栈操作:\n");
	for (int i = 1; i <= 5; i++) {
		if (Push(S, i)) {
			printf("成功入栈: %d\n", i);
		} else {
			printf("栈已满，无法入栈: %d\n", i);
		}
	}

	// 获取栈顶元素
	int topElement;
	if (GetTop(S, topElement)) {
		printf("当前栈顶元素: %d\n", topElement);
	} else {
		printf("栈为空，无法获取栈顶元素。\n");
	}

	// 出栈操作
	printf("\n出栈操作:\n");
	while (!StackEmpty(S)) {
		int poppedElement;
		if (Pop(S, poppedElement)) {
			printf("成功出栈: %d\n", poppedElement);
		} else {
			printf("栈为空，无法出栈。\n");
		}
	}

	return 0;
}

