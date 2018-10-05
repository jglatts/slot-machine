#include <stdio.h>
#include <stdlib.h> // Contains rand() allowing us to generate random integers
#include <time.h> // Used to get current time for random number seed


/* Function prototypes */
int get_random_number(int);
int slot_roll(int, int, int);
void slot_results_check(int, int, int);

int main()
{
    /* This line provides a seed to the random number generator allowing
     pseudo-random numbers to be generated */
    srand(time(NULL)); // time(NULL) gives us the current time in seconds


    printf("========Slot Machine========\n");
    printf("============================\n\n");
    slot_roll(6, 6, 6);

    return 0;
}


/* Generate a random number between 1 and max */
int get_random_number(int max){
    return rand() % max + 1;
}


/* Displays the slot results, then pass the results to slot_result_check to check for matches */
int slot_roll(int slot_1, int slot_2, int slot_3){
    int random_number_1, random_number_2, random_number_3, jackpot_wins = 0, two_wins = 0, games_played = 0;
    int play_again;

    do{ 
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
        
        if(random_number_1 == random_number_2 && random_number_1 == random_number_3){
            printf("\nYOU'VE WON JACKPOT!!!\n");
            jackpot_wins ++ ;
        }
        else if(random_number_1 == random_number_2 || random_number_1 == random_number_3 || random_number_2 == random_number_3){
            printf("\nYou've Matched two numbers!!!\n");
            two_wins ++ ;
        }
        else{
            printf("\nNo Matches\n");
        }

        printf("Press ENTER to play again or enter 1 to quit\n");
        scanf("%c", &play_again);
        games_played ++ ;
        
    } while (play_again != 1 && play_again != 1);
        printf("\n======================\n");
        printf("JACKPOTS: %d\n", jackpot_wins );
        printf("TWO MATCH WINS: %d\n", two_wins );
        printf("GAMES PLAYED: %d\n", games_played );
        printf("======================\n");

        return 1;
}
