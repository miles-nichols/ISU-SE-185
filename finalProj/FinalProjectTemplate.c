//SE 185: Final Project Template//
/////////////////////////
/* 
Team xx (please insert your team number instead of xx)
Team member 1 "Ryan McNab" | "Percentage of Contribution to The Project"
Team member 2 "Name" | "Percentage of Contribution to The Project"
Team member 3 "Name" | "Percentage of Contribution to The Project"
Team member 4 "Name" | "Percentage of Contribution to The Project"
*/

////////////////////
#include<stdio.h>//
//add more here////
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
//#include <time.h>

//include<ncurses.h>
//////////////////////
//Struct Definition//
////////////////////


bool updateScores(int newUserScore) {
	char initials[3];
	int currentRow=0;

	//promt user for input to get their name
	printf("\nEnter your 3 intitals: ");
	scanf("%c", initials);
	
	char ch;
	FILE* fp = fopen("Highscores.txt", "r");
	FILE* fpTemp = fopen("temp.txt", "w");
	
    if (NULL == fp) {
        printf("file can't be opened \n");
    }
	
	char name[3];
	int rank,score;
	while (true) {
        int ret = fscanf(fp,"%d %s %d\n",&rank,name, &score);
		currentRow++;
        if (ret == 3)
		{
			fprintf(fpTemp,"%d %s %d\n", rank,name, score);
			//printf("%d %s %d\n",rank,name, score);
			if(score < newUserScore)
			{
				fprintf(fpTemp,"%d %s %d\n", rank,initials, newUserScore);
				currentRow++;
			}
			if (currentRow <=10) {
				fprintf(fpTemp,"%d %s %d\n", rank,name, score);
			}
		}
        else if (errno != 0) {
            perror("scanf:");
            break;
        } else if(ret == EOF) {
            break;
        } else {
            puts("\nNo or partial match.\n");
			return 0;
        }
    }
	fclose(fp);
	fclose(fpTemp);
	//TODO: Save the tpTemp to the fp file.
	return false;
}

bool printScores(int newUserScore) {
	char ch;
	FILE* fp = fopen("Highscores.txt", "r");
	
    if (NULL == fp) {
        printf("file can't be opened \n");
    }
	
	char name[3];
	int rank,score;
	while (true) {
        int ret = fscanf(fp,"%d %s %d\n",&rank,name, &score);
        if (ret == 3)
		{
			printf("%d %s %d\n",rank,name, score);
			if(score < newUserScore)
			{
				fclose(fp);
				bool scoreUpdated= updateScores(newUserScore);
				return scoreUpdated;
			}
		}
        else if (errno != 0) {
            perror("scanf:");
            break;
        } else if(ret == EOF) {
            break;
        } else {
            puts("\nNo or partial match.\n");
			return 0;
        }
    }
	fclose(fp);
	return 1;
}


/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////
void printTriangle(int y, int x);
void printCircle(int y, int x);
void printCross(int y, int x);
void printSquare(int y, int x);
void printBox(int y, int x);
int main(int argc, char* argv[]){

	
	

// 	srand(time[NULL]);
// 	rand();
// 	FILE* fp = fopen("Highscores.txt", "w+");
// 	int order[99], highscores[20];
// 	int score;
// 	char place[4], name[4];
// 	initscr();
// 	//mvprintw(42, 0, "Instructions:");
// 	//triangle centered at x=35, y=10 21 wide 10 tall
// 	printTriangle(10, 35);
// 	//circle centered at x=55 y=23 20 wide 10 tall
// 	printCircle(23, 55);
// 	//cross centered at x=35 y = 36 21 wide 10 tall
// 	printCross(36, 35);
// 	//square centered at x=15 y = 23 20 wide 10 tall
// 	printSquare(23, 15);
// 	refresh();
// 	for(int i = 0; i < 99; i++){
// 		//mvprintw(43, 0, "                          ");
// 		//mvprintw(43, 0, "Remember the order");
// 		refresh();
// 		order[i] = rand() % 4;
// 		for(int j = 0; j < i; j++){
// 			switch (order[j]) {
//             case 0: // Triangle
//                 printBox(10, 35);
//                 break;
//             case 1: // Circle
//                 printBox(23, 55);
//                 break;
//             case 2: // Cross
//                 printBox(36, 35);
//                 break;
//             case 3: // Square
//                 printBox(23, 15);
//                 break;
//             }
// 		}
// 		//mvprintw(43, 0, "                          ");
// 		//mvprintw(43, 0, "Now repeat the order");
// 		refresh();
// 		for(int j = 0; j < i; j++){
// //Evan
int newScore=20;
// 			//when user presses any of the buttons, use the persons work above you to print their "notifier" on the symbol that the user pressed
// 			//KEEP TRACK OF THEIR ORDER AND SEE IF IT IS CORRECT
// 			//IF ANY INCORRECT, LOSE AT ROUND i + 1
// 			//WHEN THEY LOSE, 
// 			//score = i + 1; break();


// 		}
// 	}
	bool ret=printScores(newScore);
	
	return 0;
}

///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////
void printTriangle(int y, int x){
	//mvprintw(y-5, x, "^");
	for(int i = 1; i < 11; i++){
		//mvprintw(y-5 + i, x - i, "/");
		//mvprintw(y-5 + i, x + i, "\\");
	}
	//mvprintw(y+5, x-10, "_____________________");
}
void printCircle(int y, int x){
    //top of circle
	//mvprintw(y - 5, x - 10, "       _______       ");
    //mvprintw(y - 4, x - 10, "   ___/       \\___   ");
    //mvprintw(y - 3, x - 10, " _/                \\_");
    //mvprintw(y - 2, x - 10, "/                    \\");
    //mvprintw(y - 1, x - 10, "|                    |");
    //mvprintw(y - 0, x - 10, "|                    |");
    //bottom of circle
    //mvprintw(y + 1, x - 10, "|                    |");
    //mvprintw(y + 2, x - 10, "|                    |");
    //mvprintw(y + 3, x - 10, "\\_                  _/");
    //mvprintw(y + 4, x - 10, "  \\____        ____/");
    //mvprintw(y + 5, x - 10, "       \\_______/      ");
}
void printCross(int y, int x){
	//mvprintw(y,x,"x");
	for(int i = 1; i < 11; i++){
		//mvprintw(y + (i/2), x - i, "/");
		//mvprintw(y + (i/2), x + i, "\\");
	}
	for(int i = 1; i < 11; i++){
		//mvprintw(y - (i/2), x - i, "\\");
		//mvprintw(y - (i/2), x + i, "/");
	}
}
void printSquare(int y, int x){
	//mvprintw(y-5, x-10, "____________________");
	for(int i = 1; i < 11; i++){
		//mvprintw(y-5 + i, x-10, "|");
		//mvprintw(y-5 + i, x+10, "|");
	}
	//mvprintw(y+5, x-10, "____________________");
}
void printBox(int y, int x) {
    int startY = y - 2;
    int startX = x - 2;
    int endY = y + 2;
    int endX = x + 2;

    for (int i = startY; i <= endY; i++) {
        for (int j = startX; j <= endX; j++) {
            if (i == y && j == x) {
                //mvprintw(i, j, "X");
            } else {
                //mvprintw(i, j, "*");
            }
        }
    }
    //refresh();
    //usleep(750000); // Delay for 0.75 seconds
    for (int i = startY; i <= endY; i++) {
        for (int j = startX; j <= endX; j++) {
            //mvprintw(i, j, " ");
        }
    }
    //refresh();
}