#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int playWordle(char wordGuess[6], int numberOfAttempts, char userHint[6][5]) {

    int i, j;
    char wordleAnswer[6] = "SHARE\0";
    char wordleChecker[6] = "_____\0";

    int userIsCorrect;

    // correct position
    for (i = 0; i < 5; i ++) {
        if (wordleAnswer[i] == wordGuess[i]) {
            wordleChecker[i] = wordGuess[i];
        }
    }
    

    // wrong position
    for (i = 0; i < 5; i++) {
        if (wordleChecker[i] == '_') {
            for (j = 0; j < 5; j++) {
                if (wordGuess[i] == wordleAnswer[j]) {
                    wordleChecker[i] = '?';
                }
            }
        }
    }

    // update hint array
    for (j = 0; j < 5; j++) {
        userHint[numberOfAttempts][j] = wordleChecker[j];
    }
    // print hint array
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", userHint[i][j]);
        }
        printf("\n");
    }

    // word comparator
    userIsCorrect = strcmp(wordleAnswer, wordleChecker);

    if (userIsCorrect == 0) {
        return 1;
    }

    return 0;
}


int main () {


    // initialize the array for holding the guesses
    char wordGuess[6];

    // initializing userGuess (6 attemps & 5-letter word)
    char userGuess[6][5];

    // initialize array for storing the hints each attempt
    char userHint[6][5];

    int numberOfAttempts = 0;

    // setting the default field
    int i, j, victory;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            userGuess[i][j] = '_';
            userHint[i][j] = '_';
        }
    }


    // Main Algorithm
    while (numberOfAttempts < 6) {

        // asks for user input then stores it in the wordGuess array
        printf("ENTER 5-LETTER WORD GUESS: ");
        scanf("%s", wordGuess);

        // convert to all caps
        for (i = 0; i < 5; i++) {
            wordGuess[i] = toupper(wordGuess[i]);
        }

        // check if the input has 5 letters
        if (strlen(wordGuess) != 5) {
            printf("INVALID INPUT. PLEASE ENTER A 5-LETTER WORD.\n");
        }

        else {

            printf("GUESSES: \n");
            
            // store the guessed word in the user guessed word array
            for (i = numberOfAttempts; i < 6; i++) {
                for (j = 0; j < 5; j++) {
                    if (i == numberOfAttempts) {
                        userGuess[i][j] == wordGuess[j];
                    }
                }
            }

            // print the user guesses
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 5; j++) {
                    printf("%c ", userGuess[i][j]);
                }
                printf("\n");
            }

            // printing the HINTS
            printf("HINTS\n");

            victory = playWordle(wordGuess, numberOfAttempts, userHint);

            numberOfAttempts += 1;

            if (victory == 1) {
                switch (numberOfAttempts)
                {
                case 1:
                    printf("WOW! Hole in one, you got the WORDLE in just one attempt!\n");
                    break;
                case 6:
                    printf("WHEW! That was tough, you got the WORDLE in your last guess!\n");
                    break;
                default:
                    printf("Great! You got the WORDLE after %d attempts\n", numberOfAttempts);
                    break;
                }
                break;
            }

            else if (numberOfAttempts == 6) {
                printf("SORRY! You didn't guess the WORDLE after six attempts");
                break;
            }

        }
    }
    
    return 0;
}