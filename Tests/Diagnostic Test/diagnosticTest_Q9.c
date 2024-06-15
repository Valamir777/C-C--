//Напишите функцию print_permutations(n), 
//которая выводит все перестановки натурального 
//числа от 1 до n в стандартном (возрастающем) 
//порядке. Например, print_permutations(3) 
//должна выводить следующее:

#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
    } else {
        for (int i = l; i <= r; i++) {
            swap((str + l), (str + i));
            permute(str, l + 1, r);
            swap((str + l), (str + i)); // backtrack
        }
    }
}

void print_permutations(int n) {
    char *numbers = (char *)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        numbers[i] = '1' + i;
    }
    numbers[n] = '\0';
    
    permute(numbers, 0, n - 1);
    
    free(numbers);
}

int main() {
    int n = 3;
    print_permutations(n);
    
    return 0;
}
