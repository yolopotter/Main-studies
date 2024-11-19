#include <stdio.h>

int main() {
    if (sizeof(void*) == 4) {
        printf("This system is 32-bit.\n");
    } else if (sizeof(void*) == 8) {
        printf("This system is 64-bit.\n");
    } else {
        printf("Unknown architecture.\n");
    }

    return 0;
}
