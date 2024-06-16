#include <stdio.h>

int main(int argc, char ** argv){
    int i = 1;
    //initiate loop with start:
    start:
    if (argc > i)
    {
        printf("%s\n", argv[i]);
        i++;
        goto start;
    }
    else
    {
        goto end;
    }
    
    //The following code was to be changed using if and goto

    //for (int i = 1; i < argc; i++) {
    //    printf("%s\n", argv[i]);
    //}
    end:
    return 0;
}