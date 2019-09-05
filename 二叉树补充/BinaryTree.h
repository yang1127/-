#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(char* a, int* pi);  // 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
void BinaryTreeDestory(BTNode* root); //销毁
int BinaryTreeSize(BTNode* root); //结点个数
int BinaryTreeLeafSize(BTNode* root); //叶子结点个数
int BinaryTreeLevelKSize(BTNode* root, int k); //第k层节点个数
BTNode* BinaryTreeFind(BTNode* root, char x); //找到元素为x的结点

void BinaryTreePrevOrder(BTNode* root); //前序遍历
void BinaryTreeInOrder(BTNode* root); //中序遍历
void BinaryTreePostOrder(BTNode* root); //后序遍历
void BinaryTreeLevelOrder(BTNode* root); // 非递归遍历层序遍历

bool BinaryTreeComplete(BTNode* root); // 判断二叉树是否是完全二叉树

void TestBinaryTree();