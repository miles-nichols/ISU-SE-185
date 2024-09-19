#include<stdio.h>
#include<math.h>

int main(void){
   
double mikeSchoolDist = sqrt(pow((15.55 - 22.05), 2) + pow((55.15 - 85.10), 2));   
double marySchoolDist = sqrt(pow((15.55 - 43.25), 2) + pow((55.15 - 9.80), 2));       
double garySchoolDist = sqrt(pow((15.55 - 2.55), 2) + pow((55.15 - 72.86), 2));   
double loganSchoolDist = sqrt(pow((15.55 - 15.15), 2) + pow((55.15 - 40.49), 2));   

printf("the E distance fpr Mike is %lf\n", mikeSchoolDist);
printf("the E distance for Mary is %lf\n", marySchoolDist);
printf("the E distance for Gray is %lf\n", garySchoolDist);
printf("the E distance for Logan is %lf\n", loganSchoolDist);

    return 0;
}