
		
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
