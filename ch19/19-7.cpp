/*
 * Careercup 19-7
 * Author: zy li
 */

#include <iostream>
using namespace std;

//#define MAX(a, b, c) ((a > b ? a : b) > c ? (a > b ? a : b) : c)
#define MAX(a, b) (a > b ? a : b)

int *lsum, *asum;
/*
 * lsum(int i, int *A, int n) : the largest sum in a[i, i+1, ..., n-1] 
 * Using DP: lsum(i) = MAX{A[i]+lsum(i+1), lsum(i+1)}
 */
int largestsumNotAdjcent(int *A, int n)
{
    lsum = (int *)calloc(n, sizeof(int));
    lsum[n - 1] = A[n - 1]; // initilization

    for(int i = n - 2; i >= 0; i--)
    {
        lsum[i] = MAX(A[i] + lsum[i + 1], lsum[i + 1]);
        if(lsum[i] < A[i])
            lsum[i] = A[i];
    }

    return lsum[0];
}


/*
 * largestsumAdjacent: find the largest subsum in adjacent element squence
 *  Using DP: asum[i] = MAX(A[i]+asum[i+1], 0)
 */
int largestsumAdjacent(int *A, int n)
{
    asum = (int *)calloc(n, sizeof(int));
    asum[n - 1] = MAX(A[n - 1], 0);
    int max = 0;

    for(int i = n - 2; i >= 0; i--)
    {
        asum[i] = MAX(A[i] + asum[i+1], 0);
        
        if(max < asum[i])
            max = asum[i];
    }

    return max;
}

void printlsum(int n)
{
    for(int i = 0; i < n; i++)
        cout << asum[i] << " ";
    cout << endl;
}

int main()
{
    int A[] = {2, -8, 3, -2, 4, -10, 2, 4, 6, -1, 2, -3};

    cout << largestsumAdjcent(A, sizeof(A) / sizeof(int)) << endl;
    printlsum(sizeof(A) / sizeof(int));

    free(lsum);
    return 0;
}
