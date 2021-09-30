/*
ask for number to decide the game
functions for each mode
default variable max is set
function to guess
Ask user for a number between 1 and 10
*/

#include <stdio.h>
#include <stdlib.h>

void play() {

}

void change() {

}

int main() {
    int mode;

    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");

    scanf("%d", &mode);

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
        printf("Bad command!");
        break;
    }
}