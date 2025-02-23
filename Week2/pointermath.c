/* POINTER ARITHMETIC EXAMPLES WITH SIMPLE COMMENTS */
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};  // An integer array
    int *ptr = arr;  // Pointer points to the first element of arr

    // Print the value and address of the first element
    printf("Value at ptr: %d, Address: %p\n", *ptr, (void *)ptr);

    // Move the pointer to the next element (arr[1])
    ptr++;
    printf("After ptr++: Value: %d, Address: %p\n", *ptr, (void *)ptr);

    // Move pointer two elements forward (arr[3])
    ptr += 2;
    printf("After ptr += 2: Value: %d, Address: %p\n", *ptr, (void *)ptr);

    // Move pointer back by one element (arr[2])
    ptr--;
    printf("After ptr--: Value: %d, Address: %p\n", *ptr, (void *)ptr);

    // Difference between two pointers (number of elements apart)
    int diff = &arr[4] - &arr[1];
    printf("Elements between arr[4] and arr[1]: %d\n", diff);  // Expected: 3

    // Demonstrating pointer with a char array (byte-level movement)
    char chars[] = {'A', 'B', 'C', 'D', 'E'};
    char *cptr = chars;  // Points to 'A'
    printf("Char at cptr: %c, Address: %p\n", *cptr, (void *)cptr);

    cptr++;  // Move to the next character (1 byte forward)
    printf("After cptr++: Char: %c, Address: %p\n", *cptr, (void *)cptr);

    // Pointer difference with chars (still in elements, not bytes)
    int char_diff = &chars[4] - &chars[1];
    printf("Elements between chars[4] and chars[1]: %d\n", char_diff);  // Expected: 3

    return 0;
}