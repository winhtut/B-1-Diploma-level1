//
// Created by National Cyber City on 11/7/2022.
//

#include "stdio.h"

int main(){

    int age=0;
    printf("Enter your age:");
    scanf("%d",&age); // 18 c

    if(age > 20){
        printf("Your age is over 20:\n");
        printf("Your age is over 20:\n");
        printf("Your age is over 20:\n");
        printf("Your age is over 20:\n");
        printf("Your age is over 20:\n");
        printf("Your age is over 20:\n");
    } else if(age > 18 && 25<=age ){
        printf("Your age is equal: 18 and less than 20 \n");
        printf("Your age is equal: 18 and less than 20 \n");
        printf("Your age is equal: 18 and less than 20 \n");
        printf("Your age is equal: 18 and less than 20 \n");
        printf("Your age is equal: 18 and less than 20 \n");
        printf("Your age is equal: 18 and less than 20 \n");
    } else if(age < 20  && age!=18 ){ //
        printf(" YOur age is under 20:\n");
    } else{
        printf(" This is your age: %d",age);
    }



    return 0;
}