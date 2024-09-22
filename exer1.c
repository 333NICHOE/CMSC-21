#include <stdio.h>

int main() {

    int units = 0;
    float grades = 0;
    int totalUnits = 0;
    float GWA = 0.0;
    int counter = 0;

    while (counter != 5)
    {
        printf("Enter Units: ");
        scanf("%d", &units);

        if (units == 0) {
        break;
        }

        printf("Enter Grade: ");
        scanf("%f", &grades);

        totalUnits += units;
        //printf("current units: %d \n", totalUnits);

        GWA += (grades * units);

        //printf("current GWA: %f \n", GWA);

        counter++;
    }

    float totalGWA = GWA/totalUnits;
    printf("GWA: %f", totalGWA);
    printf("Total Units: %d", totalUnits);

    return 0;
}