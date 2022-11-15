//
// Created by National Cyber City on 11/8/2022.
//

#include "stdio.h"

int main(){
    int i=0;

    int w=100;
    while (i < w){
        i = i+2;

       if(i==30){
           printf("I =30 we found:\n");
           i=100;
       } else if(i == 15){
           printf("i =15 ; \n");
           i= i-14 ;
       }
        printf(" %d Hello This is from NCC\n",i);
    }

    return 0;
}

