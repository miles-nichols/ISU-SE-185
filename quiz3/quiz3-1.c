#include<stdio.h>
int main (){

    int gradePercent;
    printf("Please enter your grade percentage:\n");
    scanf("%d", &gradePercent);

    if(gradePercent <= 100 && gradePercent >= 93) {
        printf("Your grade is an A");
    }
    else if(gradePercent < 93 && gradePercent >= 90) {
        printf("Your grade is an A-");
    }
    else if(gradePercent < 93 && gradePercent >= 90) {
        printf("Your grade is an A");
    }
    else if(gradePercent < 90 && gradePercent >= 87) {
        printf("Your grade is a B+");
    }
    else if(gradePercent < 87 && gradePercent >= 83) {
        printf("Your grade is an B");
    }
    else if(gradePercent < 83 && gradePercent >= 80) {
        printf("Your grade is a B-");
    }
    else if(gradePercent < 80 && gradePercent >= 77) {
        printf("Your grade is an C+");
    }
    else if(gradePercent < 77 && gradePercent >= 73) {
        printf("Your grade is a C");
    }
     else if(gradePercent < 73 && gradePercent >= 70) {
        printf("Your grade is a C-");
    }
    else if(gradePercent < 70 && gradePercent >= 67) {
        printf("Your grade is a D+");
    }
    else if(gradePercent < 67 && gradePercent >= 63) {
        printf("Your grade is a D");
    }
    else if(gradePercent < 63 && gradePercent >= 60) {
        printf("Your grade is a D-");
    }
    else if(gradePercent < 60 && gradePercent >= 0) {
        printf("Your grade is a F");
    }

    else{
        printf("Your grade must be between 0 percent and 100 percent inclusively\n");
    }

    return 0;
}