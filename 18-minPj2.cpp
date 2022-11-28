//
// Created by National Cyber City on 11/22/2022.
//

#include "stdio.h"


int main(){


    int num=0;
    FILE *fptr;
    fptr = fopen("winhtut1.txt" , "a");

    if(fptr == NULL){

        printf("[-]File cannot open!");
    } else{


        printf("Enter a number:");
        scanf("%d",&num);

        fprintf(fptr ,"%d%c" , num,'\n');

        fclose(fptr);
    }


}