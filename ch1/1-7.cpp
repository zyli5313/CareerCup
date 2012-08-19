// Time complexity O(n*m). Space complexity O(n+m)

#include "iostream"
using namespace std;

const int NROW = 4;
const int NCOL = 5;
int row0[NROW], col0[NCOL]; // store 0 elements' row and column indices

void Insert(int *iArr, int len, int idx)
{    
    int i = 0;
    while(iArr[i] != -1 && iArr[i] < idx && i < len)   i++;
    
    if(i < len && iArr[i] != idx)
    {
        for(int j = len - 1; j > i; j--)
            if(iArr[j - 1] != -1)
                iArr[j] = iArr[j - 1];
        iArr[i] = idx;
    }
}

void SetZeroRowColIdx(int iMat[][NCOL])
{
    for(int i = 0; i < NROW; i++)
        for(int j = 0; j < NCOL; j++)
            if(iMat[i][j] == 0)
            {
                Insert(row0, NROW, i);
                Insert(col0, NCOL, j);    
            }
}

void SetMat(int iMat[][NCOL])
{
    for(int i = 0; i < NROW; i++)
        if(row0[i] != -1)
        {
            for(int c = 0; c < NCOL; c++)
                iMat[row0[i]][c] = 0;    
        }
        
    for(int i = 0; i < NCOL; i++)
        if(col0[i] != -1)
        {
            for(int r = 0; r < NROW; r++)
                iMat[r][col0[i]] = 0;    
        }    
}

void PrintMat(int iMat[][NCOL])
{    
    for(int i = 0; i < NROW; i++){
        for(int j = 0; j < NCOL; j++)
            cout << iMat[i][j] << " ";    
        cout << endl;        
    }
    cout << endl;
}

int main()
{
    int iMat[][NCOL] = {{1,2,0,4,5}, {5,6,7,0,9}, {0,0,1,2,5}, {3,4,2,6,7}};
    //row0 = new int[NROW](-1);
    for(int i = 0; i < NROW; i++)
        row0[i] = -1;
    for(int i = 0; i < NCOL; i++)
        col0[i] = -1;            
    
    PrintMat(iMat);
    SetZeroRowColIdx(iMat);        
    SetMat(iMat);
    PrintMat(iMat);
    
    system("pause");
    return 0;  
}
