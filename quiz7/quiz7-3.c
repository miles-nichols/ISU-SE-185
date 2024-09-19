#include<stdio.h>

void examStat(int midterm1Score[], int size, int result[]) {
    // Initialize variables for statistics
    int sum = 0;
    int max = midterm1Score[0];
    int min = midterm1Score[0];
    int failCount = 0;
    int aCount = 0;

    // Calculate statistics
    for (int i = 0; i < size; i++) {
        sum += midterm1Score[i];

        if (midterm1Score[i] > max) {
            max = midterm1Score[i];
        }

        if (midterm1Score[i] < min) {
            min = midterm1Score[i];
        }

        if (midterm1Score[i] < 60) {
            failCount++;
        }

        if (midterm1Score[i] >= 93) {
            aCount++;
        }
    }

    result[0] = sum / size;  // Calculate average
    result[1] = max;         // Maximum score
    result[2] = min;         // Minimum score
    result[3] = failCount;   // Number of students failing
    result[4] = aCount;      // Number of students getting an A
}

int main(){

int midterm1Score[30]; //array for score
int result[5]; //array for result of examStat

  for (int i = 0; i < 30; i++) {
        printf("Enter the midterm 1 exam score for student %d: ", i + 1);
        scanf("%d", &midterm1Score[i]);
    }

examStat(midterm1Score, 30, result); // calling the stat func

    printf("\nExam Statistics:\n");                                  //printing results
    printf("(a) Midterm 1 Exam Average: %d\n", result[0]);
    printf("(b) Maximum Score: %d\n", result[1]);
    printf("(c) Minimum Score: %d\n", result[2]);
    printf("(d) Number of Students Failing: %d\n", result[3]);
    printf("(e) Number of Students Getting an A: %d\n", result[4]);

    return 0;
}