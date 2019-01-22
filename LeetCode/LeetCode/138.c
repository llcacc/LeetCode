/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     struct RandomListNode *next;
*     struct RandomListNode *random;
* };
����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣

Ҫ�󷵻�����������ȿ�����
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
		{   //�����½ڵ�
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
