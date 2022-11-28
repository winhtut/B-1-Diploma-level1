//
// Created by National Cyber City on 11/21/2022.
//

#include "stdio.h"

int main(){

    char data[6]={'a','e','i','o','u','x'};

    char *ptr;

    ptr= &data[3];

    printf(" Pointer value = %d\n",*ptr); // 40
    printf(" Pointer(ptr+1) value = %c\n",*(ptr+2)); // 50 YTT  furry33 41 HMA 50
    printf(" Pointer(ptr-1) value = %c\n",*(ptr-2)); //

    return 0;
}
