#include <iostream>
using namespace std;
#include <conio.h> // For _getch() and _kbhit()

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

void printMenu(int selected) {
    string options[3] = {"Rock", "paper", "Scissors"};
    for (int i = 0; i < 3; ++i) {
        if (i == selected) {
            cout << "> " << options[i] << " <" << endl;
        } else {
            cout << "  " << options[i] << "  " << endl;
        }
    }
}

// Main
int main() {
	//menu data
	int selected = 0;
    char key;
	//player data
	int playerCount = 2;
	int playerChoice[playerCount];

	//strength values of options
    Scissors s1(5);
    Paper p1(7);
    Rock r1(15);

	for (int i = 0; i < playerCount; i++)
	{
			cout << "Use left and right arrow keys to navigate and press Enter to select an option." << endl;

		while (true) {
        	system("cls"); // Clear the console
        	printMenu(selected);
        	key = _getch(); // Get the pressed key
        	if (key == 13) { // Enter key
            	cout << "You selected: " << selected + 1 << endl;
				playerChoice[i] = selected+1;
            	break;
        	} else if (key == 75) { // Left arrow key
            	selected = (selected - 1 + 3) % 3;
        	} else if (key == 77) { // Right arrow key
            	selected = (selected + 1) % 3;
        	}
    	}
	}

	//implement fight

    cout << (s1.fight(p1) ? s1.getName() : p1.getName()) << " beats " << (s1.fight(p1) ? p1.getName() : s1.getName()) << endl;
    cout << (p1.fight(s1) ? p1.getName() : s1.getName()) << " beats " << (p1.fight(s1) ? s1.getName() : p1.getName()) << endl;

    return 0;
}
