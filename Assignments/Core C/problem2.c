#include <stdio.h>

//Initialize amazeWOW
int amazeWOW(int i);
//Define amazeWOW
int amazeWOW(int i) {
	printf("amazeWOW:\t");
	for (i ; i <= 10; i++) {
		if (i % 2 == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

//Initialize amazeCOW
int amazeCOW(int i);
//Define amazeCOW
int amazeCOW(int i) {
	printf("amazeCOW:\t");
    start:
	if (i < 10 && i % 2 == 1)
    {
        printf("%d ", i);
        i++;
        goto start;
    }
    else if (i < 10)
    {
        i++;
        goto start;
    }
	printf("\n");
}

//Initialize amazeSOS
int amazeSOS(int i);
//Define amazeWOW
int amazeSOS(int i) {
	printf("amazeSOS:\t");
	while (i < 10)
    {
        if (i % 2 == 1)
        {
            printf("%d ", i);
            
        }
    i++;
    }
    printf("\n");
}

//Initialize amazeLOL
int amazeLOL(int i);
//Define amazeLOL
int amazeLOL(int i) {
	printf("amazeLOL:\t");
	do
    {
        if (i % 2 == 1)
        {
            printf("%d ", i);
            
        }
    i++;
    } while (i < 10);
    
	printf("\n");
}

//Initialize amazeXOX
int amazeXOX(int i);
//Define amazeXOX
int amazeXOX(int i) {
	printf("amazeXOX:\t");
    start:
    if (i % 2 == 1)
        {
            printf("%d ", i);
            
        }
        i++;
    if (i >= 10)
    {
        goto end;
    }
    else
    {
        goto start;
    }    
	end:
	printf("\n");
}

//Initialize amazeTOT
int amazeTOT(int i);
//Define amazeTOT
int amazeTOT(int i) {
    i++;
	printf("amazeTOT:\t");
    start:
	switch (i)
    {
    case 1:
        goto switch2;
    case 2:
        goto switch2;
    case 3:
        goto switch2;
    case 4:
        goto switch2;
    case 5:
        goto switch2;
    case 6:
        goto switch2;
    case 7:
        goto switch2;
    case 8:
        goto switch2;
    case 9:
        goto switch2;
    case 10:
        goto switch2;
    
    default:
        goto end;
    }
    
    switch2:
    int x;
    switch (x = i % 2)
    {
    case 0:
        goto count;
        
    case 1:
        goto print;
    
    default:
        printf("ERROR");
        goto end;
    }
    
    print:
    printf("%d ", i);
    goto count;

    count:
    i++;
    goto start;
    
    end:
	printf("\n");
}

int main(void){
    int i;
    i = 0;
    amazeSOS(i);
    amazeWOW(i);
    amazeCOW(i);
    amazeLOL(i);
    amazeXOX(i);
    amazeTOT(i);

    return 0;
}
