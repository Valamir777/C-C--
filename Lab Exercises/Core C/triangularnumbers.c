#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void) {
    
    
    
    //Requestion by print the value of triNum from the user with input
    int triNum;
    printf("Type a whole number: \n");
    scanf("%d", &triNum);
    int triNums[triNum];
    int x = 0;
    // Iterate through the values of triNum
    for (int i_triNum = 0; i_triNum < triNum; i_triNum++)
    {
        // check if integer not 0
        if (i_triNum != 0)
        {
            //create value squarenum
            int squareNum = 8 * (i_triNum + 1);
            //check if squareNum is a square number
            double square = sqrt(squareNum);
            //check if square is a whole number and if when
            //multiplied by itself it equals squareNum
            if (floor(square) == square && (square * square) == squareNum)
            {
                triNums[x] = i_triNum;
                x++;
            }
            else
            {
                goto skip;
            }

        }
        else
        {
            skip:
            continue;
        }
    }
    for(int y = 0; y < x; y++)
    {
        printf("%d ", triNums[y]);
    }
    return 0;
}