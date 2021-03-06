// Time complexity O(n^2). Space complexity O(1)

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
    void AppendTail(int d)
	{
		Node *end = new Node(d);
		Node *cur = this;
		while(cur->next != NULL)
			cur = cur->next;

		cur->next = end;
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
};

//int main()
//{
//    int iArr[] = {1, 3, 5, 2, 4, 9, 6, 5, 3, 1, 10, 4};
//    Node *head = new Node(iArr[0]);
//    for(int i = 1; i < sizeof(iArr) / sizeof(int); i++)
//        head->AppendTail(iArr[i]);
//
//    head->PrintList(head);
//    
//	head->RemoveDup(head);
//	head->PrintList(head);
//	head->Dispose(head);
//
//	system("pause");
//	return 0;
//}