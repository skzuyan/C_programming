/*
experiment no 8.1:  Wap to print the elements of an array 
in reverse order using pointers in c programming 
Name : zuyan shaikh
Div :  D
Roll no : 62
UIN : 241P133
Branch : Computer engineering 
*/

#include <stdio.h>

int main() {
    //Define Character Array
    char name [30];
    int length=0;


    printf("Enter String:");
    gets(name);

    // Find length
    while(name[length]!='0') {
        length++;
    }
    printf("Length of String is %d",&length);


    return 0;
}