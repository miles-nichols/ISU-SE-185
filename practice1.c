#include<stdio.h>

//take in an integer and print every integer before if starting at 0

int main () {

	int num;
	printf("Please enter a  number: ");
	scanf("%d", num);

	for(int i = 0; i < num; i++){
		printf(i);
	}

	
}