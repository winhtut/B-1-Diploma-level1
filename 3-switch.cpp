//
// Created by National Cyber City on 11/7/2022.
//

#include "stdio.h"

int main(){

    char oneword;
    printf("this is switch case break program:\n");

    printf("Enter your char:");
    scanf(" %c",&oneword);


    switch (oneword) {
        case 'a':
            printf(" This is a:\n");
            break;
        case 'b':
            printf(" This is b:\n");
            break;
        case 'c':
            printf(" This is c:\n");
            break;
        default:
            printf(" Nothing:\n");

    }

    return 0;
}
