#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义二叉树节点结构
typedef struct BiTNode {
	int data;               // 节点的数据
	struct BiTNode *lchild; // 左子节点指针
	struct BiTNode *rchild; // 右子节点指针
} BiTNode, *BiTree; // BiTree 是 BiTNode 的指针类型

// 创建一个新的节点
BiTNode* createNode(int data) {
	// 分配内存空间
	BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
	if (newNode) {
		newNode->data = data;   // 设置节点数据
		newNode->lchild = NULL; // 初始化左子节点为空
		newNode->rchild = NULL; // 初始化右子节点为空
	}
	return newNode; // 返回新创建的节点
}

// 将节点插入到二叉树中
BiTree insert(BiTree root, int data) {
	// 如果当前树为空，创建并返回新的节点
	if (root == NULL) {
		return createNode(data);
	}
	// 根据数据大小决定插入到左子树还是右子树
	if (data < root->data) {
		root->lchild = insert(root->lchild, data); // 插入左子树
	} else {
		root->rchild = insert(root->rchild, data); // 插入右子树
	}
	return root; // 返回当前树的根节点
}

// 前序遍历二叉树
void preOrder(BiTree root) {
	// 如果当前节点不为空，打印数据并遍历子树
	if (root != NULL) {
		printf("%d ", root->data); // 打印当前节点的数据
		preOrder(root->lchild);     // 遍历左子树
		preOrder(root->rchild);     // 遍历右子树
	}
}

// 释放二叉树的内存
void freeTree(BiTree root) {
	// 如果当前节点不为空，递归释放左右子树和当前节点
	if (root != NULL) {
		freeTree(root->lchild); // 释放左子树
		freeTree(root->rchild); // 释放右子树
		free(root);             // 释放当前节点
	}
}

// 测试函数
void testBinaryTree() {
	BiTree root = NULL; // 初始化根节点为空
	int testData[] = {5, 3, 7, 2, 4, 6, 8}; // 测试数据
	int size = sizeof(testData) / sizeof(testData[0]);
	
	// 插入测试数据
	for (int i = 0; i < size; i++) {
		root = insert(root, testData[i]); // 将测试数据插入到二叉树中
	}
	
	// 前序遍历并输出结果
	printf("前序遍历结果：");
	preOrder(root); // 调用前序遍历函数
	printf("\n");
	
	// 释放内存
	freeTree(root); // 释放整个二叉树的内存
}

// 主函数
int main() {
	testBinaryTree(); // 调用测试函数
	return EXIT_SUCCESS; // 返回EXIT_SUCCESS表示程序正常结束
}

