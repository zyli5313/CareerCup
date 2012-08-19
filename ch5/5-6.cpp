/*
 * Careercup 5-6
 * Author: zy li
 */

#include <iostream>
#include <string>
using namespace std;

unsigned swapOE(unsigned x)
{
    unsigned xl = (x & 0xaaaaaaaa) >> 1, xr = (x & 0x55555555) << 1;
    return xl | xr;
}

int main()
{
    unsigned res = swapOE(9u);
    cout << res << endl;

    return 0;
}


