#include <stdio.h> 
#include <string.h>

void strengthenPassword(char *password) {
    int length = strlen(password);
    
    for (int i = 0; i < length; i++) {
        switch (password[i]) {
            case 'i':
                password[i] = '1';
                break;
            case 'a':
                password[i] = '@';
                break;
            case 'm':
                password[i] = 'M';
                break;
            case 'b':
                password[i] = '8';
                break;
            case 's':
                password[i] = '$';
                break;
            // Add more transformations if needed
        }
    }
}

int main() {
    char password[100]; // Adjust the size accordingly

    printf("Enter your password: ");
    scanf("%s", password);

    strengthenPassword(password);

    printf("Your strengthened password: %s!\n", password);

    return 0;
}

































/* int main(){ 
char userPassword[50];
int i;

printf("Please enter a password: ");
scanf("%s", userPassword);

for(i = 0; i < (strlen(userPassword)); ++i){
    if(userPassword[i] == 'i'){
        userPassword[i] = '1';
    }
    else if(userPassword[i] == 'a'){
        userPassword[i] == '@';
    }
    else if(userPassword[i] == 'm'){
        userPassword[i] == 'M';
    }
    else if(userPassword[i] == 'B'){
        userPassword[i] == '8';
    }
    else if(userPassword[i] == 's'){
        userPassword[i] == '$';
    }
}
    strcat(userPassword, "!");
    printf("Your updated password is: ");
    printf("%s", userPassword);

    return 0;
} */