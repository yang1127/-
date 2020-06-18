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

BTNode* BinaryTreeCreate(char* a, int* pi);  // ͨ��ǰ�����������"ABD##E#H##CF##G##"����������

void BinaryTreePrevOrder(BTNode* root); //ǰ�����

void BinaryTreeInOrder(BTNode* root); //�������

void BinaryTreePostOrder(BTNode* root); //�������


void TestBinaryTree();
