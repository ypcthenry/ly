
#include<stdio.h>
#include<string.h>

#define true 1
#define false 0

typedef int bool;
typedef unsigned char u8;


bool IsSpace(u8 c){
    u8 space[]=" \t";
    int index;

    for(index=0;index<strlen(space);index++){
        if(c==space[index])
            return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    char c=' ';
    if(IsSpace(c))
	printf("'%d'是空格\n",c);
    return 0;
}

