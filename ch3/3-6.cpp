// Time complexity O(n^2). Space complexity O(n)

#include "iostream"
using namespace std;
#define NUL 0x7fffffff;
//const int NUL = 0x7fffffff;
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
    
    int Size()
    {
        return idxTop + 1;        
    }
    
    bool IsEmpty()
    {
        return idxTop == -1 ? true : false;    
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
			return NUL;
    }        
    
    virtual T Top()
    {
        if(idxTop > -1)
			return arr[idxTop];  
		else
			return NUL;
    }
};

template<typename T>
Stack<T>& StackSort(Stack<T> &s)
{
    Stack<T> *pres = new Stack<T>();
    
    while(!s.IsEmpty())
    {
        T t = s.Pop();
        while(!pres->IsEmpty() && pres->Top() < t)
            s.Push(pres->Pop());
        pres->Push(t);                   
    }
    
    delete &s;
    return *pres;
}

int main()
{
    //MyQueue<int> *pQueue = new MyQueue<int>();   
    Stack<int> stk; 
    int iArr[] = {11, 3, 5, 2, 9, 10, 1};
	for(int i = 0; i < sizeof(iArr) / sizeof(int); i++)
		stk.Push(iArr[i]);
	
	stk = StackSort<int>(stk);
	
	while(!stk.IsEmpty())
    {
        int res = stk.Pop();
	    cout << res << " ";
    }
	cout << endl;
	
	system("pause");
	return 0;
}
