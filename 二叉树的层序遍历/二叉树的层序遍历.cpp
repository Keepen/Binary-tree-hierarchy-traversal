#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct Tree {
	char val;
	struct Tree* left;
	struct Tree* right;
}Tree;


//创建结点
Tree* createNode(char val) {
	Tree* node = (Tree*)malloc(sizeof(Tree));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//对二叉树进行层序遍历
void levOrder(Tree* root) {
	
	if (root == NULL) {
		return;
	}
	//根结点入队
	//打印根节点，根节点出队
	//根节点的左右非空孩子入队
	std::queue <Tree*> queue;
	queue.push(root);
	while (!queue.empty()) {
		Tree* front = queue.front();
		queue.pop();
		printf("%c  ", front->val);
		if (front->left) {
			queue.push(front->left);
		}
		if (front->right) {
			queue.push(front->right);
		}
	}
}

//判断二叉树是否是完全二叉树
bool isComplete(Tree* root) {
	//将空结点也入队，最后判断队内有没有非空元素即可，
	std::queue <Tree*> q;
	q.push(root);
	while (true) {
		Tree* front = q.front();
		q.pop();
		//如果队首第一次为空，就退出循环
		if (front == NULL) {
			break;
		}
		//将空结点也入队
		q.push(front->left);
		q.push(front->right);
	}
	//将队内进的空结点出队，判断是否还有没有非空结点
	//若有，则表明不是完全二叉树
	//没有，则表明是完全二叉树
	while (!q.empty()) {
		Tree* front = q.front();
		q.pop();
		if (front != NULL) {
			return false;
		}
	}
	return true;
}

void test() {
	//创建二叉树
	Tree* a = createNode('A');
	Tree* b = createNode('B');
	Tree* c = createNode('C');
	Tree* d = createNode('D');
	Tree* e = createNode('E');
	Tree* f = createNode('F');
	Tree* g = createNode('G');

	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->left = f; c->right = g;
	//levOrder(a);
	bool key = isComplete(a);
	if (key==true) {
		printf("是完全二叉树！！！\n");
	}
	else {
		printf("不是完全二叉树！！！\n");
	}
}

int main() {
	test();
	system("pause");
	return 0;
}