// Time complexity O(1). Space complexity O(n)

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
};

template<typename T>
class MyQueue
{
private:
    Stack<T> *s1, *s2;
public:
    MyQueue()
    {
        s1 = new Stack<T>();
        s2 = new Stack<T>();    
    }
    ~MyQueue()
    {
        delete s1;
        delete s2;    
    }
    
    void Inqueue(T t)
    {
        s1->Push(t);    
    }
    
    T Dequeue()
    {
        if(s2->IsEmpty())        
            while(!s1->IsEmpty())
            {
                T t = s1->Pop();
                s2->Push(t);
            }
        
        if(!s2->IsEmpty())
            return s2->Pop();
        // in case of NULL or empty Queue
        else
            return NUL;
    }
    
    bool IsEmpty()
    {
        return s1->IsEmpty() && s2->IsEmpty();    
    }
};

int main()
{
    MyQueue<int> *pQueue = new MyQueue<int>();    
    int iArr[] = {11, 3, 5, 2, 9, 10, 1};
	for(int i = 0; i < sizeof(iArr) / sizeof(int); i++)
		pQueue->Inqueue(iArr[i]);
	
	while(!pQueue->IsEmpty())
    {
        int res = pQueue->Dequeue();
	    cout << res << " ";
    }
	cout << endl;
	
	system("pause");
	return 0;
}
