/*
    ผู้ใช้กรอกข้อมูลพนักงานในบริษัท โดยจะกรอกข้อมูล ชื่อ, เงินเดือน, อายุการทำงาน ของแต่ละคน โดยเมื่อผู้ใช้กรอกตัว n จะถือเป็นการหยุดโปรแกรมและทำการแสดงข้อมูลเงินเดือนเฉลี่ยของพนักงานในบริษัท และเงินเดือนของทุกคนรวมกันที่ผู้บริหารต้องจ่าย และแสดงคนที่อายุงานเยอะที่สุดพร้อมระบุ ชื่อ เงินเดือน และอายุงาน ของคนๆ นั้น
    
    Test case:
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Yorn
        Salary (Bath/Month) : 
            15000
        Duration (Year) : 
            4
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Van
        Salary (Bath/Month) : 
            14550
        Duration (Year) : 
            2
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Thane
        Salary (Bath/Month) : 
            22500
        Duration (Year) : 
            8
        Do you want to Enter Employee Information? (y/n) : 
            n
    Output:
        Average of Salary : 17,350.00 Bath
        Payment of every month : 52,050.00 Bath
        ----------------------------------------
        ** Most duration in this business **
        Name : Thane (8 Years)
        Salary : 22,500.00 Bath

*/

//TODO: #21 output money should in decimal format (eg. 120,200,340.42).
#include <stdio.h>

int main() {
    char choice;
    int totalSalary = 0, maxDuration = 0;
    float averageSalary = 0;
    char maxName[100];
    float maxSalary = 0;
    
    int n = 0;
    
    do {
        printf("Do you want to Enter Employee Information? (y/n) : ");
        scanf(" %c", &choice);
        
        if (choice == 'n') {
            break;
        }
        else if (choice == 'y') {
            char name[100];
            float salary;
            int duration;
            
            printf("Employee Name : ");
            scanf(" %s", name);
            
            printf("Salary (Bath/Month) : ");
            scanf("%f", &salary);
            
            printf("Duration (Year) : ");
            scanf("%d", &duration);
            
            totalSalary += salary;
            
            if (duration > maxDuration) {
                maxDuration = duration;
                maxSalary = salary;
                strcpy(maxName, name);
            }
            
            n++;
        }
        else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    } while (choice != 'n');
    
    if (n > 0) {
        averageSalary = (float)totalSalary / n;
        
        printf("\nAverage of Salary : %.2f Bath\n", averageSalary);
        printf("Payment of every month : %.2f Bath\n", (float)totalSalary);
        printf("----------------------------------------\n");
        printf("** Most duration in this business **\n");
        printf("Name : %s (%d Years)\n", maxName, maxDuration);
        printf("Salary : %.2f Bath\n", maxSalary);
    } else {
        printf("No employee information entered.\n");
    }
    
    return 0;
}
