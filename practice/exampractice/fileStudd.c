#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//this will be on the final!

struct node{
    char name[20];
    double exam1;
    double exam2;
    struct node* nextNode;
};

int main(){
//delcare node and intialize dynamic memory
struct node* a = (struct node*)malloc(sizeof(struct node));
struct node* b = (struct node*)malloc(sizeof(struct node));
struct node* c = (struct node*)malloc(sizeof(struct node));
//initialize date for node a
strcpy(a->name,"Kyle");
a->exam1 = 98.3;
a->exam2 = 99.3;
a->nextNode = b;

strcpy(b->name,"Nate");
b->exam1 = 95.5;
b->exam2 = 99.5;
b->nextNode = c;

strcpy(c->name,"Sam");
c->exam1 = 85.5;
c->exam2 = 100;
c->nextNode = NULL;
//basic operation using linked list
struct node* currentNode = a;
double exam1Total = 0;
double exam2Max = currentNode->exam2;
FILE *fp = fopen("test.txt","w");
while(currentNode != NULL){
    fprintf(fp,"\n%s: ",currentNode->name);
    fprintf(fp,"\n%.1lf: ",currentNode->exam1);
    fprintf(fp,"\n%.1lf: ",currentNode->exam2);
    fprintf(fp,"\naverage = %.1lf", (currentNode->exam1 + currentNode->exam2)/2);
    exam1Total = exam1Total + currentNode->exam1;
    if (exam2Max < currentNode->exam2){
        exam2Max = currentNode->exam2;
    }

    currentNode = currentNode->nextNode;

    fprintf(fp,"\nExam-1 average for the clas: %.1lf\n", exam1Total /3);
    fprintf(fp,"Exam-2 maximum for the class is: %.1lf", exam2Max);

    fclose(fp);
}
   FILE *frp = fopen("test.txt","r");
    fscanf(fp,"%lf", &exam1Total);
    fscanf(fp,"%lf", &exam2Max);
    printf("The maximum exam 2 score is: %.2lf\n", exam2Max);
    printf("The exam 1 average is: %.2lf\n", exam1Total / 3);

    fclose(fp);

    return 0;
}