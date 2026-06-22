// -- Union with Pointers -- //

#include <stdio.h>

union Data {
    int i;
    float f;
};

// MAIN FUNCTION //
int main() {
    union Data data;
    union Data *ptr;

    data.i = 100;
    ptr = &data;

    printf("Accessing union members using pointer:\n");
    printf("ptr->i = %d\n", ptr->i);     /* Output: 100 */

    ptr->f = 99.99;
    printf("ptr->f = %.2f\n", ptr->f);   /* Output: 99.99 */
    printf("(*ptr).i = %d (corrupted)\n", (*ptr).i); /* Garbage value */

    return 0;
}
