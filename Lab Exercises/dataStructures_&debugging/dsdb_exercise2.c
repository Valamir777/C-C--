#include <stdio.h>
#include <stdlib.h>

union IntBytes {
    int value;
    unsigned char bytes[sizeof(int)];
};

void intToHexString(int num, char *hexStr) {
    sprintf(hexStr, "0x%X", num);
}

int main() {
    union IntBytes intBytes;
    int r1; // Integer to be converted into byte form
    char *hexstr = (char*)malloc(10 * sizeof(char)); // Array to store hexadecimal as a char array (string)

    if (hexstr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Ask user to enter an integer
    printf("Enter an integer to be converted into bytes: ");
    // Scan for user response
    if (scanf("%d", &r1) != 1) {
        printf("Failed to read an integer.\n");
        free(hexstr);
        return EXIT_FAILURE;
    }

    intToHexString(r1, hexstr);
    intBytes.value = r1;

    printf("The hexadecimal form of the integer is: %s\n", hexstr);
    printf("The individual bytes of the integer are:\n");
    for (size_t i = 0; i < sizeof(int); ++i) {
        printf("byte %zu: 0x%02X\n", i, intBytes.bytes[i]);
    }
    free(hexstr);
    return EXIT_SUCCESS;
}

