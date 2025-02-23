#include <stdio.h>

int main() {
    int x = 42;
    int *ptr = &x;  // ptr points to x

    printf("Value of x: %d\n", x);         // 42
    printf("Address of x: %p\n", &x);      // e.g., 0x7ffe...
    printf("Value stored in ptr: %p\n", ptr);  // Same as &x
    printf("Value pointed by ptr: %d\n", *ptr); // 42 (dereferencing ptr)

    return 0;
}
