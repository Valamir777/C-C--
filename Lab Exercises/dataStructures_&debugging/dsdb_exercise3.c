#include <stdio.h>
#include <stddef.h>

struct X {
    short s;
    int i;
    char c;
};

struct Y {
    int i;
    char c;
    short s;
};

struct Z {
    int i;
    short s;
    char c;
};

int main() {
    printf("Size of struct X: %zu\n", sizeof(struct X));
    printf("Size of struct Y: %zu\n", sizeof(struct Y));
    printf("Size of struct Z: %zu\n", sizeof(struct Z));

    // Example for struct X
    printf("Padding in struct X: %zu\n", sizeof(struct X) - (sizeof(short) + sizeof(int) + sizeof(char)));
    printf("Padding in struct Y: %zu\n", sizeof(struct Y) - (sizeof(short) + sizeof(int) + sizeof(char)));
    printf("Padding in struct Z: %zu\n", sizeof(struct Z) - (sizeof(short) + sizeof(int) + sizeof(char)));
    // Repeat for struct Y and Z

    return 0;
}
