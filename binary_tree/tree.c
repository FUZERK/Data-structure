#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"



void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%d", root->_data);
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%d", root->_data);
	BinaryTreeInOrder(root->_right);
}	

void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	BinaryTreeInOrder(root->_left);
	BinaryTreeInOrder(root->_right);
	printf("%d", root->_data);
}

int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}

	int size = BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);

	return size+1;
}

int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}

	if (root->_left == NULL && root->_right == NULL) {
		return 1;
	}
	int size = BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
	return size;
}



int BinaryTreeLevelKSize(BTNode* root, int k) {

	if (root == NULL) {
		return 0;
	}

	if (k==1 && root != NULL) {
		return 1;
	}
	int size = BinaryTreeLevelKSize(root->_left,k-1) + BinaryTreeLevelKSize(root->_right,k-1);

	return size;
}