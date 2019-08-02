1.删除链表中等于给定值 val 的所有节点。
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
2.反转一个单链表。
https ://leetcode-cn.com/problems/reverse-linked-list/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
	//思路：输出为 NULL<-1<-2<-3<-4<-5 将头指向的next置为NULL，将1-5链接输出,取三个指针
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
3.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
https ://leetcode-cn.com/problems/middle-of-the-linked-list/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
	//思路：使用快慢指针，快慢指针开始均在head位置，慢指针走一步、快指针走两步
	//当快指针为空、或者fast的next或指向空时返回slow的位置值即为中间结点。
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
4.输入一个链表，输出该链表中倒数第k个结点。
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
		//思路：使用快慢指针，快指针先走k步，再快慢指针一起走，当快指针为空的时候返回的慢指针即为所求值
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
5.将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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

	//思路：若l1(l2)链表为空，则新链表为l2(l1);若两链表均不为空，则l1的第一个结点与l2的第一个结点比较
	//谁小放到新链表中，相等的话依次放入，再l2的第一个与l1第二个的比较依次下去
	//哪个链表先完、把另一个链表剩余值链接到新的链表中

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
6.编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 。
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
		//建立两个链表，一个小的，一个较大的，并建立两个头结点且为空
		struct ListNode* lessHead, *lessTail;
		struct ListNode* greaterHead, *greaterTail;
		//开辟空间
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

		lessTail->next = greaterHead->next; //两链表进行链接
		greaterTail->next = NULL;

		pHead = lessHead->next;
		free(lessHead); //释放掉两链表的头，空结点
		free(greaterHead);

		return pHead;
	}
};
7.在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
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
		//该题的链表应为顺序链表
	   //思路：当为空链表或者只有一个结点时返回该链表，当有两个或两个以上结点再比较
	   //设三个指针 prev = NULL， cur = pHead， pnext = cur->next 每次当next != NULL时方可判断
	   //如果cur->val == next->val时，删除掉重复元素，else 继续遍历

		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		struct ListNode* prev = NULL;
		struct ListNode* cur = pHead;
		struct ListNode* pnext = cur->next;

		while (pnext != NULL)
		{
			if (cur->val == pnext->val)
			{
				while (pnext != NULL && cur->val == pnext->val) //找重复元素
				{
					pnext = pnext->next;
				}

				if (prev != NULL)
				{
					prev->next = pnext; //除去重复元素后
				}
				else
				{
					prev = pHead; //当链表头为重复元素时
				}

				while (cur != pnext) //删除掉重复元素,直到cur=next指针位置时，即把所有重复元素删除
				{
					struct ListNode* tmp = cur;
					cur = cur->next;
					free(tmp);
				}
				cur = pnext; //迭代

				while (prev != NULL) //此时next、prev、cur 均指向一处 恰重复元素在链表尾，则结束，反之，next = next->next继续遍历
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
8.链表的回文结构。
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
		//思路：输出为 NULL<-1<-2<-3<-4<-5 将头指向的next置为NULL，将1-5链接输出,取三个指针
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
		//思路：将链表均分为左右两部分，需要找到中间结点，使用快慢指针；右半部分逆转后，再判断这两部分是否相等

		struct ListNode* slow = A;
		struct ListNode* fast = A;

		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		struct ListNode* leftlist = A;
		struct ListNode* rightlist = slow->next;
		slow->next = NULL;  //把左右分开

		rightlist = reverseList(rightlist);

		while (rightlist != NULL)  //遍历
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
9.输入两个链表，找出它们的第一个公共结点。
https ://leetcode-cn.com/problems/intersection-of-two-linked-lists/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	//要求：如果两个链表没有交点，返回 null；在返回结果后，两个链表仍须保持原有的结构；可假定整个链表结构中没有循环；程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
	//思路：(1)先遍历A、B，找到尾，看相不相交，同时计算除A、B的长度；(2)|A-B|的差值，长的先走|A-B|，A、B再同时遍历，第一个相等的即为第一个结点

	if (headA == NULL || headB == NULL) //若两个链表其中一个为空，则不会相交
		return NULL;

	struct ListNode* curA = headA;
	struct ListNode* curB = headB;
	int lengthA = 0, lengthB = 0;
	while (curA->next != NULL)  //尾不为空
	{
		curA = curA->next;
		++lengthA;
	}
	while (curB->next != NULL)  //尾不为空
	{
		curB = curB->next;
		++lengthB;
	}
	if (curA != curB)  //判断尾是否相等
	{
		return NULL;
	}
	//两个链表长度
	struct ListNode* longL = headA;
	struct ListNode* shortL = headB;
	if (lengthB > lengthA)
	{
		longL = headB;
		shortL = headA;
	}
	int gap = abs(lengthA - lengthB); //两链表相差值
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
10.给定一个链表，判断链表中是否有环。
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
	//思路：使用快慢指针，慢走一步、快走两步、若快追上慢，则有环

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


11.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL。
返回meet值
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
	//思路：使用快慢指针，慢走一步、快走两步、若快追上慢，则有环

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
	//思路：先判断是否有环，再求meet

	ListNode* meet = hasCycle(head);
	if (meet == NULL)
		return NULL;

	while (meet != head)  //不相等的话，继续走
	{
		meet = meet->next;
		head = head->next;
	}
	return meet;  //相等则返回meet
}
12. 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深度拷贝。
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

		//思路：拷贝插入、置random、拆解——链接

		//拷贝插入结点
		Node* cur = head;
		while (cur != NULL)  //遍历原链表
		{
			Node* next = cur->next;  //原结点<->指向新结点<->下一个原结点  先把原结点的下一个结点保存
			Node* copynode = BuyNode(cur->val); //新结点
			cur->next = copynode; //原结点<->指向新结点
			copynode->next = next; //新结点<->下一个原结点

			cur = next; //迭代
		}

		// 置random
		cur = head;
		while (cur)
		{
			Node* cpnode = cur->next;

			if (cur->random) //置random
				cpnode->random = cur->random->next;


			cur = cur->next->next; //迭代
		}

		// 拆解-链接
		Node* cphead = BuyNode(0);
		Node* cptail = cphead;

		cur = head;
		while (cur)
		{
			Node* cpnode = cur->next;
			Node* next = cur->next->next;

			cur->next = next; //拆解

			cptail->next = cpnode; //链接
			cptail = cpnode;

			cur = next; //迭代
		}

		Node* cplist = cphead->next;
		free(cphead);

		return cplist;
	}
};