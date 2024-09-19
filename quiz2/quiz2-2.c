#include<stdio.h>
#include<math.h>

int main(){

char firstName[50];
char lastName[50];
char major[50];
char yearCollege[50];
char gradYear[50];

printf("Enter your first name: ");
scanf("%s", &firstName);
printf("Enter your last name: ");
scanf("%s", &lastName);
printf("Enter your major: ");
scanf("%s", &major);
printf("Enter your year in college (ex: freshman): ");
scanf("%s", &yearCollege);
printf("Enter your graduation year: ");
scanf("%s", &gradYear);

printf("\nName (Last, First): Name (%s, %s)\n", lastName, firstName);
printf("Major: %s\n", major);
printf("Year: %s \n", yearCollege);
printf("Graduation year: %s\n", gradYear);

    return 0;
}