#include <stdio.h>
#include <stdlib.h>

// 定义线索二叉树节点结构
typedef struct ThreadedBiTNode {
	int data;                          // 节点的数据
	struct ThreadedBiTNode *lchild;    // 左子节点指针
	struct ThreadedBiTNode *rchild;    // 右子节点指针
	int ltag, rtag;                    // 左右标记 (0表示指向子树，1表示指向前驱/后继)
} ThreadedBiTNode, *ThreadedBiTree;

// 创建一个新的节点
ThreadedBiTNode* createThreadedNode(int data) {
	ThreadedBiTNode* newNode = (ThreadedBiTNode*)malloc(sizeof(ThreadedBiTNode));
	if (newNode) {
		newNode->data = data;   // 设置节点数据
		newNode->lchild = NULL; // 初始化左子节点为空
		newNode->rchild = NULL; // 初始化右子节点为空
		newNode->ltag = 0;      // 初始化左标志为0
		newNode->rtag = 0;      // 初始化右标志为0
	}
	return newNode; // 返回新创建的节点
}

// 将节点插入到二叉树中
ThreadedBiTree insert(ThreadedBiTree root, int data) {
	if (root == NULL) {
		return createThreadedNode(data);
	}
	if (data < root->data) {
		root->lchild = insert(root->lchild, data);
	} else {
		root->rchild = insert(root->rchild, data);
	}
	return root;
}

// 中序线索化过程
ThreadedBiTNode* pre = NULL; // 用于记录前一个访问的节点

void inOrderThreading(ThreadedBiTNode* root) {
	if (root != NULL) {
		inOrderThreading(root->lchild); // 递归遍历左子树
		
		// 处理当前节点
		if (root->lchild == NULL) {
			root->ltag = 1; // 将左标志置为1，表示指向前驱
			root->lchild = pre; // 左指针指向前驱
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->rtag = 1; // 将右标志置为1，表示指向后继
			pre->rchild = root; // 右指针指向后继
		}
		pre = root; // 更新前节点为当前节点
		
		inOrderThreading(root->rchild); // 递归遍历右子树
	}
}

// 打印中序线索化后的二叉树
void printInOrderThreaded(ThreadedBiTNode* root) {
	ThreadedBiTNode* p = root;
	// 找到最左节点
	while (p && p->ltag == 0) {
		p = p->lchild;
	}
	
	while (p != NULL) {
		printf("%d ", p->data); // 打印节点数据
		// 如果右指针是线索，直接访问后继
		if (p->rtag == 1) {
			p = p->rchild; // 跳转到后继
		} else {
			p = p->rchild; // 否则跳转到右子树
			while (p && p->ltag == 0) {
				p = p->lchild; // 找到最左节点
			}
		}
	}
}

// 释放线索二叉树的内存
void freeThreadedTree(ThreadedBiTNode* root) {
	// 由于是线索树，释放内存可以简单释放原节点
	free(root); // 这里假设是树的所有节点均为手动管理，实际情况需要对每个节点进行释放
}

// 主函数
int main() {
	ThreadedBiTree root = NULL; // 初始化根节点为空
	
	// 测试数据
	int testData[] = {5, 3, 7, 2, 4, 6, 8};
	int size = sizeof(testData) / sizeof(testData[0]);
	
	// 插入测试数据
	for (int i = 0; i < size; i++) {
		root = insert(root, testData[i]);
	}
	
	// 中序线索化
	inOrderThreading(root);
	
	// 打印线索化后的树
	printf("中序线索化后的遍历结果：");
	printInOrderThreaded(root);
	printf("\n");
	
	// 释放内存 (这里只是示例，实际上需要遍历每个节点释放)
	freeThreadedTree(root);
	
	return EXIT_SUCCESS; // 返回EXIT_SUCCESS表示程序正常结束
}

