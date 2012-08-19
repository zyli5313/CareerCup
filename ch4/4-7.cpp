// Time complexity best:O(|t1| + |t2|), worst:O(|t1|*|t2|). Space complexity O(1)

#include "stdafx.h"
#include "iostream"
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

	// return if root2 is the subtree of root1
	bool IsSubtree(TreeNode<T> *root1, TreeNode<T> *root2)
	{
		if(root2 == NULL)
			return true;
		if(root1 == NULL)
			return false;
		
		if(root1->data == root2->data)
			return IsSubtree(root1, root2->left) && IsSubtree(root1, root2->right);
		else
			return IsSubtree(root1->left, root2) || IsSubtree(root1->right, root2);
	}
};

int main()
{
	int iArr[] = {1, 2, 5, 7, 10, 13, 15, 21, 22};
	int low = 0, high = sizeof(iArr) / sizeof(int) - 1; 
	Tree<int> *ptree = new Tree<int>();
	TreeNode<int> *proot = ptree->InitializeTree(iArr, low, high, ptree->GetRoot());
	ptree = new Tree<int>(proot);

	int iArr1[] = {13, 15, 21, 22};
	//int iArr1[] = {13, 15, 221, 223};
	low = 0, high = sizeof(iArr1) / sizeof(int) - 1; 
	Tree<int> *ptreeSub = new Tree<int>();
	proot = ptree->InitializeTree(iArr1, low, high, ptreeSub->GetRoot());
	ptreeSub = new Tree<int>(proot);   

	cout << ptree->IsSubtree(ptree->GetRoot(), ptreeSub->GetRoot()) << endl;

	system("pause");
	return 0;
}
