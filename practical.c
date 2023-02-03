#include <stdio.h>

int main(){
    int n, i, j, temp;
    int arr[100];
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}