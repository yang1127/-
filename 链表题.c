1.ɾ�������е��ڸ���ֵ val �����нڵ㡣
https ://leetcode-cn.com/problems/remove-linked-list-elements/submissions/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL)
	{
		return NULL;
	}

	struct ListNode* cur = head;
	struct ListNode* prev = NULL;

	while (cur != NULL)
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			if (cur == head)
			{
				head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}

			free(cur);
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}
2.��תһ��������
https ://leetcode-cn.com/problems/reverse-linked-list/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
	//˼·�����Ϊ NULL<-1<-2<-3<-4<-5 ��ͷָ���next��ΪNULL����1-5�������,ȡ����ָ��
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* p1 = head;
	struct ListNode* p2 = p1->next;
	struct ListNode* p3 = p2->next;
	head->next = NULL;
	while (p2 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p3 != NULL)
		{
			p3 = p3->next;
		}
	}
	head = p1;
	return head;
}
3.����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м��㡣
https ://leetcode-cn.com/problems/middle-of-the-linked-list/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
	//˼·��ʹ�ÿ���ָ�룬����ָ�뿪ʼ����headλ�ã���ָ����һ������ָ��������
	//����ָ��Ϊ�ա�����fast��next��ָ���ʱ����slow��λ��ֵ��Ϊ�м��㡣
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
4.����һ����������������е�����k����㡣
https ://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		//˼·��ʹ�ÿ���ָ�룬��ָ������k�����ٿ���ָ��һ���ߣ�����ָ��Ϊ�յ�ʱ�򷵻ص���ָ�뼴Ϊ����ֵ
		struct ListNode* slow = pListHead;
		struct ListNode* fast = slow;
		while (k--)
		{
			if (fast == NULL)
			{
				return NULL;
			}
			else
			{
				fast = fast->next;
			}
		}

		while (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};
5.��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
https ://leetcode-cn.com/problems/merge-two-sorted-lists/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{

	//˼·����l1(l2)����Ϊ�գ���������Ϊl2(l1);�����������Ϊ�գ���l1�ĵ�һ�������l2�ĵ�һ�����Ƚ�
	//˭С�ŵ��������У���ȵĻ����η��룬��l2�ĵ�һ����l1�ڶ����ıȽ�������ȥ
	//�ĸ��������ꡢ����һ������ʣ��ֵ���ӵ��µ�������

	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	Node* head = NULL;
	Node* tail = NULL;
	if (l1->val < l2->val)
	{
		head = l1;
		l1 = l1->next;
	}
	else
	{
		head = l2;
		l2 = l2->next;
	}

	tail = head;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	if (l1 != NULL)
		tail->next = l1;

	if (l2 != NULL)
		tail->next = l2;

	return head;
}
6.��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ ��
https ://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		if (pHead == NULL)
		{
			return NULL;
		}
		//������������һ��С�ģ�һ���ϴ�ģ�����������ͷ�����Ϊ��
		struct ListNode* lessHead, *lessTail;
		struct ListNode* greaterHead, *greaterTail;
		//���ٿռ�
		lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* cur = pHead;
		while (cur != NULL)
		{
			if (cur->val < x)
			{
				lessTail->next = cur;
				lessTail = cur;
				cur = cur->next;
			}
			else
			{
				greaterTail->next = cur;
				greaterTail = cur;
				cur = cur->next;
			}
		}

		lessTail->next = greaterHead->next; //�������������
		greaterTail->next = NULL;

		pHead = lessHead->next;
		free(lessHead); //�ͷŵ��������ͷ���ս��
		free(greaterHead);

		return pHead;
	}
};
7.��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
https ://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		//���������ӦΪ˳������
	   //˼·����Ϊ���������ֻ��һ�����ʱ���ظ����������������������Ͻ���ٱȽ�
	   //������ָ�� prev = NULL�� cur = pHead�� pnext = cur->next ÿ�ε�next != NULLʱ�����ж�
	   //���cur->val == next->valʱ��ɾ�����ظ�Ԫ�أ�else ��������

		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		struct ListNode* prev = NULL;
		struct ListNode* cur = pHead;
		struct ListNode* pnext = cur->next;

		while (pnext != NULL)
		{
			if (cur->val == pnext->val)
			{
				while (pnext != NULL && cur->val == pnext->val) //���ظ�Ԫ��
				{
					pnext = pnext->next;
				}

				if (prev != NULL)
				{
					prev->next = pnext; //��ȥ�ظ�Ԫ�غ�
				}
				else
				{
					prev = pHead; //������ͷΪ�ظ�Ԫ��ʱ
				}

				while (cur != pnext) //ɾ�����ظ�Ԫ��,ֱ��cur=nextָ��λ��ʱ�����������ظ�Ԫ��ɾ��
				{
					struct ListNode* tmp = cur;
					cur = cur->next;
					free(tmp);
				}
				cur = pnext; //����

				while (prev != NULL) //��ʱnext��prev��cur ��ָ��һ�� ǡ�ظ�Ԫ��������β�����������֮��next = next->next��������
				{
					pnext = pnext->next;
				}
			}

			else
			{
				prev = cur;
				cur = pnext;
				pnext = pnext->next;
			}
		}
	}
};
8.����Ļ��Ľṹ��
https ://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/

class PalindromeList {
public:
	struct ListNode* reverseList(struct ListNode* head)
	{
		//˼·�����Ϊ NULL<-1<-2<-3<-4<-5 ��ͷָ���next��ΪNULL����1-5�������,ȡ����ָ��
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		struct ListNode* p1 = head;
		struct ListNode* p2 = p1->next;
		struct ListNode* p3 = p2->next;
		head->next = NULL;
		while (p2 != NULL)
		{
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			if (p3 != NULL)
			{
				p3 = p3->next;
			}
		}
		head = p1;
		return head;
	}

	bool chkPalindrome(ListNode* A)
	{
		//˼·�����������Ϊ���������֣���Ҫ�ҵ��м��㣬ʹ�ÿ���ָ�룻�Ұ벿����ת�����ж����������Ƿ����

		struct ListNode* slow = A;
		struct ListNode* fast = A;

		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		struct ListNode* leftlist = A;
		struct ListNode* rightlist = slow->next;
		slow->next = NULL;  //�����ҷֿ�

		rightlist = reverseList(rightlist);

		while (rightlist != NULL)  //����
		{
			if (leftlist->val != rightlist->val)
				return false;
			else
			{
				leftlist = leftlist->next;
				rightlist = rightlist->next;
			}
		}
		return true;
	}
};
9.�������������ҳ����ǵĵ�һ��������㡣
https ://leetcode-cn.com/problems/intersection-of-two-linked-lists/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	//Ҫ�������������û�н��㣬���� null���ڷ��ؽ���������������뱣��ԭ�еĽṹ���ɼٶ���������ṹ��û��ѭ�������������� O(n) ʱ�临�Ӷȣ��ҽ��� O(1) �ڴ档
	//˼·��(1)�ȱ���A��B���ҵ�β�����಻�ཻ��ͬʱ�����A��B�ĳ��ȣ�(2)|A-B|�Ĳ�ֵ����������|A-B|��A��B��ͬʱ��������һ����ȵļ�Ϊ��һ�����

	if (headA == NULL || headB == NULL) //��������������һ��Ϊ�գ��򲻻��ཻ
		return NULL;

	struct ListNode* curA = headA;
	struct ListNode* curB = headB;
	int lengthA = 0, lengthB = 0;
	while (curA->next != NULL)  //β��Ϊ��
	{
		curA = curA->next;
		++lengthA;
	}
	while (curB->next != NULL)  //β��Ϊ��
	{
		curB = curB->next;
		++lengthB;
	}
	if (curA != curB)  //�ж�β�Ƿ����
	{
		return NULL;
	}
	//����������
	struct ListNode* longL = headA;
	struct ListNode* shortL = headB;
	if (lengthB > lengthA)
	{
		longL = headB;
		shortL = headA;
	}
	int gap = abs(lengthA - lengthB); //���������ֵ
	while (gap--)
	{
		longL = longL->next;
	}
	while (longL != shortL)
	{
		longL = longL->next;
		shortL = shortL->next;
	}
	return longL;
}
10.����һ�������ж��������Ƿ��л���
https ://leetcode-cn.com/problems/linked-list-cycle/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
bool hasCycle(struct ListNode *head) {
	//˼·��ʹ�ÿ���ָ�룬����һ������������������׷���������л�

	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
			return true;

	}
	return false;

}


11.����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL��
����meetֵ
https ://leetcode-cn.com/problems/linked-list-cycle-ii/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
ListNode* hasCycle(struct ListNode *head) {
	//˼·��ʹ�ÿ���ָ�룬����һ������������������׷���������л�

	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
			return slow;

	}
	return NULL;

}

struct ListNode *detectCycle(struct ListNode *head) {
	//˼·�����ж��Ƿ��л�������meet

	ListNode* meet = hasCycle(head);
	if (meet == NULL)
		return NULL;

	while (meet != head)  //����ȵĻ���������
	{
		meet = meet->next;
		head = head->next;
	}
	return meet;  //����򷵻�meet
}
12. ����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣Ҫ�󷵻�����������ȿ�����
https ://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/

Node* BuyNode(int val)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	node->random = NULL;

	return node;
}

class Solution {
public:
	Node* copyRandomList(Node* head) {

		//˼·���������롢��random����⡪������

		//����������
		Node* cur = head;
		while (cur != NULL)  //����ԭ����
		{
			Node* next = cur->next;  //ԭ���<->ָ���½��<->��һ��ԭ���  �Ȱ�ԭ������һ����㱣��
			Node* copynode = BuyNode(cur->val); //�½��
			cur->next = copynode; //ԭ���<->ָ���½��
			copynode->next = next; //�½��<->��һ��ԭ���

			cur = next; //����
		}

		// ��random
		cur = head;
		while (cur)
		{
			Node* cpnode = cur->next;

			if (cur->random) //��random
				cpnode->random = cur->random->next;


			cur = cur->next->next; //����
		}

		// ���-����
		Node* cphead = BuyNode(0);
		Node* cptail = cphead;

		cur = head;
		while (cur)
		{
			Node* cpnode = cur->next;
			Node* next = cur->next->next;

			cur->next = next; //���

			cptail->next = cpnode; //����
			cptail = cpnode;

			cur = next; //����
		}

		Node* cplist = cphead->next;
		free(cphead);

		return cplist;
	}
};