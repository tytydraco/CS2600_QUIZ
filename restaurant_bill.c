/*
Ask for tax %
Ask for tip %
Randomly choose meal cost
constants for meal costs
function to randomly pick one
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float bills[] = {9.95, 4.55, 13.25, 22.35};

int main() {
    int tax;
    int tip;
    
    time_t t;
    srand((unsigned int) time(&t));

    printf("Enter tax percent: ");
    scanf("%d", &tax);
    
    printf("Enter tip percent: ");
    scanf("%d", &tip);

    int meal_index = rand() % 4;
    float meal_price = bills[meal_index];
    printf("Random meal price: %f\n", meal_price);

    printf("Tax: %f\n", ((float) tax/100) * meal_price);
    printf("Tip: %f\n", ((float) tip/100) * meal_price);
}
