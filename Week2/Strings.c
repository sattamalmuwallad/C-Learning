#include <stdio.h>
#include <string.h>
int main(){
    char string[] = "Hello";
    printf("Length (strlen): %lu\n", strlen(string));  // Without null terminator
    printf("Size (sizeof): %lu\n", sizeof(string));    // With null terminator
    

    // strcpy()
    char cpy[10]; // has to be with enough size
    strcpy(cpy, string);
    printf("Copied string: %s \n", cpy); // common pitfall the output was Hello% with the null terminator
    //what we should do is 
    char sfcpy[6];
    strncpy(sfcpy, string, sizeof(sfcpy) - 1); // safe copy
    sfcpy[sizeof(sfcpy) - 1] = '\0'; // null terminator
    printf("Safe copied string is: %s\n", sfcpy);
    return 0;
}
