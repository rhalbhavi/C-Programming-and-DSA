// -- Array of Unions -- //

#include <stdio.h>

// Union representing different data types
union Value {
    int i;
    float f;
    char c;
};

// MAIN FUNCTION //
int main() {
    union Value arr[3];

    // Store different types in each array element
    arr[0].i = 42;
    arr[1].f = 3.14f;
    arr[2].c = 'Z';

    printf("Array of Unions:\n");
    printf("arr[0] as int:   %d\n", arr[0].i);   /* Output: 42 */
    printf("arr[1] as float: %.2f\n", arr[1].f); /* Output: 3.14 */
    printf("arr[2] as char:  %c\n", arr[2].c);   /* Output: Z */

    return 0;
}
