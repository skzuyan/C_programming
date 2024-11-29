/*
experiment no 10 b :  Wap to print the elements of an array 
in reverse order using pointers in c programming 
Name : zuyan shaikh
Div :  D
Roll no : 62
UIN : 241P133
Branch : Computer engineering 
*/
#include <stdio.h>

void printArrayInReverse(int *arr, int size) {
    int *ptr = arr + size - 1;  

    printf("Array in reverse order:\n");
    for (int i = size; i > 0; i--) {
        printf("%d ", *ptr);  
        ptr--;             
    }
}

int main() {
    int a;
 // size of elements 
    printf("Enter the size of the array: ");
    scanf("%d", &a);
    // enter elements 
    int arr[a];
    printf("Enter %d elements of the array:\n", a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
    }

    printArrayInReverse(arr, a);

    return 0;
}

/* Output 

Enter the size of the array: 5
Enter 5 elements of the array:
1 2 3 4 5
Array in reverse order:
5 4 3 2 1

*/
