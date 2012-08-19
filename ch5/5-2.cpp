/*
 * Careercup 5-2
 */

#include <iostream>
#include <string>
using namespace std;

#define M 32

void printbin(int x, char *bstr)
{
    char *stemp = (char *)malloc(M);
    char *stempcp = stemp, *bstrcp = bstr;
    int quo = x, rem;
    
    while(quo != 0)
    {
        rem = quo % 2;
        if(rem)
            *stempcp++ = '1';
        else
            *stempcp++ = '0';
    
        quo >>= 1;
    }
    stempcp = '\0';

    // revert the str
    for(int j = strlen(stemp) - 1; j >= 0; j--)
        *bstrcp++ = stemp[j];
    bstrcp = '\0';
    
}


void d2b(char *dstr)
{
    // the total len of returned str is M. Return false if longer than len M
    char *intestr = (char *)malloc(M);
    char *fracstr = (char *)malloc(M);
    
    char *dstrcp = (char *)malloc(strlen(dstr));
    memcpy(dstrcp, dstr, strlen(dstr));
    char *dpoint = index(dstrcp, '.');
    *dpoint = '\0';

    int inte = atoi(dstrcp);
    printbin(inte, intestr);

    int frac = atoi(dpoint + 1);
    printbin(frac, fracstr);

    if(strlen(intestr) + strlen(fracstr) >= M - 2)
        cout << "ERROR" << endl;
    else
        cout <<  strcat(strcat(intestr, "."), fracstr) << endl;
}

int main()
{
    char str[] = "3.72";
    d2b(str);
    return 0;
}


