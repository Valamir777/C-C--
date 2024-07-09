#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

char GRADE_MAP[] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

class Grade {
    int * percentage;
    char * letter;

public:
    Grade(int, char); //constructor
    ~Grade(); // deconstructor

    void setByPercent(int p);
    void setByLetter(char c);
    void print();

};

void Grade::setByPercent(int p) {
    *percentage = p;
    *letter = GRADE_MAP[p / 10];

    

}

void Grade::setByLetter(char c) {
    *letter = c;
    *percentage = 100 - (*letter - 'A') * 10 - 5;
}

void Grade::print() {
    cout << *percentage << " :: " << *letter << endl;
}

Grade::Grade(int p, char l){
    percentage = new int;
    letter = new char;
    *percentage = p;
    *letter = l;
}

Grade::~Grade(){
    delete percentage;
    delete letter;
}

int main() {
	char letter;
	int percent;
    Grade g(percent, letter);
	
	printf("Enter two grades separated by a space. Use a percentage for the first and letter for the second: ");
	scanf("%d", &percent);
	scanf("\n");
	
	g.setByPercent(percent);
	g.print();
	
	g.setByLetter(getchar());
	g.print();

	return 0;
}