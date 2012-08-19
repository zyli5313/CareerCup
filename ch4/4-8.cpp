// Time complexity O(nlgn). Space complexity O(n)

#include "stdafx.h"
#include "iostream"
#include "list"
using namespace std;
template<typename T>
class TreeNode
{
public:
	T data;
	TreeNode *left, *right, *parent;     
	TreeNode() { left = right = parent = NULL; }
	TreeNode(T t): data(t), left(NULL), right(NULL), parent(NULL){}
};

template<typename T>
class Tree
{
private:
	TreeNode<T> *root, *pFlag;
public:
	Tree() { root = NULL; }
	Tree(TreeNode<T> *t): root(t){}
	~Tree()
	{
		while(root != NULL)
		{
			TreeNode<T> *pnext = root->next;
			delete root;
			root = pnext;    
		}    
	}

	TreeNode<T>* GetRoot(){ return root; }

	// tArr is in ascending order
	// the result is a binary search tree	
	TreeNode<T>* InitializeTree(T *tArr, int low, int high, TreeNode<T> *pnode)
	{
		if(low > high || tArr == NULL)
			return NULL;

		int mid = low + (high - low) / 2;
		pnode = new TreeNode<T>(tArr[mid]);

		// Initialize left
		pnode->left = InitializeTree(tArr, low, mid - 1, pnode->left);
		if(pnode->left != NULL)
			pnode->left->parent = pnode;
		// Initialize right
		pnode->right = InitializeTree(tArr, mid + 1, high, pnode->right);
		if(pnode->right != NULL)
			pnode->right->parent = pnode;

		return pnode;
	}

	void PrintPre(TreeNode<T> *pnode)
	{
		if(pnode == NULL)
			return;

		cout << pnode->data << " ";
		PrintPre(pnode->left);
		PrintPre(pnode->right);		
	}

	void FindSum(TreeNode<T> *head, int sum, list<T> buffer, int level) {
		if (head == NULL)
			return;
		int tmp = sum;
		buffer.push_back(head->data);
		list<T>::const_iterator i;
		for(i = buffer.end(); i != buffer.begin(); i--)
		{
			//for (int i = level;i >- 1; i--){
			tmp -= *i;
			if (tmp == 0) 
				Print(buffer, i, level);
		}
		list<T> c1 (buffer);
		list<T> c2 (buffer);
		FindSum(head->left, sum, c1, level + 1);
		FindSum(head->right, sum, c2, level + 1);
	}

	void Print(list<T> buffer, typename list<T>::const_iterator level, int i2) {
		// bugs here
		for (list<T>::const_iterator i = level; *i <= i2; i++) {
			cout << *i << " ";
		}
		cout << endl;
	}
};

int main()
{
	int iArr[] = {-4, -3, 1, 2, 5, 7, 10, 13, 15, 21, 22};
	int sum = 5;
	int low = 0, high = sizeof(iArr) / sizeof(int) - 1; 
	Tree<int> *ptree = new Tree<int>();
	TreeNode<int> *proot = ptree->InitializeTree(iArr, low, high, ptree->GetRoot());
	ptree = new Tree<int>(proot);   

	list<int> buffer;
	ptree->FindSum(ptree->GetRoot(), sum, buffer, 0);

	system("pause");
	return 0;
}
