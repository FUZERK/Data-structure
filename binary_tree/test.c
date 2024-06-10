#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"

BTNode* BuyNode(BTDataType x) {
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->_data = x;
	newnode->_left = NULL;
	newnode->_right = NULL;
	return newnode;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);


	node1->_left = node2;
	node1->_right = node3;
	node2->_left = node4;
	node2->_right = node5;
	node3->_left = node6;
	node3->_right = node7;

	return node1;
}

int main() {
	BTNode* root = CreatBinaryTree();
	printf("%d", BinaryTreeLevelKSize(root,1));
}

