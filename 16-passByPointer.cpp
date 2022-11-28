//
// Created by National Cyber City on 11/22/2022.
//
#include "stdio.h"
void passByPointer(int *value);
int main(){

    int *p ;
    int data=20;

    p = &data;

    passByPointer(p);
    printf("value of pointer %d\n",*p);
    printf("value of pointer %d",data);

    return 0;
}

void passByPointer(int *value){

    (*value)++;

}
