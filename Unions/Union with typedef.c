// -- Union using typedef -- //

#include <stdio.h>

// Union with typedef
typedef union {
    int integer;
    float decimal;
    char character;
} MyUnion;

// MAIN FUNCTION //
int main() {
    MyUnion u;

    u.integer = 65;
    printf("As integer: %d\n", u.integer);    /* Output: 65 */
    printf("As character: %c\n", u.character); /* Output: A (ASCII 65) */

    u.decimal = 3.14;
    printf("As float: %.2f\n", u.decimal);    /* Output: 3.14 */

    return 0;
}
