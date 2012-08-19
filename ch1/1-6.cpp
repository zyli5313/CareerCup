// Time complexity O(n*m). Space complexity O(1)

#include "iostream"
using namespace std;
const int COL = 5;

void Rotate(int matrix[][COL], int n) {
    for (int layer = 0; layer < n / 2; ++layer) {
     int first = layer;
     int last = n - 1 - layer;
     for(int i = first; i < last; ++i) {
      int offset = i - first;
      int top = matrix[first][i]; // save top
      // left -> top
      matrix[first][i] = matrix[last-offset][first];    
 
      // bottom -> left
      matrix[last-offset][first] = matrix[last][last - offset]; 
 
      // right -> bottom
      matrix[last][last - offset] = matrix[i][last]; 
 
      // top -> right
      matrix[i][last] = top; // right <- saved top
     }
    }
}

void PrintMat(int iMat[][COL])
{
    //int row = sizeof(&iMat[0][0]) / sizeof(iMat[0]);
    for(int i = 0; i < COL; i++){
        for(int j = 0; j < COL; j++)
            cout << iMat[i][j] << " ";    
        cout << endl;        
    }
    cout << endl;
}

int main()
{
    int iMat[][COL] = {{1,2,3,4,5}, {5,6,7,8,9}, {9,0,1,2,5}, {3,4,5,6,7}, {3,2,1,4,6}};
    
    PrintMat(iMat);
    Rotate(iMat, COL);
    PrintMat(iMat);
    
    system("pause");
    return 0; 
}


