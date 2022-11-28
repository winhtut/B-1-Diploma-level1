//
// Created by National Cyber City on 11/21/2022.
//

#include "stdio.h"

int main(){

    int age=20;

    int age2=23;
    int age3=28;

    int *p = &age; // address of f82c->20

    printf("Hello C");
    printf("Address of age %X\n",&age);


    printf("Pointer %d\n",*p);
    printf("Pointer Address %X",p);


    return 0;
}

// Pointer store address of another variable.