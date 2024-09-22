#include <stdio.h>
#include <stdlib.h>


// Gets the x and y input 
void getInput (int *x, int *y) {

    printf("Enter value of x: ");
    scanf("%d", x);

    printf("Enter value of y: ");
    scanf("%d", y);
}

// Swaps the value of x and y if x is greater
void swapValues (int *x, int *y) {

    int temp;

    // checker
    if (*x > *y) {
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

int primeChecker (int n) {

    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

void getLargest(int *x, int *y, int *l1, int *l2, int *l3, int *count) {

    *count = 0;
    *l1 = -1;
    *l2 = -1;
    *l3 = -1;


    // Checks all the values in range
    for (int i = *x; i <= *y; i++ ) {

        // Checks if prime
        if (primeChecker(i)) {
            
            (*count)++;
            
            if (i > *l1) {
                *l3 = *l2;
                *l2 = *l1;
                *l1 = i;
            }

            else if (i > *l2) {
                *l3 = *l2;
                *l2 = i;
            }

            else if (i > *l3) {
                *l3 = i;
            }
        }
    }
}

void printLargest (int *l1, int *l2, int *l3, int *count) {
    printf("Number of primes: %d\n", *count);
    printf("The three largest prime numbers are: [%d], [%d], [%d]", *l1, *l2, *l3);
}

int main () {

    int x, y, l1, l2, l3, count;


    getInput(&x, &y);
    swapValues(&x, &y);

    getLargest(&x, &y, &l1, &l2, &l3, &count);
	printLargest(&l1, &l2, &l3, &count);


    return 0;
}