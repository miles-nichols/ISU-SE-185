#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    char first_name[50], last_name[50]; //array for first name and array for last name
    char *full_name = NULL; 
    int num_letters = 0; //number of letters
    int i = 0; //for first name loop
        int j = 0; //for last name loop

    printf("Whats your first name\n");//finding first name
    scanf("%s",first_name);
    printf("Whats your last name\n"); //finding last name
    scanf("%s",last_name);

    num_letters = strlen(first_name) + strlen(last_name); //finding number of letters in both the combniation of the first and last name
    full_name = (char *)malloc(num_letters + 1); // allocating memory (+1 for the space character)
 
    if (full_name == NULL) {
        printf("Error while allicating memory");
        return 1;
    }

    while (first_name[i] != '\0') { //copying fist name character by character
        full_name[i] = first_name[i];
        i++;
    }
    
    full_name[i] = ' '; 
    i++; //adds a space

    while (last_name[j] != '\0') { //copying fist name character by character
        full_name[i] = last_name[j];
        i++;
        j++;
    }

    full_name[i] = '\0';  // Null-terminate the full_name string
    printf("Full name: %s\n", full_name);

    free(full_name);     // Free the dynamically allocated memory

    return 0;
}