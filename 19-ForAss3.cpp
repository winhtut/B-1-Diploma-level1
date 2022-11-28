//
// Created by National Cyber City on 11/28/2022.
//

#include "stdio.h"
#include "stdlib.h"
void dataInsertToFile();
void loading();
void printDataFromArray();

char arr[100];
int main(){

    dataInsertToFile();
    loading();
    printDataFromArray();


    return 0;
}

void dataInsertToFile(){

    FILE *fptr;
    fptr =fopen("ass3.txt","w" );
    fclose(fptr);

    FILE *fptr1;
    fptr1 =fopen("ass3.txt","a" );

    if(fptr1==NULL){

        printf("file cannot open");
        exit(1);
    } else{
        for(int i=1; i<=100 ; i++){

            fprintf(fptr,"%d\n",i);

        }
        fclose(fptr1);
    }

}

void loading(){
    int index=0;
    FILE *fptr;
    fptr = fopen("ass3.txt","r");
    int data=0;
    while (fscanf(fptr,"%d",data)==1){
        arr[index]=data;
        index++;
    }
    fclose(fptr);

}

void printDataFromArray(){

    for(int i=0; i<100 ; i++){

        printf("data:%d\n",arr[i]);
    }
}