#include <stdio.h>
#include <stdlib.h>

void swap(char **, char **);

int main(void)
{
  char str1[100]="This is my String.";
  char str2[100]="Another String.";

  char *p1=str1;
  char *p2=str2;

  char **a,**b;
  a=&p1;
  b=&p2;

  printf("1---Address:p1=%p,p2=%p\n",p1,p2);
  printf("Before swap:\np1:%s\np2:%s\n",p1,p2);

  swap(a,b);


  printf("4---Address:p1=%p,p2=%p\n",p1,p2);
  printf("After swap:\np1:%s\np2:%s\n",p1,p2);

  system("pause");
  return 0;
}


void swap(char **a,char **b)
{
  char *pt;
  pt=*a;
  *a=*b;
  *b=pt;
}
