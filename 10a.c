/*
experiment no 10 a :  Wap to print the elements of an array 
in reverse order using pointers in c programming 
Name : zuyan shaikh
Div :  D
Roll no : 62
UIN : 241P133
Branch : Computer engineering 
*/



#include<stdio.h>

int main()
{
    int a,b, sum;
    int* p=&a;
    int*q=&b;
    
    printf (" Enter a : ");
    scanf("%d",p);
    printf (" Enter b: ");
    scanf("%d",q);
    
    sum = *p+*q;
    printf("sum :%d", sum );
    
    return 0;
}
// Output 
/*
Enter a : 5
 Enter b: 13
sum :18
*/