// Time complexity O(n). Space complexity O(1)

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
	int GetData(){ return data; }
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
			free(head);
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

	void MakeLoop(int loopNo)
	{
		//int loopNo = 3;
		Node *pNode = this, *pEnd = this, *pSave;
		while(pEnd->next != NULL)
			pEnd = pEnd->next;

		for(int i = 0; i < loopNo && pNode != NULL && pNode->next != pEnd; i++)
			pNode = pNode->next;
		pSave = pNode;				

		pEnd->next = pSave;
	}

	Node* GetLoopEntryNode(Node *head)
	{
		if(head == NULL || head->next == NULL || head->next->next == NULL)
			return NULL;
				
		// first meet
		Node *pStep1 = head->next, *pStep2 = head->next->next;
		while(pStep1 != pStep2)
		{
			pStep1 = pStep1->next;
			pStep2 = pStep2->next->next;
		}

		// move pStep1 to head. Move pointer pStep1 and pStep2 one step every time. 
		// the second meet node is the loop entry node
		pStep1 = head;
		while(pStep1 != pStep2)
		{
			pStep1 = pStep1->next;
			pStep2 = pStep2->next;
		}

		return pStep1;
	}
};

int main()
{
    int loopNo = 0;
	//int iArr[] = {1, 3, 5, 2, 9, 10, 7, 11, 1};
	int iArr[] = {1, 3};
    Node *head = new Node(iArr[0]);
    for(int i = 1; i < sizeof(iArr) / sizeof(int); i++)
        head->AppendTail(iArr[i]);	

    head->PrintList(head);   		
	head->MakeLoop(loopNo);
	Node *pLoopNode = head->GetLoopEntryNode(head);
	cout << pLoopNode->GetData() << endl;

	//head->Dispose(head);	

	system("pause");
	return 0;
}