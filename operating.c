#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter the number of proccesses: ");
    scanf("%d", &n);

    int * arr = malloc(n * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    
    printf("arr Elements:");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}