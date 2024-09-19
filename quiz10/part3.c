#include <stdio.h>
#include <string.h>

// Function prototype
int calculateFirstWordLength(char word[]);

int main() {
    char string[50];
    int length;

    printf("Enter a string: \n");
    fgets(string, sizeof(string), stdin);

    // Call strtok to extract the first word
    char *firstWord = strtok(string, " \n");

    // Call the calculateFirstWordLength function and store the result in 'length'
    length = calculateFirstWordLength(firstWord);

    printf("The length of \"%s\" is: %d\n", firstWord, length);
    return 0;
}

// Recursive function to calculate the length of a string
int calculateFirstWordLength(char word[]) {
    if (word == NULL || word[0] == '\0' || word[0] == '\n') {
        return 0;
    }
    return 1 + calculateFirstWordLength(word + 1);
}
