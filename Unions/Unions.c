// -- Unions -- //

#include <stdio.h>
#include <string.h>

// Union definition — all members share the same memory location
union Data {
    int i;
    float f;
    char str[20];
};

// MAIN FUNCTION //
int main() {
    union Data data;

    printf("Memory size occupied by union Data: %lu bytes\n", sizeof(data)); /* Output: 20 */

    // Storing integer value
    data.i = 10;
    printf("data.i = %d\n", data.i); /* Output: 10 */

    // Storing float value (overwrites previous data)
    data.f = 220.5;
    printf("data.f = %.1f\n", data.f); /* Output: 220.5 */
    printf("data.i is now corrupted: %d\n", data.i); /* Garbage value */

    // Storing string value (overwrites previous data)
    strcpy(data.str, "C Programming");
    printf("data.str = %s\n", data.str); /* Output: C Programming */
    printf("data.f is now corrupted: %.1f\n", data.f); /* Garbage value */

    return 0;
}
