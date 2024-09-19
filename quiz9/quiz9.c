#include <stdio.h>

float calculateAverage(int score1, int score2, int score3) {
    return (float)(score1 + score2 + score3) / 3.0;
}

int main() {
    FILE *file;
    char studentName[4][50];
    int midterm1[4], midterm2[4], finalExam[4];

    printf("Enter student information:\n");
    for (int i = 0; i < 4; ++i) {
        printf("Student %d name: ", i + 1);
        scanf("%s", studentName[i]);

        printf("Midterm 1 score for %s: ", studentName[i]);
        scanf("%d", &midterm1[i]);

        printf("Midterm 2 score for %s: ", studentName[i]);
        scanf("%d", &midterm2[i]);

        printf("Final Exam score for %s: ", studentName[i]);
        scanf("%d", &finalExam[i]);
    }

    file = fopen("student_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "Student Information:\n");
    for (int i = 0; i < 4; ++i) {
        fprintf(file, "Name: %s, Midterm 1: %d, Midterm 2: %d, Final Exam: %d\n",
                studentName[i], midterm1[i], midterm2[i], finalExam[i]);
    }

    fclose(file);

    file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nReading from file and calculating averages:\n");
    for (int i = 0; i < 4; ++i) {
        fscanf(file, "Name: %s, Midterm 1: %d, Midterm 2: %d, Final Exam: %d\n",
               studentName[i], &midterm1[i], &midterm2[i], &finalExam[i]);

        float average = calculateAverage(midterm1[i], midterm2[i], finalExam[i]);
        printf("Average score for %s: %.2f\n", studentName[i], average);
    }

    fclose(file);

    return 0;
}