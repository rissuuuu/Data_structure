#include <stdio.h>
int main()
{
   int a;
   int* p;
   p=&a;
   a=5;
   printf("%d\n",p);
   printf("%d\n",&a);
   printf("%d\n",&p);
   printf("%d",*p);
}
