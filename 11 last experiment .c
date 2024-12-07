/*
experiment no  11:  strature to hold employee details 
Name : zuyan shaikh
Div :  D
Roll no : 62
UIN : 241P133
Branch : Computer engineering 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold employee details
struct employee {
    int id;
    char name[50];
    float salary;
};

// Function to add employee details to the file
void add_employee() {
    struct employee emp;
    FILE *file = fopen("employee_database.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    getchar(); // Clear newline left by scanf
    fgets(emp.name, sizeof(emp.name), stdin);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    // Remove newline character from name if present
    size_t len = strlen(emp.name);
    if (len > 0 && emp.name[len - 1] == '\n') {
        emp.name[len - 1] = '\0';
    }

    // Write employee data to the file
    fprintf(file, "%d %.2f %s\n", emp.id, emp.salary, emp.name);
    fclose(file);
    printf("Employee record added successfully!\n");
}

// Function to display all employee records from the file
void display_employees() {
    struct employee emp;
    FILE *file = fopen("employee_database.txt", "r");

    if (file == NULL) {
        printf("No employee records found!\n");
        return;
    }

    printf("\nEmployee Records:\n");
    printf("ID\tName\t\tSalary\n");
    printf("---------------------------------\n");

    // Read and display each employee record from the file
    while (fscanf(file, "%d %f %[^\n]", &emp.id, &emp.salary, emp.name) != EOF) {
        printf("%d\t%-15s%.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(file);
}

// Function to edit an employee record
void edit_employee() {
    int id, found = 0;
    struct employee emp;
    FILE *file = fopen("employee_database.txt", "r+");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Employee ID to edit: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %f %[^\n]", &emp.id, &emp.salary, emp.name) != EOF) {
        if (emp.id == id) {
            found = 1;
            printf("Enter new Employee Name: ");
            getchar();
            fgets(emp.name, sizeof(emp.name), stdin);
            printf("Enter new Employee Salary: ");
            scanf("%f", &emp.salary);

            // Remove newline character from name if present
            size_t len = strlen(emp.name);
            if (len > 0 && emp.name[len - 1] == '\n') {
                emp.name[len - 1] = '\0';
            }
        }
        fprintf(temp, "%d %.2f %s\n", emp.id, emp.salary, emp.name);
    }

    fclose(file);
    fclose(temp);

    remove("employee_database.txt");
    rename("temp.txt", "employee_database.txt");

    if (found) {
        printf("Employee record edited successfully!\n");
    } else {
        printf("Employee ID not found!\n");
    }
}

// Function to delete an employee record
void delete_employee() {
    int id, found = 0;
    struct employee emp;
    FILE *file = fopen("employee_database.txt", "r+");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %f %[^\n]", &emp.id, &emp.salary, emp.name) != EOF) {
        if (emp.id != id) {
            fprintf(temp, "%d %.2f %s\n", emp.id, emp.salary, emp.name);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("employee_database.txt");
    rename("temp.txt", "employee_database.txt");

    if (found) {
        printf("Employee record deleted successfully!\n");
    } else {
        printf("Employee ID not found!\n");
    }
}

int main() {
    int choice;

    printf("\t\t *** Employee Database *** \n\n");

    while (1) {
        // Menu for user
        printf("\nEmployee Database Menu:\n");
        printf("1. Add Employee Record\n");
        printf("2. Display Employee Records\n");
        printf("3. Edit Employee Record\n");
        printf("4. Delete Employee Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_employees();
                break;
            case 3:
                edit_employee();
                break;
            case 4:
                delete_employee();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
/*
*** Employee Database *** 


Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Edit Employee Record
4. Delete Employee Record
5. Exit
Enter your choice: 1
Enter Employee ID: 101
Enter Employee Name: Sanjay Singh
Enter Employee Salary: 20000
Employee record added successfully!

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Edit Employee Record
4. Delete Employee Record
5. Exit
Enter your choice: 1
Enter Employee ID: 102
Enter Employee Name: Junaid
Enter Employee Salary: 230000
Employee record added successfully!

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Edit Employee Record
4. Delete Employee Record
5. Exit
Enter your choice: 1
Enter Employee ID: 103
Enter Employee Name: Jon Doe
Enter Employee Salary: 12000
Employee record added successfully!

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Edit Employee Record
4. Delete Employee Record
5. Exit
Enter your choice: 2

Employee Records:
ID      Name            Salary
---------------------------------
101     Sanjay Singh   20000.00
102     Junaid         230000.00
103     Jon Doe        12000.00

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Edit Employee Record
4. Delete Employee Record
5. Exit
Enter your choice: 3
Enter Employee ID to edit: 103
Enter new Employee Name: John Doe
Enter new Employee Salary: 15000
Employee record edited successfully!

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Edit Employee Record
4. Delete Employee Record
5. Exit
Enter your choice: 4
Enter Employee ID to delete: 101
Employee record deleted successfully!

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Edit Employee Record
4. Delete Employee Record
5. Exit
Enter your choice: 2

Employee Records:
ID      Name            Salary
---------------------------------
102     Junaid         230000.00
103     John Doe       15000.00

Employee Database Menu:
1. Add Employee Record
2. Display Employee Records
3. Edit Employee Record
4. Delete Employee Record
5. Exit
Enter your choice: 5
Exiting the program.
*/