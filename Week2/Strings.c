/* UPDATED STRING FUNCTIONS CODE WITH COMMENTS AND PITFALLS */
#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "Hello";

    // strlen() - Length excluding null terminator
    printf("Length (strlen): %lu\n", strlen(string));  // Output: 5

    // sizeof() - Size including null terminator
    printf("Size (sizeof): %lu\n", sizeof(string));    // Output: 6

    //----------------------------
    // strcpy() - Copy string
    //----------------------------
    char cpy[10]; // ✅ Sufficient space to hold "Hello" + '\0'
    strcpy(cpy, string); 
    printf("Copied string: %s\n", cpy);  // ✅ Output: Hello

    // 🚫 Pitfall: If cpy was too small, buffer overflow could occur.

    //----------------------------
    // strncpy() - Safer copy with size limit
    //----------------------------
    char sfcpy[6];
    strncpy(sfcpy, string, sizeof(sfcpy) - 1);  // ✅ Copies up to 5 chars
    sfcpy[sizeof(sfcpy) - 1] = '\0';           // ✅ Ensure null termination
    printf("Safe copied string: %s\n", sfcpy);  // Output: Hello

    //----------------------------
    // strcat() - String concatenation
    //----------------------------
    char greeting[15] = "Hello";  // ✅ Enough space for concatenation
    char suffix[] = " World";
    strcat(greeting, suffix);      // ✅ greeting = "Hello World"
    printf("Concatenated string: %s\n", greeting); // Output: Hello World

    // 🚫 Pitfall: If greeting had less space, strcat would cause overflow.

    //----------------------------
    // strncat() - Safer concatenation with limit
    //----------------------------
    char safe_concat[12] = "Hi";
    strncat(safe_concat, " There", sizeof(safe_concat) - strlen(safe_concat) - 1); // ✅ Prevents overflow
    printf("Safe concatenated string: %s\n", safe_concat);  // Output: Hi There

    //----------------------------
    // strlen() - Getting string length
    //----------------------------
    printf("Length of 'Hello': %lu\n", strlen("Hello")); // Output: 5

    //----------------------------
    // strcmp() - Compare two strings
    //----------------------------
    printf("Comparing 'apple' & 'apple': %d\n", strcmp("apple", "apple"));  // Output: 0 (equal)
    printf("Comparing 'apple' & 'banana': %d\n", strcmp("apple", "banana")); // <0 (apple < banana)
    printf("Comparing 'banana' & 'apple': %d\n", strcmp("banana", "apple")); // >0 (banana > apple)

    //----------------------------
    // strncmp() - Compare up to n characters
    //----------------------------
    printf("strncmp('application', 'apple', 3): %d\n", strncmp("application", "apple", 3)); // 0 (first 3 chars match)
    printf("strncmp('app', 'apple', 5): %d\n", strncmp("app", "apple", 5));               // <0 (app is shorter)

    //----------------------------
    // Common Pitfalls Recap:
    //----------------------------
    // 🚫 Forgetting to allocate enough space leads to buffer overflows.
    // 🚫 Assuming strncpy() always null-terminates (it doesn't if source is longer).
    // 🚫 Using strcat() without verifying destination size can corrupt memory.

    return 0;
}
