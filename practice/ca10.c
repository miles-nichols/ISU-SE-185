#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Friend{
    char name[50];
    char month;
    char day;
};

int main(){
    struct Friend friends[12];
    char enter[10];
    int friendCount = 0;

while(1){
    printf("Do you want to enter a friend's birthday? type yes or no:\n");
    scanf("%s", enter);
     if (strcmp(enter, "no") == 0) {
        break;
    }
    else if(strcmp(enter, "yes") == 0){
        if(friendCount < 12){
            printf("Enter friend's name: ");
            scanf("%s", friends[friendCount].name);
            printf("Enter friend's birth month (1-12): ");
            scanf("%d", &friends[friendCount].month);
            printf("Enter friend's birth day: ");
            scanf("%d", &friends[friendCount].day);
                friendCount++; 
        }
        else{
            printf("You have entered info for all 12 friends");
            break;
        }
    }
    printf("Friends birthdays: ");
        for(int i = 0; i < friendCount; ++i){
            printf("%s's birthday is %d/%d\n", friends[i].name, friends[i].month, friends[i].day);
        }
}

    

return 0;
}