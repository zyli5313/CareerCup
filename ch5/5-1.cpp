// Time complexity O(nlgn). Space complexity O(n)

#include "iostream"
using namespace std;

void SetBit(int _N, int _M, int _i, int _j)
{
    int N = _N, M = _M, i = _i, j = _j;
    if(i > j)
    {
        int temp = i;
        i = j;
        j = temp;    
    }
    
    // Save lower i bits of N
    int imask = 1;    
    imask <<= i;
    
    int lowN |= imask;
        
    // Set lower j bits of N 0
    imask = 1;
    imask <<= j;
    imask &= 0xffffffff;
    
    M <<= i;
    N
}
