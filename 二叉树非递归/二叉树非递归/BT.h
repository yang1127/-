#pragma once

#include <iostream>
#include <stack>
 
using namespace std;

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(char* a, int* pi);  // 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树

void BinaryTreePrevOrder(BTNode* root); //前序遍历

void BinaryTreeInOrder(BTNode* root); //中序遍历

void BinaryTreePostOrder(BTNode* root); //后序遍历


void TestBinaryTree();
