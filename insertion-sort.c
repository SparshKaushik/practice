#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        while (temp < arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    printf("Sorted Array : ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}