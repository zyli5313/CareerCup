// Time complexity O(n). Space complexity O(n)

#include "iostream"
#include "assert.h"
using namespace std;
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ABS(a) (a > 0 ? a : -a)

template<typename T>
class TreeNode
{
public:
	T data;
	TreeNode *left, *right;     
	TreeNode() { left = right = NULL; }
	TreeNode(T t): data(t), left(NULL), right(NULL){}
};

template<typename T>
class Tree
{
private:
	TreeNode<T> *root;
public:
	Tree() { root = NULL; }
	Tree(TreeNode<T> *t): root(t){}

	TreeNode<T>* GetRoot(){ return root; }

	bool IsBalance(TreeNode<T> *pTree, int &height)
	{
		if(pTree->left == NULL && pTree->right == NULL)
		{
			height = 0;
			return true;    
		}		
		
		int lh = 0, rh = 0;		
		bool lb = true, rb = true;
		if(pTree->left != NULL)
			lb = IsBalance(pTree->left, lh);		
		if(pTree->right != NULL)			
			rb = IsBalance(pTree->right, rh);
		if(! lb && rb )
			return false;

		height = MAX(lh + 1, rh + 1);

		return ABS(lh - rh) < 2;
	}

	// Build a tree determined by preorder and inorder.
	// lp and rp are the left bound and right bound of preOrder Array repectively. The same goes with lm and rm
	TreeNode<T>* BuildTreeUsingPreInorder(TreeNode<T> *tree, T *preArr, T *inArr, 
		int lp, int rp, int lm, int rm)
	{
		int pos;
		int len;

		tree = new TreeNode<T>();
		tree->data = preArr[lp];
		tree->left = tree->right = NULL;

		pos = lm;
		while(inArr[pos] != preArr[lp])
			pos++;

		len = pos - lm;

		if(pos > lm)
			tree->left = BuildTreeUsingPreInorder(tree->left, preArr, inArr,
			lp+1, lp+len, lm, pos-1);

		if(pos < rm)
			tree->right = BuildTreeUsingPreInorder(tree->right, preArr, inArr,
			lp+len+1, rp, pos+1, rm);

		return tree;  
	}        
};

int main()
{
	// Balanced
	int inArr[] = {4, 2, 5, 1, 6, 3};
	int preArr[] = {1, 2, 4, 5, 3, 6}; 
	// Unbalanced
	//int inArr[] = {4, 3, 5, 2, 1, 6};
	//int preArr[] = {1, 2, 3, 4, 5, 6};

	Tree<int> *root = new Tree<int>();
	TreeNode<int> *tree = new TreeNode<int>();
	tree = root->BuildTreeUsingPreInorder(tree, preArr, inArr, 
		0, sizeof(inArr)/sizeof(int) - 1, 0, sizeof(preArr)/sizeof(int) - 1);
	root = new Tree<int>(tree);

	int h;
	cout << root->IsBalance(root->GetRoot(), h) << endl;

	system("pause");
	return 0;
}
