#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SYMBOLS 10
#define MAX_ROUNDS 10
#define MAX_INITIALS 3

// Global variables
char symbols[MAX_SYMBOLS] = {'@', '#', '$', '%', '&', '*', '!', '?', '^', '+'};
char game_sequence[MAX_ROUNDS];
char user_sequence[MAX_ROUNDS];
int score = 0;

// Function declarations
void generate_sequence();
void display_symbols();
void get_user_input();
int check_input();
void update_score();
void display_highscores();
void save_highscore();

int main() {
    srand(time(NULL));

    printf("Welcome to the Memory Game!\n");

    char ready;
    printf("Are you ready to start? (Y/N): ");
    scanf(" %c", &ready);

    if (ready == 'Y' || ready == 'y') {
        generate_sequence();
        display_symbols();

        for (int round = 0; round < MAX_ROUNDS; round++) {
            get_user_input();
            if (check_input()) {
                update_score();
            } else {
                printf("Incorrect! Game Over. Your final score: %d\n", score);
                display_highscores();
                break;
            }
        }

        save_highscore();
    } else {
        printf("Exiting the game. Goodbye!\n");
    }

    return 0;
}

void generate_sequence() {
    for (int i = 0; i < MAX_ROUNDS; i++) {
        game_sequence[i] = symbols[rand() % MAX_SYMBOLS];
    }
}

void display_symbols() {
    printf("Memorize the sequence:\n");

    for (int i = 0; i < MAX_ROUNDS; i++) {
        printf("%c ", game_sequence[i]);
        fflush(stdout);
        printf("\r  ");
        fflush(stdout);
    }

    printf("\n");
}

void get_user_input() {
    printf("Enter the sequence (e.g., ABC): ");
    scanf("%s", user_sequence);
}

int check_input() {
    return strcmp(user_sequence, game_sequence) == 0;
}

void update_score() {
    score++;
    printf("Correct! Your score: %d\n", score);
}

void display_highscores() {
    printf("High Scores:\n");

    // Read high scores from file and display them
    FILE *file = fopen("highscores.txt", "r");
    if (file == NULL) {
        printf("No high scores available.\n");
        return;
    }

    char initials[MAX_INITIALS];
    int highscore;

    while (fscanf(file, "%s %d", initials, &highscore) != EOF) {
        printf("%s - %d\n", initials, highscore);
    }

    fclose(file);
}

void save_highscore() {
    printf("Congratulations! Enter your initials (3 characters): ");
    char initials[MAX_INITIALS];
    scanf("%s", initials);

    FILE *file = fopen("highscores.txt", "a");
    if (file == NULL) {
        printf("Error saving high score.\n");
        return;
    }

    fprintf(file, "%s %d\n", initials, score);

    fclose(file);

    // Sort high scores and update the file
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error updating high scores.\n");
        return;
    }

    int scores[MAX_ROUNDS];
    char names[MAX_ROUNDS][MAX_INITIALS];

    file = fopen("highscores.txt", "r");
    if (file == NULL) {
        printf("Error updating high scores.\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%s %d", names[i], &scores[i]) != EOF) {
        i++;
    }

    fclose(file);

    // Bubble sort high scores
    for (int j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - j - 1; k++) {
            if (scores[k] < scores[k + 1]) {
                int tempScore = scores[k];
                scores[k] = scores[k + 1];
                scores[k + 1] = tempScore;

                char tempName[MAX_INITIALS];
                strcpy(tempName, names[k]);
                strcpy(names[k], names[k + 1]);
                strcpy(names[k + 1], tempName);
            }
        }
    }

    // Write sorted high scores to temp file
    for (int j = 0; j < i; j++) {
        fprintf(tempFile, "%s %d\n", names[j], scores[j]);
    }

    fclose(tempFile);

    // Rename temp file to overwrite original high scores file
    remove("highscores.txt");
    rename("temp.txt", "highscores.txt");
}
