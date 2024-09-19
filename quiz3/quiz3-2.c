#include<stdio.h>
#include<string.h>
int main (){

    char username[25];
    char password[10];

    printf("Enter your username:\n");
    scanf("%s", &username);
    printf("Enter your password:\n");
    scanf("%s", &password);

    char enteredUsername[25];
    char enteredPassword[10];

    printf("Enter your username:");
    scanf("%s", &enteredUsername);
    printf("Enter your password:");
    scanf("%s", &enteredPassword);
    if(strcmp(enteredPassword, password) == 0 && strcmp(enteredPassword, password) == 0){
        printf("Sucess!");
    }
    else{
    printf("Username or password is incorrect");
    }
    return 0;
}