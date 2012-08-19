// Time complexity O(n). Space complexity O(1)

#include "stdafx.h"
#include "iostream"
using namespace std;

const int MAXSTKNUM = 5;
const int MAXBASEARR = 100;

template<typename T>
class Stack
{
protected:
    T *arr;
    int idxTop;
public:
    Stack()
    {
        arr = new T[MAXSTKNUM];
        idxTop = -1;    
    }    
    ~Stack()
    {
        while(idxTop-- >= 0)
            delete &arr[idxTop];    
    }
    
    T Top()
	{ 
		if(idxTop > -1)
			return arr[idxTop];
		else 
			return NULL;
	}
    
    virtual bool Push(T t)
    {
		bool res = true;
		if(idxTop < MAXSTKNUM - 1)
			arr[++idxTop] = t;   
		else
			res = false;
		return res;
    }   			
    
    virtual T Pop()
    {
		if(idxTop > -1)
			return arr[idxTop--];  
		else
			return NULL;
    }

	virtual void PrintStack()
	{
		T t;
		while((t = Pop()) != NULL)
			cout << t << " ";
		cout << endl;
	}
};

template<typename T>
class SetOfStacks : public Stack<T>
{
private:	
	int idxStk;
	T *baseArr[MAXBASEARR];
public:
	SetOfStacks() : Stack()	{
		//baseArr[] = new int[MAXBASEARR];
		idxStk = -1;
		baseArr[++idxStk] = arr;
	}

	bool Push(T t)
	{
		bool res = true;
				
		if(idxTop < MAXSTKNUM - 1)
			baseArr[idxStk][++idxTop] = t;   
		// Advance index of stack and allocate memory if the current stack is full
		else if(idxTop == MAXSTKNUM - 1 && idxStk < MAXBASEARR - 1)
		{			
			baseArr[++idxStk] = new int[MAXSTKNUM];
			idxTop = -1;
			baseArr[idxStk][++idxTop] = t;
		}
		// All stacks are full
		else
			res = false;

		return res;
	}

	T Pop()
	{		
		if(idxTop > -1)
			return baseArr[idxStk][idxTop--];
		// Go back to the previous stack
		else if(idxTop == -1 && idxStk > 0)
		{
			delete[] baseArr[idxStk--];
			idxTop = MAXSTKNUM - 1;
			return baseArr[idxStk][idxTop--];
		}
		// All stacks are empty
		else
			return NULL;
	}

	T PopAt(int idxS)
	{
		T ret;

		if(idxS > idxStk)
			return NULL;
		else if(idxS == idxStk)
			ret = baseArr[idxS][idxTop--];
		else
		{
			ret = baseArr[idxS][MAXSTKNUM - 1];

			// Adjust the remaining stacks, making them maintaining the property of SetOfStacks
			for(int i = idxS + 1; i <= idxStk; i++)
			{
				int maxj = (idxStk == i) ? idxTop : MAXSTKNUM - 1;
				
				for(int j = 0; j <= maxj; j++)
				{
					if(j == 0)
						baseArr[i - 1][MAXSTKNUM - 1] = baseArr[i][j];
					else
						baseArr[i][j - 1] = baseArr[i][j];
				}
			}
			idxTop--;
			if(idxTop == -1)
			{
				idxTop = MAXSTKNUM - 1;
				idxStk--;
			}
		}		

		
		return ret;
	}	
};

int main()
{
	SetOfStacks<int> *piStk = new SetOfStacks<int>();
	int iArr[] = {11, 3, 5, 2, 9, 10, 1, 20, 22, 23, 15, 16, 13, 10, 1, 41};
	for(int i = 0; i < sizeof(iArr) / sizeof(int); i++)
		piStk->Push(iArr[i]);

	cout << "Pop from No 2 stack: " << piStk->PopAt(1) << endl;
	cout << "Pop from No 3 stack: " << piStk->PopAt(2) << endl;
	piStk->PrintStack();

	system("pause");
	return 0;
}
