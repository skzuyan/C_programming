/*
experiment no 9 Wap to print the elements of an array 
in reverse order using pointers in c programming 
Name : zuyan shaikh
Div :  D
Roll no : 62
UIN : 241P133
Branch : Computer engineering 
*/#include <stdio.h>

struct student_record {
char name[50];
int roll_number;
float total_marks;
};

int main() {
 struct student_record students[5], topper;
 int i;
printf("\t\t\t***Toper Finder***\n\n");
 // Taking User Input
printf("Enter details of 5 students :\n");
for (i = 0; i < 5; i++) {
 printf("\nStudent %d \n", i + 1);

printf("Name\t\t: ");
 scanf("%s", students[i].name);
 printf("Roll Number\t: ");
scanf("%d", &students[i].roll_number);
 printf("Total Marks\t: ");
 scanf("%f", &students[i].total_marks);
 }
 
topper = students[0];

 // Find the student with the highest marks
 for (i = 1; i < 5; i++) {
 if (students[i].total_marks > topper.total_marks) {
 topper = students[i];
 }
}

// Display the topper's details

printf("\nTopper\n");
 printf("Name\t\t: %s\n", topper.name);
 printf("Roll Number\t: %d\n", topper.roll_number);
 printf("Total Marks\t: %.2f\n", topper.total_marks);

return 0;
}
/* Output
 ***Toper Finder***

Enter details of 5 students :

 Student 1
 Name : Fahad
 Roll Number : 9
Total Marks : 92

 Student 2
Name : Piyush
 Roll Number : 54
Total Marks : 87

 Student 3
 Name : Akash
Roll Number : 30
Total Marks : 50

Student 4
 Name : Sanjana
 Roll Number : 12
Total Marks : 75

Student 5
 Name : zaid
 Roll Number : 33
Total Marks : 45



Topper
85 Name : Fahad
86 Roll Number : 9
Total Marks : 92.00 
*/