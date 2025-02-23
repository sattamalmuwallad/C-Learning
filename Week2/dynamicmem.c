/* DIFFERENCE BETWEEN malloc, calloc, realloc WITH SIMPLE EXAMPLES AND DIAGRAMS */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;

    //----------------------------
    // 1️⃣ malloc: Allocates uninitialized memory
    //----------------------------
    int *malloc_arr = (int *)malloc(5 * sizeof(int));  // Allocates memory for 5 integers

    if (malloc_arr == NULL) {
        printf("malloc failed!\n");
        return 1;
    }

    printf("\n 1️⃣ malloc - Uninitialized Memory:\n");
    for (i = 0; i < 5; i++) {
        printf("malloc_arr[%d] = %d (garbage value)\n", i, malloc_arr[i]);  // May contain garbage
    }

    //----------------------------
    // 2️⃣ calloc: Allocates memory and initializes it to zero
    //----------------------------
    int *calloc_arr = (int *)calloc(5, sizeof(int));  // Allocates and zeros out memory

    if (calloc_arr == NULL) {
        printf("calloc failed!\n");
        return 1;
    }

    printf("\n2️⃣ calloc - Zero Initialized Memory:\n");
    for (i = 0; i < 5; i++) {
        printf("calloc_arr[%d] = %d\n", i, calloc_arr[i]);  // All zeros
    }

    //----------------------------
    // 3️⃣ realloc: Resizes previously allocated memory
    //----------------------------
    printf("\n3️⃣ realloc - Resizing malloc_arr from 5 to 8 integers:\n");
    malloc_arr = (int *)realloc(malloc_arr, 8 * sizeof(int));  // Resize to hold 8 integers

    if (malloc_arr == NULL) {
        printf("realloc failed!\n");
        return 1;
    }

    // Initialize newly allocated elements
    for (i = 5; i < 8; i++) {
        malloc_arr[i] = i * 10;  // Assign values to new slots
    }

    for (i = 0; i < 8; i++) {
        printf("malloc_arr[%d] = %d\n", i, malloc_arr[i]);
    }

    //----------------------------
    // 🔑 Free allocated memory to avoid memory leaks
    //----------------------------
    free(malloc_arr);
    free(calloc_arr);

    return 0;
}

/*
📝 OUTPUT EXPLANATION:
1️⃣ malloc - Uninitialized Memory:
malloc_arr[0] = 32767 (garbage value)
malloc_arr[1] = -21000 (garbage value)
...

2️⃣ calloc - Zero Initialized Memory:
calloc_arr[0] = 0
calloc_arr[1] = 0
...

3️⃣ realloc - Resizing malloc_arr from 5 to 8 integers:
malloc_arr[0] = 32767 (previous garbage or initialized value)
malloc_arr[5] = 50 (newly assigned value)
malloc_arr[6] = 60
malloc_arr[7] = 70
*/

/*
📊 DIAGRAMS:

🟢 malloc (5 integers):
[??][??][??][??][??]  -> Uninitialized (garbage values)

🔵 calloc (5 integers):
[0][0][0][0][0]  -> Zero-initialized memory

🟡 realloc (after resizing to 8 integers):
Before: [??][??][??][??][??]
After:  [??][??][??][??][??][50][60][70] -> Old data preserved, new space added
*/
