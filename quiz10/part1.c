#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("numbers.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    // Write numbers to the file
    fprintf(fp, "%d %d %d %d %d %d %d %d\n", 12, 7, 3, 0, 28, 74, 37, 299);

    fclose(fp);

    // Reopen the file in read mode
    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    int evenNums[8];
    int curr;
    int count = 0;

    // Read the file and store even numbers in the array
    while (fscanf(fp, "%d", &curr) == 1) {
        if (curr % 2 == 0) {
            evenNums[count++] = curr;
        }
    }

    fclose(fp);

    // Print the even numbers
    printf("Even numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", evenNums[i]);
    }
    printf("\n");

    return 0;
}
