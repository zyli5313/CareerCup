// Time complexity O((logn)^2). Space complexity O(1)

#include "iostream"
#include "assert.h"
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
	
	TreeNode<T>* GetLowestCommonAncestor(TreeNode<T> *pnode1, TreeNode<T> *pnode2)
	{        
        if(pnode1 == root || pnode2 == root)
            return root;
            
        TreeNode<T> *pn1 = pnode1, *pn2 = pnode2;        
        // If pn2 is pn1's parent, return pn2
        while(pn1 != NULL && pn1->parent != pn2)
            pn1 = pn1->parent;
        if(pn1 != NULL)
            return pn2;
            
        pn1 = pnode1;
        // If pn1 is pn2's parent, return pn1
        while(pn2 != NULL && pn2->parent != pn1)
            pn2 = pn2->parent;
        if(pn2 != NULL)
            return pn1;
           
        // Else return LCA(n1, Parent(n2)); 
        return GetLowestCommonAncestor(pnode1, pnode2->parent);
    }
    
    //int cnt = 0; Inorder traverse
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
	int cnt = 0, idx1 = 0, idx2 = 3;

	Tree<int> *ptree = new Tree<int>();
	TreeNode<int> *proot = ptree->InitializeTree(iArr, low, high, ptree->GetRoot());
	ptree = new Tree<int>(proot);    
	
	TreeNode<int> *pnode1 = ptree->GetNode(ptree->GetRoot(), idx1, cnt);
	cout << pnode1->data << " ";
	cnt = 0;
	TreeNode<int> *pnode2 = ptree->GetNode(ptree->GetRoot(), idx2, cnt);
	cout << pnode2->data << " ";
	TreeNode<int> *pnodeComm = ptree->GetLowestCommonAncestor(pnode1, pnode2);
	cout << "LCA:"<< pnodeComm->data << endl;
	
	system("pause");
	return 0;
}
