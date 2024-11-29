/*
experiment no 8.2:  Wap to print the elements of an array 
in reverse order using pointers in c programming 
Name : zuyan shaikh
Div :  D
Roll no : 62
UIN : 241P133
Branch : Computer engineering 
*/

#include<stdio.h>

  int main (){
 char str[100];
int start, end, isPalindrome = 1;

// Ask the user for the string
 printf("Enter a string: ");
fgets(str, sizeof(str), stdin); // Read string with spaces

// Find the length if the string by calculating the index of the null terminator
for (end = 0; str[end] !='\n'; end++){
// Do nothing, just find the length
 }

 // Adjust the end index to exclude the newline character if it exists
 if (str[end-1] == '\n'){
 str[end-1] = '\0';
end--; // Adjust the length accordignly
 }
 
 // Check if the string is a palindrome
for (start = 0; start < end / 2; start++){
 if (str[start] != str[end - start - 1]){
 isPalindrome = 0; // Set flag to 0 if characters don'T match
 break;
 }
}

 // Output the result
 if (isPalindrome)
 {
  printf("The string is a palindrome.\n");
} else {
printf("The string is not a palindrome.\n");
 }

 return 0;


 } 
 /* OUTPUT

 Enter a string: madam
 
The string is a palindrome

Enter a string: hello
 The string is not a palindrome.