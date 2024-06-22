//Use pointers and addresses to modify the code so x is passed by reference 
//instead and is squared. This will involve changes to the square function 
//that does not involve changing void to int and giving square a return statement. 
//Make sure your code compiles with -Wall flag without warnings.

#include <stdio.h>
#include <stdlib.h>

void square(int *pointer);

//void square(int num) {
//	num = num * num;
//}

int main() {
	int x = 4;
    int *pointer;
    pointer = (int*)malloc(sizeof(int));
    *pointer = x;
	square(pointer);
	printf("%d\n", *pointer);
	return 0;
}

//int main() {
//	int x = 4;
//	square(x);
//	printf("%d\n", x);
//	return 0;
//}

void square(int *pointer) {
	*pointer = *pointer * *pointer;
}