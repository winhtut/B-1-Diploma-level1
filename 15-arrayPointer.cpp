//
// Created by National Cyber City on 11/22/2022.
//

#include "stdio.h"

void swap(int *d1 , int *d2);
int main(){

    int data1=10;
    int data2 = 20;
    printf("data 1 : %d\ndata 2: %d\n",data1,data2);
    swap(&data1, &data2); // pass by reference

    printf("data 1 : %d\ndata 2: %d",data1,data2); // 20 10

    return 0;
}
void swap(int *d1 , int *d2){ // pass by value

    int tempo;
    tempo = *d1; //10
    *d1 = *d2; // 20
    *d2 = tempo; // 10

}