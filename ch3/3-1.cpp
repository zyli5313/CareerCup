// Time complexity O(n). Space complexity O(1)

#include "iostream"
using namespace std;

const int MAXSTKNUM = 1000;

template<typename T>
class Stack<T>
{
private:
    T arr[];
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
            delete arr[idxTop];    
    }
    
    T Top(){ return arr[idxTop];}
    
    void Push(T t)
    {
        arr[++idxTop] = t;       
    }     
    
    T Pop()
    {
        return arr[idxTop--];    
    }
}
