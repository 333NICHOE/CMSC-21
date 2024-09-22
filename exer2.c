#include <stdio.h>

void programMenu() {
    printf("1 - Measure in Metric\n");
    printf("2 - Measure in Standard\n");
    printf("3 - Exit\n");
}

float metricBMI(float kilograms, float meters) {
    float bmi = kilograms / (meters * meters);
    return bmi * 10000;
}

float standardBMI(float pounds, int feet, int inches) {
    float totalHeight = (feet * 12) + inches;
    float bmi = pounds / ((totalHeight * totalHeight)) * 703;
    return bmi * 10000;
}

int bmiClassification(int bmi) {
    if (bmi < 18.5) {
        printf("Underweight\n");
    }

    else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("Normal\n");
    }

    else if (bmi >= 25 || bmi <= 29.9) {
        printf("Overweight\n");
    }

    else {
        printf("Obese\n");
    }
}

int main() {

    programMenu();
    int choice = 0;
    int repeat = 1;
    while (repeat == 1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter your weight in kilograms: ");
                float kilograms = 0.0;
                scanf("%f", &kilograms);
                printf("Enter your height in meters: ");
                float meters = 0.0;
                scanf("%f", &meters);
                float bmiMetric = metricBMI(kilograms, meters);
                printf("Your BMI is: %f\n", bmiMetric);
                printf("Your BMI classification is: ");
                bmiClassification(bmiMetric);
                break;
            case 2:
                printf("Enter your weight in pounds: ");
                float pounds = 0.0f;
                scanf("%f", &pounds);
                printf("Enter your height in feet: ");
                int feet = 0;
                scanf("%d", &feet);
                printf("Enter your height in inches: ");
                int inches = 0;
                scanf("%d", &inches);
                float bmiStd = standardBMI(pounds, feet, inches);
                printf("Your BMI is: %f\n", bmiStd);
                printf("Your BMI classification is: ");
                bmiClassification(bmiStd);
                break;
            case 3:
                printf("Thank you for using my program! \n");
                break;
    }
    return 0;
}
}
