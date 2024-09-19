#include<stdio.h>
#include<string.h>

struct studentRecord{
    char name[20];
    int id;
    char dept[5];
    char gender;
};
struct studentRecord scanInfo() {
    struct studentRecord n;
    printf("\nEnter student name:");
    scanf("%s", n.name);
     printf("\nEnter student id:");
    scanf("%d", &n.id);
     printf("\nEnter student dept:");
    scanf("%s", n.dept);
     printf("\nEnter student gender:");
    scanf("%c", &n.gender);
    
    return n;
}
void printInfo(struct studentRecored m){
    printf("/nStudent name: %s", m.name);
    printf("/nStudent id: %d", m.id);
    printf("/nStudent dept: %s", m.dept);
    printf("/nStudent gender: %c", m.gender);
}
void main(){
    struct studentRecord st[2];
    st = scanInfo();
    for(int i = 0; i < 2; i++){
        printf("Enter student %d info: \n", i +1);
        st[i] = scanInfo;
    }

    //print info
    for(int i = 0; i < 2; i++){
        printInfo(st[i]);
    }
    
    printInfo(st1);

   

}