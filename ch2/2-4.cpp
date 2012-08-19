// Time complexity O(n+m). Space complexity O(result(n+m))

#include "stdafx.h"
#include "iostream"
using namespace std;

class Node
{
private:
    Node *next;
    int data;
        
public:
    Node(int d) { data = d;   next = NULL;}
	Node(){	data = -1;	next = NULL; }
	Node* GetNext(){ return next;}
    void AppendTail(int d)
	{
		Node *end = new Node(d);
		Node *cur = this;
		while(cur->next != NULL)
			cur = cur->next;

		cur->next = end;
	}

	void AppendHead(int d, Node *head)
	{
		Node *node = new Node(d);
		node->next = head;
		head = node;
	}	
		
	void RemoveDup(Node *head)
	{
		if (head == NULL) return;
		 Node *previous = head;
		 Node *current = previous->next;

		 while (current != NULL) {
			 Node *runner = head;
			 while (runner != current) { // Check for earlier dups
				 if (runner->data == current->data) {
					 Node *tmp = current->next; // remove current
					 previous->next = tmp;
					 current = tmp; // update current to next node
					 break; // all other dups have already been removed
				 }
				runner = runner->next;
			 }
			 if (runner == current) { // current not updated - update now
				 previous = current;
				 current = current->next;
			 }
		 }
	} 

	int GetLen(Node *head)
	{
		int num = 0;
		while(head != NULL)
		{
			num++;
			head = head->next;
		}
		return num;
	}


	int GetNToLast(Node *head, int N)
	{
		int len = GetLen(head);   
		if(len == 0)
			return NULL;
		if(len < N)
			N %= len;
		Node *node = head;

		for(int i = len - N; i > 0; i--)
			node = node->next;

		return node->data;
	}

	void Delete(Node *head, int idata)
	{
		if(head == NULL)
			return;

		Node *pre, *node = head;
		while(node->data != idata && node != NULL)
		{
			pre = node;
			node = node->next;
		}

		// in case of last node in the list
		if(node->next == NULL && node->data == idata)
		{
			pre->next = NULL;
			free(node);
		}
		else if(node != NULL && node->data == idata)
		{
			pre->next = node->next;
			free(node);
		}
	}

    
	void PrintList(Node *head)
	{
		Node *node = head;
		while(node != NULL)
		{
			cout << node->data << " ";

			node = node->next;
		}
		cout << endl;
	}

	void Dispose(Node *head)
	{
		while(head != NULL)
		{
			Node *temp = head->next;
			//free(head);
			delete head;
			head = temp;
		}
	}

	int GetIntFromList(Node *head)
	{
		int result = 0, base = 1;

		while(head != NULL)
		{
			result += head->data * base;
			base *= 10;
			head = head->next;
		}
		return result;
	}

	Node* GetListFromInt(int res)
	{		
		Node *head = new Node();
		while(res != 0)
		{
			int rem = res % 10;
			head->AppendTail(rem);
			res /= 10;			
		}
		return head;
	}
		
	Node& operator + (Node &head)
	{
		Node *resHead = new Node();
		int ih1 = head.GetIntFromList(&head), ih2 = this->GetIntFromList(this);
		resHead = resHead->GetListFromInt(ih1 + ih2);
		return *resHead;
	}
};

int main()
{
    int N = 4;
	int iArr1[] = {1, 3, 5}, iArr2[] = {2, 9};
    Node *head1 = new Node(iArr1[0]);
    for(int i = 1; i < sizeof(iArr1) / sizeof(int); i++)
        head1->AppendTail(iArr1[i]);
	Node *head2 = new Node(iArr2[0]);
    for(int i = 1; i < sizeof(iArr2) / sizeof(int); i++)
        head2->AppendTail(iArr2[i]);

    head1->PrintList(head1);    	
	head2->PrintList(head2);
	
	Node resHead = *head1 + *head2;
	resHead.PrintList(resHead.GetNext());

	head1->Dispose(head1);
	head2->Dispose(head2);	
	resHead.Dispose(resHead.GetNext());

	system("pause");
	return 0;
}
