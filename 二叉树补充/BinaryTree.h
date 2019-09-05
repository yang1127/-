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

BTNode* BinaryTreeCreate(char* a, int* pi);  // ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
void BinaryTreeDestory(BTNode* root); //����
int BinaryTreeSize(BTNode* root); //������
int BinaryTreeLeafSize(BTNode* root); //Ҷ�ӽ�����
int BinaryTreeLevelKSize(BTNode* root, int k); //��k��ڵ����
BTNode* BinaryTreeFind(BTNode* root, char x); //�ҵ�Ԫ��Ϊx�Ľ��

void BinaryTreePrevOrder(BTNode* root); //ǰ�����
void BinaryTreeInOrder(BTNode* root); //�������
void BinaryTreePostOrder(BTNode* root); //�������
void BinaryTreeLevelOrder(BTNode* root); // �ǵݹ�����������

bool BinaryTreeComplete(BTNode* root); // �ж϶������Ƿ�����ȫ������

void TestBinaryTree();