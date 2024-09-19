

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


        }
    }
    //refresh();
}