#include <stdio.h>

int main() {
    int days;
    printf("Number of days : ");
    scanf("%d", &days);
    float rainfall[3][days];
    for (int i = 0; i < days; i++) {
        printf("Enter the rainfall for Day %d\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("City %d : ", j + 1);
            scanf("%f", &rainfall[j][i]);
        }
    }
    for (int i = 0; i < days; i++) {
        printf("Day %d: \n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Rainfall for City %d : %.2f\n", j + 1, rainfall[j][i]);
        }
    }
    float variance[3];
    for (int i = 0; i < 3; i++) {
        float sum = 0;
        float variance_sum = 0;
        for (int j = 0; j < days; j++) {
            sum += rainfall[i][j];
            variance_sum += rainfall[i][j] * rainfall[i][j];
        }
        printf("Average Rainfall for City %d : %.2f\n", i + 1, sum / days);
        variance[i] = variance_sum / days - (sum / days) * (sum / days);
        printf("Variance for City %d : %.2f\n", i + 1, variance[i]);
    }
    return 0;
}