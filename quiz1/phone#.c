#include<stdio.h>

int main(){
    
     printf("Please enter the 10 digit phone number:");
    long int phoneNum;
    scanf("%li", &phoneNum);

    int areaCode = phoneNum / 10000000;
    int exchangeCode =(phoneNum / 10000) % 1000;
    int userNum = phoneNum % 10000;

    printf("The area code is: %d\n", areaCode);
    printf("The exchange code is: %d\n", exchangeCode);
    printf("The user number is: %d\n", userNum);

return 0;
}