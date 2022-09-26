#include <stdio.h>

int main() {
    float city1, city2, city3;
    float rainfall[3][7];
    for (int i = 0; i < 7; i++) {
        printf("Enter the rainfall for Day %d\n", i + 1);
        printf("Enter rainfall for city 1: ");
        scanf("%f", &rainfall[0][i]);
        printf("Enter rainfall for city 2: ");
        scanf("%f", &rainfall[1][i]);
        printf("Enter rainfall for city 3: ");
        scanf("%f", &rainfall[2][i]);
    }
    for (int i = 0; i < 7; i++) {
        printf("Day %d: \n", i + 1);
        printf("Rainfall for city 1: %f\n", rainfall[0][i]);
        printf("Rainfall for city 2: %f\n", rainfall[1][i]);
        printf("Rainfall for city 3: %f\n", rainfall[2][i]);
    }
}