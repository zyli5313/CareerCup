// Time complexity O(n). Space complexity O(n)(worst case)

#include "stdafx.h"
#include "iostream"
using namespace std;

const int MAXSTKNUM = 1000;

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
};

template<typename T>
class StackWithMin : public Stack<T>
{
private:
	Stack<T> *minStk;
public:
	StackWithMin() : Stack()
	{
		minStk = new Stack<T>();
	}

	~StackWithMin()
	{
		while(minStk->Top() != NULL)
			delete &(minStk->Top());
	}

	bool Push(T t)
	{
		bool res = true;
		if(idxTop < MAXSTKNUM - 1)
			arr[++idxTop] = t;   
		else
			res = false;

		if(minStk->Top() == NULL || minStk->Top() != NULL && minStk->Top() > t)
			minStk->Push(t);

		return res;
	}

	T Pop()
    {
		if(arr[idxTop] == minStk->Top())
			minStk->Pop();

		if(idxTop > -1)
			return arr[idxTop--];  
		else
			return NULL;
    }

	T GetMin() { return minStk->Top();}
};

int main()
{
	StackWithMin<int> *piStk = new StackWithMin<int>();
	int iArr[] = {11, 3, 5, 2, 9, 10, 1};
	for(int i = 0; i < sizeof(iArr) / sizeof(int); i++)
		piStk->Push(iArr[i]);

	for(int i = 0; i < sizeof(iArr) / sizeof(int); i++)
	{
		cout << "MIN: " << piStk->GetMin() << endl;
		piStk->Pop();
	}

	system("pause");
	return 0;
}
