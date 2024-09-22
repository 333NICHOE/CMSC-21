#include <stdio.h>

// Recursive function
double populationGrowth(double population, double growthRate, int growthYears) {
    
    // Base Case
    if (growthYears == 0) {
        return population;
    }

    // Main Algorithm
    else {
        double updatedPopulation = population * (1 + (growthRate/100));
        return populationGrowth(updatedPopulation, growthRate, growthYears - 1);
    }
    
}



int main () {

    double population;
    double growthRate;
    int growthYears;

    printf("Population (n): ");
    scanf("%lf", &population);
    printf("Growth Rate (y%%): ");
    scanf("%lf", &growthRate);
    printf("Growth Years (x): ");
    scanf("%d", &growthYears);

    double resultingGrowthPopulation = populationGrowth(population, growthRate, growthYears);
    printf("After %d years at %.0lf%% growth rate, the population will be %f", growthYears, growthRate, resultingGrowthPopulation);

    return 0;
}