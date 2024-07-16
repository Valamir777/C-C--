#include <iostream>
#include <stdio.h>
using namespace std;


// Parent Class
class Tool {
public:
    bool fight(Tool&); // Corrected declaration
    virtual const char* getName() const = 0; // Pure virtual function to get the name
protected:
    int *strength;
    char *type;
    Tool(int, char);
    ~Tool();
    void setStrength(int x);
};

// Subclasses
class Scissors : public Tool {
public:
    Scissors(int x) : Tool(x, 's') {}
    const char* getName() const override { return "Scissors"; }
};

class Paper : public Tool {
public:
    Paper(int x) : Tool(x, 'p') {}
    const char* getName() const override { return "Paper"; }
};

class Rock : public Tool {
public:
    Rock(int x) : Tool(x, 'r') {}
    const char* getName() const override { return "Rock"; }
};

// Functions
bool Tool::fight(Tool& other) {
    return *strength > *(other.strength);
}

void Tool::setStrength(int x) {
    strength = new int(x);
}

Tool::Tool(int sub_strength, char sub_type) {
    type = new char(sub_type);
    setStrength(sub_strength);
}

Tool::~Tool() {
    delete type;
    delete strength;
}

// Main
int main() {
	//menu data
	int selected = 0;
    char key;
	//player data
	int playerCount = 2;
	char playerChoice[playerCount];

    Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;

    return 0;
}
