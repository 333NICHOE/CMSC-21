#include <stdio.h>
#include <stdlib.h>

int main () {

    int *p;

    p = (int*)malloc(sizeof(int));
    
    *p = 3;

    printf("Enter replacement value of %d: ", *p);
    scanf("%d", p);

    printf("Replacement value: %d \n", *p);

    printf("Replacement value of %d: ", *p);

    free(p);

    printf("Replacement value of %d: ", *p);


    return 0;
}