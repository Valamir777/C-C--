//Fix the following code so that it creates a string str and copies “hakuna matata!” into it.
//#include <stdio.h>

//void main() {
//	char str[];
//	???(, "hakuna matata!"); // this line should copy "hakuna matata!"
//	                         // into our char array
//	printf("%s\n", str);
	// Anything else?
//}

//#include <stdio.h>
//#include <string.h>

//void main() {
//    char str[20];

//	strcpy(str, "hakuna matata!"); // this line should copy "hakuna matata!"
//	                         // into our char array
//	printf("%s\n", str);
	// Anything else?
//}

//After confirming your fix works, change the code to use heap memory instead of the stack. Remember, everything you malloc you must also free!

#include <stdio.h>
#include <string.h>

void main() {
    char str[20];
	

	strcpy(str, "hakuna matata!"); // this line should copy "hakuna matata!"
	                         // into our char array
	printf("%s\n", str);
	// Anything else?
}