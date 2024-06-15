//Учитывая массив данных[] длины N : a) Напишите функцию поиска(value), 
//которая возвращает местоположение (индекс) значения value в массиве, 
//если оно существует, за O(N) времени. б) Предположим, что элементы вашего 
//массива сопоставимы и что вам предоставлена функция сортировки. Напишите 
//функцию binary_search(value), которая занимает O(log N ) времени.

// a) Функция линейного поиска (O(N) временная сложность):
#include <stdio.h>

int search(int data[], int N, int value) {
    for (int i = 0; i < N; i++) {
        if (data[i] == value) {
            return i; // Return the index if value is found
        }
    }
    return -1; // Return -1 if value is not found
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int N = 5;
    int value = 30;
    
    int index = search(data, N, value);
    
    if (index != -1) {
        printf("Value found at index: %d\n", index);
    } else {
        printf("Value not found in the array\n");
    }
    
    return 0;
}

// б) Функция двоичного поиска (временная сложность O(log N)):
#include <stdio.h>

int binary_search(int data[], int N, int value) {
    int low = 0;
    int high = N - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (data[mid] == value) {
            return mid; // Return the index if value is found
        } else if (data[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1; // Return -1 if value is not found
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int N = 5;
    int value = 30;
    
    int index = binary_search(data, N, value);
    
    if (index != -1) {
        printf("Value found at index: %d\n", index);
    } else {
        printf("Value not found in the array\n");
    }
    
    return 0;
}
