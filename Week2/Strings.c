#include <stdio.h>
#include <string.h>
int main(){
    char string[] = "Hello";
    printf("Length (strlen): %lu\n", strlen(string));  // Without null terminator
    printf("Size (sizeof): %lu\n", sizeof(string));    // With null terminator
    return 0;
}