#include <stdio.h>

// Function to calculate the average of an array of grades
double calculateAverage(double grades[], int numGrades) {
    double sum = 0.0;
    for (int i = 0; i < numGrades; i++) {
        sum += grades[i];
    }
    return sum / numGrades;
}

// Function to determine the letter grade based on a numeric score
char determineLetterGrade(double score) {
    if (score >= 85) {
        return 'A';
    } else if (score >= 75) {
        return 'B';
    } else if (score >= 60) {
        return 'C';
    } else {
        return 'F';
    }
}

int main() {
    const int numStudents = 2;
    const int numAssignments = 4;
    double grades[numStudents][numAssignments];
    double finalGrades[numStudents];
    
    printf("Please Enter assigment grades for student 1 and student 2\n");
    // Input assignment grades for each student
    for (int student = 0; student < numStudents; student++) {
        for (int assignment = 0; assignment < numAssignments; assignment++) {
            printf("Student-%d Assignment-%d grade:  ", student + 1, assignment + 1);
            scanf("%lf", &grades[student][assignment]);
        }

        // Calculate the average grade for the current student
        finalGrades[student] = calculateAverage(grades[student], numAssignments);
    }

    // Display final grades and letter grades for each student
    for (int student = 0; student < numStudents; student++) {
        printf("Student %d Avg = %.2lf \nStudent %d Grade = %c\n", student + 1, finalGrades[student], student +1, determineLetterGrade(finalGrades[student]));
    }

    return 0;
}