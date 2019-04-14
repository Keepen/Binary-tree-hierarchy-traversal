#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct Tree {
	char val;
	struct Tree* left;
	struct Tree* right;
}Tree;


//�������
Tree* createNode(char val) {
	Tree* node = (Tree*)malloc(sizeof(Tree));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//�Զ��������в������
void levOrder(Tree* root) {
	
	if (root == NULL) {
		return;
	}
	//��������
	//��ӡ���ڵ㣬���ڵ����
	//���ڵ�����ҷǿպ������
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

//�ж϶������Ƿ�����ȫ������
bool isComplete(Tree* root) {
	//���ս��Ҳ��ӣ�����ж϶�����û�зǿ�Ԫ�ؼ��ɣ�
	std::queue <Tree*> q;
	q.push(root);
	while (true) {
		Tree* front = q.front();
		q.pop();
		//������׵�һ��Ϊ�գ����˳�ѭ��
		if (front == NULL) {
			break;
		}
		//���ս��Ҳ���
		q.push(front->left);
		q.push(front->right);
	}
	//�����ڽ��Ŀս����ӣ��ж��Ƿ���û�зǿս��
	//���У������������ȫ������
	//û�У����������ȫ������
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
	//����������
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
		printf("����ȫ������������\n");
	}
	else {
		printf("������ȫ������������\n");
	}
}

int main() {
	test();
	system("pause");
	return 0;
}