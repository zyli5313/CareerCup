// Time complexity O(n). Space complexity O(n)

#include "stdafx.h"
#include "iostream"
using namespace std;

const int MAXINT = 0x7fffffff;
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

	TreeNode<T>* GetRoot(){ return root; }

	void SetPFlag(TreeNode<T> *pt)
	{
		pFlag = pt;
	}

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

	// return the next node in in-order traverse
	TreeNode<T>* NextNode(TreeNode<T> *pnode)
	{
		if(pnode == NULL)
			return NULL;

		if(pnode->right != NULL)
		{
			// return the right leftmost node
			TreeNode<T> *pnodeRL = pnode->right;
			while(pnodeRL->left != NULL)
				pnodeRL = pnodeRL->left;
			return pnodeRL;
		}
		else
		{
			TreeNode<T> *ppar = pnode->parent, *pcur = pnode;

			// If the node has no right child, the next node is the first parent when this node climbing up the tree as the left child			
			while(ppar != NULL && ppar->right == pcur)
			{
				pcur = ppar;
				ppar = ppar->parent;
			}

			// find the next node
			if(ppar != NULL)
				return ppar;
			// pnode is the last node of this tree
			else
				return pFlag;
		}
	}

	//int cnt = 0;
	TreeNode<T>* GetNode(TreeNode<T> *pnode, int idx, int& cnt)
	{
		if(pnode == NULL || cnt > idx)
			return NULL;

		TreeNode<T> *pnodeRet;
		pnodeRet = GetNode(pnode->left, idx, cnt);
		if(pnodeRet != NULL)
			return pnodeRet;

		if(cnt++ == idx)
			return pnode;
		pnodeRet = GetNode(pnode->right, idx, cnt);
		if(pnodeRet != NULL)
			return pnodeRet;
		else
			return NULL;
	}
};

int main()
{
	int iArr[] = {1, 2, 5, 7, 10, 13, 15, 21, 22};
	int low = 0, high = sizeof(iArr) / sizeof(int) - 1;
	int idx = 5;

	Tree<int> *ptree = new Tree<int>();
	TreeNode<int> *proot = ptree->InitializeTree(iArr, low, high, ptree->GetRoot());
	ptree = new Tree<int>(proot);
		
	// make a flag
	TreeNode<int> *pFlag = new TreeNode<int>(MAXINT);
	ptree->SetPFlag(pFlag);

	for(int i = 0; i < high + 1; i++)
	{
		int cnt = 0;
		TreeNode<int> *pnode = ptree->GetNode(ptree->GetRoot(), i, cnt);
		cout << pnode->data << " ";
		TreeNode<int> *pnext = ptree->NextNode(pnode);
		if(pnext != pFlag)
			cout << pnext->data << endl;
		// the last node
		else
			cout << "END" << endl;
	}	

	system("pause");
	return 0;
}
