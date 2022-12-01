/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
// #include<iomanip>

// using namespace std;

int main()
{
    int a=10,b=30,*p,s=0;
    p = &a;
    a++;
    (*p)++;
    s = a+b+ *p;
    printf("%d\n",s);
    return 0;
}
