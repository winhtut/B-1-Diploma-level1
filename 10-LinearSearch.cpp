//
// Created by National Cyber City on 11/15/2022.
//

#include "stdio.h"

int main(){

    int myArr[12]={10,20,30,40,50,60,70,20,80,90,100,20};
    int loc[10];
    int toFind = 20;
    int count=0;

    for(int i=0; i<12 ; i++){

        if(myArr[i]==toFind){
            loc[count]=i;
            count++;
            printf("We found At %d\n",i);


        }
    }
    if(count==0){
        printf("NOt found:\n");
    } else{
        printf("We Found:\n");
    }

    return 0;
}

