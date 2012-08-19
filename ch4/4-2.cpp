// Time complexity O(n^2). Space complexity O(n)

#include "iostream"
using namespace std;
#define N 7
// Adjacent array( which has a loop 0-1-4-2-0)
int AdjArr[N][N] = {0, 1, 1, 1, 0, 0, 0, 
                    0, 0, 0, 0, 1, 0, 0,
                    1, 0, 0, 0, 1, 0, 0,
                    0, 0, 0, 0, 0, 1, 0,
                    0, 0, 1, 0, 0, 1, 1,
                    0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0};
int VisitedArr[N] = {0};

bool IsConnected(int i, int j)
{
    if(i >= N || j >= N || i < 0 || j < 0)
        return false;
        
    if(AdjArr[i][j] == 1)
        return true;
    
    bool bres = false;
    for(int m = 0; m < N; m++)
    {        
        // Traverse the point which is linked but not visited
        if(AdjArr[i][m] == 1 && VisitedArr[m] == 0)
        {
            VisitedArr[m] = 1;
            bres = IsConnected(m, j);   
            VisitedArr[m] = 0;
            if(bres == true)
                break; 
        }
    }
    
    return bres;
}

int main()
{
    int iA1[] = {0, 1, 3, 5, 6};
    int iA2[] = {4, 4, 4, 4, 4};
    for(int i = 0; i < sizeof(iA1) / sizeof(int); i++)
        cout << iA1[i] << " and " << iA2[i] << " : " << IsConnected(iA1[i], iA2[i]) << endl;
        
        system("pause");
        return 0;    
}
