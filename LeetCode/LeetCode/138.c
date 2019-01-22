/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     struct RandomListNode *next;
*     struct RandomListNode *random;
* };
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深度拷贝。
*/
typedef struct RandomListNode node;
struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
	if (head == NULL)
		return NULL;
	else
	{
		node* cur = head;
		while (cur)
		{   //创建新节点
			node* newnode = (node*)malloc(sizeof(node));
			newnode->label = cur->label;
			newnode->next = cur->next;
			cur->next = newnode;
			cur = newnode->next;
		}
		node* t = head;
		node* Tnext = NULL;
		while (t)
		{
			if (t->random != NULL)
			{
				Tnext = t->next;
				Tnext->random = t->random->next;
				t = Tnext->next;

			}
			else
			{
				Tnext = t->next;
				Tnext->random = t->random;
				t = Tnext->next;

			}

		}
		node* ret = head;
		node* pt = head->next;
		node* tmp = ret->next;
		while (tmp->next)
		{
			ret->next = tmp->next;
			ret = ret->next;
			tmp->next = ret->next;
			tmp = tmp->next;
		}
		ret->next = NULL;
		return pt;
	}

}
