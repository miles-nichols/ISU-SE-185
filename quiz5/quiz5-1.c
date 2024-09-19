#include <stdio.h>

int main() {
    double hw[5], exam[3]; // Arrays to store homework and exam grades
    double hw_avg = 0.0, exam_avg = 0.0, weighted_avg;

    // Input grades for homework
    for (int i = 0; i < 5; i++) {
        printf("Enter your grade (%%) for HW #%02d: ", i + 1);
        scanf(" %lf", &hw[i]);
        hw_avg += hw[i]; // Accumulate homework grades
    }

    // Input grades for exams
    for (int i = 0; i < 3; i++) {
        printf("Enter your grade (%%) for Exam #%02d: ", i + 1);
        scanf(" %lf", &exam[i]);
        exam_avg += exam[i]; // Accumulate exam grades
    }

    // Calculate averages
    hw_avg /= 5.0;
    exam_avg /= 3.0;
    weighted_avg = (0.40 * hw_avg) + (0.60 * exam_avg);

    printf("\nFinal grade = %.2lf%%\n", weighted_avg);
    return 0;
}