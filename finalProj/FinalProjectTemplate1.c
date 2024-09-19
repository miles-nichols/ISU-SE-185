//SE 185: Final Project Template//
/////////////////////////
/* 
Team xx (please insert your team number instead of xx)
Team member 1 "Ryan McNab" | "45" project skeleton, highscores table (input/output), print shapes
Team member 2 "Miles Nichols" | "5" not working high scores table, making ryan finish it
Team member 3 "Evan Gluba" | "25" got user input and a random pattern for order while checking for valid and invalid input
Team member 4 "Troy Powers" | "25" print order and box
*/

////////////////////
#include<stdio.h>//
//add more here////
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
//////////////////////
//Struct Definition//
////////////////////


/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////
int printtable();
int printScores(int newUserScore);
int updateScores(int newUserScore, char initials[]);
void printTriangle(int y, int x);
void printCircle(int y, int x);
void printCross(int y, int x);
void printSquare(int y, int x);
void printBox(int y, int x);
void circTriangle(int y, int x);
void circCircle(int y, int x);
void circCross(int y, int x);
void circSquare(int y, int x);
void circ(int y, int x);
void circRemove(int y, int x);
int main(int argc, char* argv[]){
	srand(time(NULL));
	rand();
	int correct = 0, wrong = 0;
	char userChoice = 'x';
	char starter;
	//asks user to start
	printf("Are you ready to start?(y to start): ");
	scanf("%c", &starter);
	if(starter != 'y'){
		return 0;
	}
	int order[99], highscores[20], score;
	initscr();
	mvprintw(42, 0, "Instructions:");
	//triangle centered at x=35, y=10 21 wide 10 tall
	printTriangle(10, 35);
	//circle centered at x=55 y=23 20 wide 10 tall
	printCircle(23, 55);
	//cross centered at x=35 y = 36 21 wide 10 tall
	printCross(36, 35);
	//square centered at x=15 y = 23 20 wide 10 tall
	printSquare(23, 15);
	refresh();
	for(int i = 0; i < 99; i++){
		//prints the order for user to remember
		mvprintw(43, 0, "                          ");
		mvprintw(43, 0, "Remember the order");
		refresh();
		order[i] = rand() % 4;
		for(int j = 0; j < i; j++){
			switch (order[j]) {
            case 0: // Triangle
                printBox(10, 35);
                break;
            case 1: // Circle
                printBox(23, 55);
                break;
            case 2: // Cross
                printBox(36, 35);
                break;
            case 3: // Square
                printBox(23, 15);
                break;
            }
		}
		//asks user to repeat the order
		mvprintw(43, 0, "                          ");
		mvprintw(43, 0, "Now repeat the order");
		refresh();
		for(int j = 0; j < i; j++){
			correct = 0;
			wrong = 0;
			userChoice = 'x';
			while (1) { 
			mvprintw(44, 0, "Use n(North), e(East), s(South), w(West)"); 
			refresh();
		
			scanf("%c", &userChoice);
			
			if (order[j] == 0 && userChoice == 'n'){ //this is the option if triangle is chosen 
				circTriangle(10, 35);
				break; //breaks the while loop if user gets the answer right
			}
				else if (order[j] == 0 && userChoice == 'e') { //if they hit e
					circCircle(23, 55);
					wrong = 1; //if user enters wrong option, this will break the for loop later
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
				else if (order[j] == 0 && userChoice == 's') {//if they hit s
					circCross(36, 35);
					wrong = 1;
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
				else if (order[j] == 0 && userChoice == 'w') { //if they hit w
					circSquare(23, 15);
					wrong = 1;
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
			
			
			if (order[j] == 1 && userChoice == 'e'){ //this is the option if circle is chosen 
				circCircle(23, 55);
				break; //breaks the while loop if user gets the answer right
			}
				else if (order[j] == 1 && userChoice =='n') { //if they hit n
					circTriangle(10, 35);
					wrong = 1; //if user enters wrong option, this will break the for loop later
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
				else if (order[j] == 1 && userChoice == 's') {//if they hit s
					circCross(36, 35);
					wrong = 1;
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
				else if (order[j] == 1 && userChoice == 'w') { //if they hit w
					circSquare(23, 15);
					wrong = 1;
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
			
			if (order[j] == 2 && userChoice == 's'){ //this is the option if x is chosen 
				circCross(36, 35);
				break; //breaks the while loop if user gets the answer right
			}
				else if (order[j] == 2 && userChoice == 'e') { //if they hit e
					circCircle(23, 55);
					wrong = 1; //if user enters wrong option, this will break the for loop later
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
				else if (order[j] == 2 && userChoice == 'n') {//if they hit n
					circTriangle(10, 35);
					wrong = 1;
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
				else if (order[j] == 2 && userChoice == 'w') { //if they hit w
					circSquare(23, 15);
					wrong = 1;
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
			
			if (order[j] == 3 && userChoice == 'w'){ //this is the option if square is chosen 
				circSquare(23, 15);
				break; //breaks the while loop if user gets the answer right
				}
				else if (order[j] == 3 && userChoice == 'e') { //if they hit e
					circCircle(23, 55);
					wrong = 1; //if user enters wrong option, this will break the for loop later
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
				else if (order[j] == 3 && userChoice == 's') {//if they hit s
					circCross(36, 35);
					wrong = 1;
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
				else if (order[j] == 3 && userChoice =='n') { //if they hit n
					circTriangle(10, 35);
					wrong = 1;
					mvprintw(45, 0, "wrong input...");
					refresh();
					break;
				}
			if (wrong == 1) { //breaks the for loop when the wrong button is hit
			break;
			}
			}
			if (wrong == 1) { //breaks the for loop when the wrong button is hit
			break;
			}
			usleep(100000);
			circRemove(10, 35); //these four functions will reset the circle that is around the user selections
			circRemove(23, 55);
			circRemove(36, 35);
			circRemove(23, 15);
		}
if (wrong == 1) { //breaks the for loop when the wrong button is hit
			break;
			}
		score = i + 1;
	}

	endwin();
	printf("Your score was: %d\n", score);
	printScores(score);

	//print table
	printtable();
	return 0;
}

///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////
void printTriangle(int y, int x){
	//tip of triangle
	mvprintw(y-5, x, "^");
	//sides of triangle
	for(int i = 1; i < 11; i++){
		mvprintw(y-5 + i, x - i, "/");
		mvprintw(y-5 + i, x + i, "\\");
	}
	//bottom of triangle
	mvprintw(y+5, x-10, "_____________________");
}
void printCircle(int y, int x){
    //top of circle
	mvprintw(y - 5, x - 10, "       _______       ");
    mvprintw(y - 4, x - 10, "   ___/       \\___   ");
    mvprintw(y - 3, x - 10, " _/                \\_");
    mvprintw(y - 2, x - 10, "/                    \\");
    mvprintw(y - 1, x - 10, "|                    |");
    mvprintw(y - 0, x - 10, "|                    |");
    //bottom of circle
    mvprintw(y + 1, x - 10, "|                    |");
    mvprintw(y + 2, x - 10, "|                    |");
    mvprintw(y + 3, x - 10, "\\_                  _/");
    mvprintw(y + 4, x - 10, "  \\____        ____/");
    mvprintw(y + 5, x - 10, "       \\_______/      ");
}
void printCross(int y, int x){
	//middle of x
	mvprintw(y,x,"x");
	//top of x
	for(int i = 1; i < 11; i++){
		mvprintw(y + (i/2), x - i, "/");
		mvprintw(y + (i/2), x + i, "\\");
	}
	//bottom of x
	for(int i = 1; i < 11; i++){
		mvprintw(y - (i/2), x - i, "\\");
		mvprintw(y - (i/2), x + i, "/");
	}
}
void printSquare(int y, int x){
	//top of square
	mvprintw(y-5, x-10, "____________________");
	//sides of square
	for(int i = 1; i < 11; i++){
		mvprintw(y-5 + i, x-10, "|");
		mvprintw(y-5 + i, x+10, "|");
	}
	//bottom of square
	mvprintw(y+5, x-10, "____________________");
}
void printBox(int y, int x) {
	//print 5x5 box
    int startY = y - 2;
    int startX = x - 2;
    int endY = y + 2;
    int endX = x + 2;

    for (int i = startY; i <= endY; i++) {
        for (int j = startX; j <= endX; j++) {
            if (i == y && j == x) {
                mvprintw(i, j, "X");
            } else {
                mvprintw(i, j, "*");
            }
        }
    }
    refresh();
	//wait .75 seconds
    usleep(750000); // Delay for 0.75 seconds
	//get rid of box
    for (int i = startY; i <= endY; i++) {
        for (int j = startX; j <= endX; j++) {
            mvprintw(i, j, " ");
        }
    }
    refresh();
}
//does the update if needed
int updateScores(int newUserScore, char initials[]) {
	int currentRow=0;
	//open files
	FILE* fp = fopen("temp.txt", "r");
	FILE* fpTemp = fopen("Highscores.txt", "w");
	//make sure open
    if (NULL == fp) {
        printf("file can't be opened \n");
    }
	if (NULL == fpTemp) {
        printf("file can't be opened \n");
    }
	char name[4];
	int rank,score;
	int updated = 0;
	//run through entire file
	while (1) {
		//scan line
        int ret = fscanf(fp,"%d %s %d\n",&rank,name, &score);
		int tempscore;
		char tempname[4];
		//if scan working
        if (ret == 3)
		{
			//if the update has happened yet
			if(updated == 1)
			{
				//if at bottom of file
				if(rank == 10)
				{
					//print last line and end
					fprintf(fpTemp, "%d %s %d\n", rank, tempname, tempscore);
					fclose(fp);
					fclose(fpTemp);
					return 1;
				}
				//print line with last name and score
				fprintf(fpTemp, "%d %s %d\n", rank, tempname, tempscore);
				strcpy(tempname, name);
				tempscore = score;
			}
			else if(score < newUserScore)
			{
				//replace line with new information
				fprintf(fpTemp,"%d %s %d\n", rank,initials, newUserScore);
				updated = 1;
				strcpy(tempname, name);
				tempscore = score;
			}
			else if(rank == 10)
			{
				//if opened at end of file, end program
				printf("Error: No change was made");
				fclose(fp);
				fclose(fpTemp);
				return 0;
			}
			else
			{
				//print  same line as before
				fprintf(fpTemp,"%d %s %d\n", rank,name, score);
			}
		}
        else if(ret == EOF) {
            break;
        } else {
            puts("\nNo or partial match.\n");
			return 0;
        }
    }
	fclose(fp);
	fclose(fpTemp);
	return 0;
}
//checks if there is an update required
int printScores(int newUserScore) {
	//open file
	FILE* fp = fopen("Highscores.txt", "r");
	//make sure its open
    if (NULL == fp) {
        printf("file can't be opened \n");
    }
	
	char name[4];
	int rank,score;
	while (1) {
		//scanf line
        int ret = fscanf(fp,"%d %s %d\n",&rank,name, &score);
        if (ret == 3)
		{
			if(score < newUserScore)
			{
				//renames highscores to temp
				rename("Highscores.txt","temp.txt");
				printf("Congrats, you got a highscore!");
				char initials[4];
				//prompt user for input to get their name
				printf("\nEnter your 3 initials: ");
				scanf("%s", initials);
				
				fclose(fp);
				//do the update to the table
				int scoreUpdated = updateScores(newUserScore, initials);
				//remove the temporary file
				remove("temp.txt");
				return scoreUpdated;
				
			}
		}
        else if(ret == EOF) {
			//means there is no update needed
			printf("Unfortunately, you did not get a highscore\nYou got %d score!\nThanks for playing!\n", newUserScore);
			fclose(fp);
            break;
        } else {
            puts("\nNo or partial match.\n");
			fclose(fp);
			return 0;
        }
    }
	
	return 0;
}
//draw circle on square
void circSquare(int y, int x){
	circ(y, x);
}
//draw circle on circle

void circCircle(int y, int x){
	circ(y, x);
}
//draw circle on triangle

void circTriangle(int y, int x){
	circ(y, x);
}
//draw circle on cross

void circCross(int y, int x){
	circ(y, x);
}

//makes the big circle
void circ(int y, int x){
	//make the top and the bottom of circle
	mvprintw(y-7, x-7, "###############");
	mvprintw(y+7, x-7, "###############");
	//make the sides 
	mvprintw(y - 6, x - 11, "####");
	mvprintw(y - 6, x + 8, "####");
	//make the sides
	mvprintw(y + 6, x - 11, "####");
	mvprintw(y + 6, x + 8, "####");
	//makes the lines down the side
	for (int i = 1; i < 3; i++){
		mvprintw(y - 6 + i, x - 12, "#");
		mvprintw(y - 6 + i, x + 12, "#");
		mvprintw(y - 6 + i, x - 12, "#");
		mvprintw(y - 6 + i, x + 12, "#");
		mvprintw(y + 6 - i, x - 12, "#");
		mvprintw(y + 6 - i, x + 12, "#");
	}
	//makes the inner part of the side
	for (int i = 4; i < 9; i++) {
		mvprintw(y - 6 + i, x - 14, "#"); 
		mvprintw(y - 6 + i, x + 14, "#");
	}
	//make the inner part of the top and bottom
	mvprintw(y - 3, x - 13, "#");\
	mvprintw(y - 3, x + 13, "#");
	mvprintw(y + 3, x - 13, "#");
	mvprintw(y + 3, x + 13, "#");
}

void circRemove(int y, int x){
	//replaces top and bottom with blank 
	mvprintw(y-7, x-7, "               ");
	mvprintw(y+7, x-7, "               ");
	//replaces inner sides with blank
	mvprintw(y - 6, x - 11, "    ");
	mvprintw(y - 6, x + 8, "    ");
	
	mvprintw(y + 6, x - 11, "    ");
	mvprintw(y + 6, x + 8, "    ");
	//replaces the outer sides with blank
	for (int i = 1; i < 3; i++){
		mvprintw(y - 6 + i, x - 12, " ");
		mvprintw(y - 6 + i, x + 12, " ");
		mvprintw(y - 6 + i, x - 12, " ");
		mvprintw(y - 6 + i, x + 12, " ");
		mvprintw(y + 6 - i, x - 12, " ");
		mvprintw(y + 6 - i, x + 12, " ");
	}
	//replaces the inner outside with blanks
	for (int i = 4; i < 9; i++) {
		mvprintw(y - 6 + i, x - 14, " "); 
		mvprintw(y - 6 + i, x + 14, " ");
	}
	//replaces remaining with blank
	mvprintw(y - 3, x - 13, " ");
	mvprintw(y - 3, x + 13, " ");
	mvprintw(y + 3, x - 13, " ");
	mvprintw(y + 3, x + 13, " ");
}
int printtable(){
	//open file
	FILE *fp = fopen("Highscores.txt", "r+");
	//restart at top
	rewind(fp);
	fseek(fp,0,SEEK_SET);
	//make sure file open
	if (NULL == fp) {
        printf("file can't be opened \n");
    }
	char name[4];
	int rank,score;
	while (1) {
		//scans the line
        int ret = fscanf(fp,"%d %s %d\n",&rank,name, &score);
        if (ret == 3)
		{
				//if worked correctly, print line to console
				printf("%d %s %d\n", rank, name, score);
		}
        else if(ret == EOF) {
			//when end of file, stop printing
            break;
        } else {
            puts("\nNo or partial match.\n");
			return 0;
        }
    }
	//close file
	fclose(fp);
	return 0;
}