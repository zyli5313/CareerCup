/*
 * Careercup 8-7
 * Author: zy li
 * Time complexity: O(n!). Space complexity: O(n!)
 */

#include <iostream>
using namespace std;

#define M 100
#define QUA 25
#define DIM 10
#define NIK 5
#define PEN 1

int repArr[M];


void RepNCents(int idx, int rem)
{
    if(rem == 0)
    {
        for(int i = 0; i < idx; i++)
            printf("%d ", repArr[i]);
        printf("\n");
        return;
    }
    else if(rem < 0)
        return;

    if(rem >= QUA)
    {
        repArr[idx] = QUA;
        RepNCents(idx + 1, rem - QUA);
    }
    if(rem >= DIM)
    {
        repArr[idx] = DIM;
        RepNCents(idx + 1, rem - DIM);
    }
    if(rem >= NIK)
    {
        repArr[idx] = NIK;
        RepNCents(idx + 1, rem - NIK);
    }
    if(rem >= PEN)
    {
        repArr[idx] = PEN;
        RepNCents(idx + 1, rem - PEN);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage %s <n cents>\n", argv[0]);
        exit(-1);
    }    
    
    RepNCents(0, atoi(argv[1]));
}
