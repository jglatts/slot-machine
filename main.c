#include <stdio.h>
#include <stdlib.h> // Contains rand() allowing us to generate random integers
#include <time.h> // Used to get current time for random number seed


/* Function prototypes */
int get_random_number(int);
void slot_roll(int, int, int);
void slot_results_check(int, int, int);

int main()
{
    /* This line provides a seed to the random number generator allowing
     pseudo-random numbers to be generated */
    srand(time(NULL)); // time(NULL) gives us the current time in seconds
    char play_again;
    int i = 0; //variable used to check how many times game has been played


    // do-while loop to see if we should continue the game
    do {
        printf("========Slot Machine========\n\n");
        printf("==========================\n\n");
        slot_roll(6, 6, 6);
        printf("Press ENTER to play again or enter X to quit\n");
        scanf("%c", &play_again);
        i++; //increment by one everytime the player starts a new game
    } while (play_again != 'x' && play_again != 'X');

    return 0;
}


/* Generate a random number between 1 and max */
int get_random_number(int max){
    return rand() % max + 1;
}


/* Displays the slot results, then pass the results to slot_result_check to check for matches */
void slot_roll(int slot_1, int slot_2, int slot_3){
    int random_number_1, random_number_2, random_number_3;

    random_number_1 = get_random_number(slot_1);
    random_number_2 = get_random_number(slot_2);
    random_number_3 = get_random_number(slot_3);
    printf("*****\n");
    printf("* %d *\n", random_number_1);
    printf("*****\n");
    printf("*****\n");
    printf("* %d *\n", random_number_2);
    printf("*****\n");
    printf("*****\n");
    printf("* %d *\n", random_number_3);
    printf("*****\n");
    slot_results_check(random_number_1, random_number_2, random_number_3);
}

void slot_results_check(int number_1, int number_2, int number_3){
    // Check to see if user has made jackpot, two matches, or no matches
    if(number_1 == number_2 && number_1 == number_3){
        printf("\nYOU'VE WON JACKPOT!!!\n");
    }
    else if(number_1 == number_2 || number_1 == number_3 || number_2 == number_3){
        printf("\nYou've Matched 2!!!\n");
    }
    else{
        printf("\nNo Matches\n");
    }
}