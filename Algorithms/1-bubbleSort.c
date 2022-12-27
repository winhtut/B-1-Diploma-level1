//
// Created by National Cyber City on 12/26/2022.
//
// bubble sort


#include "stdio.h"

void bubbleSort(int data[] ,int  size ){

    for(int i=0; i < size-1 ;++i ){

        for( int j=0 ; j< size-i-1 ; ++j ){

            if( data[j] > data[j+1]){

                int temp = data[j];

                data[j] = data[j+1];

                data[j+1] = temp;

            }


        }

    }

}
//{5 , 3, 10 , 12 , 8,7,15,  11,4,20}
int main(){
    int data[]={5 , 12, 3 , 10 , 15 , 8 , 7 ,  20,11,4};

    int size  = sizeof(data) / sizeof (data[0]);

    printf("size of arr %d\n",size);

    bubbleSort(data , size);


    for (int i = 0; i <size; ++i) {

        printf("%d : ",data[i]);
    }

    return 0;
}