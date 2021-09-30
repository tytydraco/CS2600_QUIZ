/*
ask for number to decide the game
functions for each mode
default variable max is set
function to guess
Ask user for a number between 1 and 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_number = 10;

void play() {
    int number = rand() % max_number + 1;

    while (1) {
        char guess[16];

        printf("Guess: ");
        scanf("%s", &guess);

        if (strcmp(guess, "q") == 0)
            break;

        int guess_int = atoi(guess);

        if (guess_int > number) {
            printf("Too high!\n");
        } else if (guess_int < number) {
            printf("Too low!\n");
        } else {
            printf("Winner!\n");
            break;
        }
    }
}

void change() {
    printf("New max number: ");
    scanf("%d", &max_number);
    getchar();

    if (max_number < 0 || max_number > 1000) {
        printf("Number out of range!\n");
        change();
    }

    FILE *save = fopen("save", "w");
    char max_string[64];
    sprintf(max_string, "%d", max_number);
    if (save != NULL) {
        char save_text[64];
        fputs(max_string, save);
        fclose(save);
    }
}

int main() {
    int mode;

    FILE *save = fopen("save", "r");
    if (save != NULL) {
        char save_text[64];
        fgets(save_text, 64, save);
        max_number = atoi(save_text);
        fclose(save);
    }

    while (1) {
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");

        scanf("%d", &mode);
        getchar();
        
        switch (mode)
        {
        case 1:
            play();
            break;
        case 2:
            change();
            break;
        case 3:
            printf("Thanks for playing!\n");
            exit(0);
        
        default:
            printf("Bad command!\n");
            break;
        }
    }
}