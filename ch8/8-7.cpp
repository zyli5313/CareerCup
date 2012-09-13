/*
 * Careercup 8-7
 * Author: zy li
 * Time complexity: O(4^n). Space complexity: O(n)
 */

#include <iostream>
using namespace std;

#define M 100
#define QUA 25
#define DIM 10
#define NIK 5
#define PEN 1

int repArr[M];
int val[] = {QUA, DIM, NIK, PEN};

/*void RepNCents(int idx, int rem)
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
}*/
void RepNCents(int idx, int rem, int validx)
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

    for(int i = validx; i < 4; ++i)
    {
        // allow for repitition, since we have add constraint on
		// which val element can be chosen (only idx validx..3 can be chosen)
		for(int rep = 1; rep * val[i] <= rem; rep++)
        {
            for(int j = 0; j < rep; j++)
				repArr[idx+j] = val[i];
            
			RepNCents(idx + rep, rem - rep*val[i], i + 1);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage %s <n cents>\n", argv[0]);
        exit(-1);
    }    
    
    RepNCents(0, atoi(argv[1]), 0);
}
