/*
 * Careercup 9-1
 * Author: zy li
 * WITH BUG! CANNOT RUN!
 */

#include <iostream>
#include <string>
using namespace std;

#define M 256   // string ascii encoding is between 0-255
#define N 7

typedef struct node
{
    string str;
    int hashnum;
    struct node *next;
} Node, *NodePtr;

int HashFunc(string str)
{
    int res = 0;

    for(string::iterator iter = str.begin(); iter < str.end(); iter++)
        res ^= *iter;

    return res;
}

void freeNode(NodePtr nptr)
{
    NodePtr ptemp = NULL;

    while(nptr != NULL)
    {
        ptemp = nptr;
        nptr = nptr->next;
        free(ptemp);
    }
}
NodePtr SortAnagram(string strs[N], int strnum)
{
    NodePtr *nodePtrs = (NodePtr *)calloc(M, sizeof(NodePtr));

    for(int i = 0; i < strnum; i++)
    {
        NodePtr pnode = (NodePtr)malloc(sizeof(Node));
        pnode->str = *(strs + i);
        int hn = HashFunc(strs[i]);
        pnode->hashnum = hn;
        pnode->next = NULL;

        // insert
        // first element, then init the head ptr
        if(nodePtrs[pnode->hashnum] == NULL)
            nodePtrs[pnode->hashnum] = pnode;
        else    //insert head
        {
            pnode->next = nodePtrs[pnode->hashnum];
            nodePtrs[pnode->hashnum] = pnode;
        }
    }

    // link the sorted list
    NodePtr phead = NULL, ppre = NULL, pcur = NULL;
    for(int i = 0; i < strnum; i++)
    {
        if(nodePtrs[i] != NULL)
        {
            if(phead == NULL)
                phead = nodePtrs[i];

            // links every list
            if(ppre != NULL)
                ppre->next = nodePtrs[i];

            // find the last element in the list
            pcur = nodePtrs[i];
            ppre = pcur;
            while(pcur != NULL)
            {
                ppre = pcur;
				while(pcur != NULL)
            	{
                	ppre = pcur;
                	pcur = pcur->next;
            	}
			}
        }
    }

    return phead;
}

void printList(NodePtr pnode)
{
    while(pnode != NULL)
    {
        cout << pnode->str << endl;
        pnode = pnode->next;
    }
}

int main()
{
    string s1 = "art", s2 = "music", s3 = "!@#$Asd", s4 = "tar", s5 = "heart", s6 = "rat", s7 = "earth";
    string strArr[N] = {s1, s2, s3, s4, s5, s6, s7};
    NodePtr phead = SortAnagram(strArr, N);
    printList(phead);

    return 0;
}
