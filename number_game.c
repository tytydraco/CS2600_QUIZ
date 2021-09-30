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
}

int main() {
    int mode;

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
            exit(0);
        
        default:
            printf("Bad command!\n");
            break;
        }
    }
}