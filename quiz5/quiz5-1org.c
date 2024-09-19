#include<stdio.h> 
 
int main() { 
    double hw1, hw2, hw3, hw4, hw5, exam1, exam2, exam3;     
    double hw_avg, exam_avg, weighted_avg; 
    
    printf("Enter your grade (%%) for HW #01:  ");     
    scanf(" %lf" , &hw1);    
    printf("Enter your grade (%%) for HW #02:  ");   
    scanf(" %lf" , &hw2);     
    printf("Enter your grade (%%) for HW #03:  ");   
    scanf(" %lf" , &hw3);    
    printf("Enter your grade (%%) for HW #04:  ");   
    scanf(" %lf" , &hw4); 
    printf("Enter your grade (%%) for HW #05:  ");    
    scanf(" %lf" , &hw5);   
    printf("Enter your grade (%%) for Exam #01:  "); 
    scanf(" %lf" , &exam1);  
    printf("Enter your grade (%%) for Exam #02:  ");   
    scanf(" %lf" , &exam2);   
    printf("Enter your grade (%%) for Exam #03:  ");  
    scanf(" %lf" , &exam3); 
     	   	             
    hw_avg = (hw1 + hw2 + hw3 + hw4 + hw5) / 5.0;     
    exam_avg = (exam1 + exam2 + exam3) / 3.0;   
    weighted_avg = (0.40 * hw_avg) + (0.60 * exam_avg); 
    printf("\nFinal grade = %.2lf%%\n" , weighted_avg);   

     return 0; 
} 
