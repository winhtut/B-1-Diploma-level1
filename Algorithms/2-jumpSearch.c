//
// Created by National Cyber City on 12/27/2022.
//

// jump search lesson


#include "stdio.h"
#include "math.h"
int nextStep =3;

int min(int first , int second){

    if( second > first){
        return first;
    } else{
        return second;
    }

}

int jumpSearch(int arr[] , int size , int key){



    int previous = 0;


    while ( arr[min(nextStep , size)-1] < key ){



            previous = nextStep ;

            nextStep += 3 ;

            if(previous>= size ){
                return -1;
            }

    }


    for(int j = previous ; j< nextStep ; j++){

            if( arr[j] == key){

                return j;
            }


    }

    return -1;

}


int main(){

    int arr[]= {1,2,3,4,5,6,7,8,9,100,101,102};

    int size = sizeof(arr)/sizeof(arr[0]);

    int toFind = 2 ;

    int indexNumber = jumpSearch(arr , size , toFind);

    if( indexNumber != -1){
        printf("We found\n");
        printf("found at index %d   data : %d ",indexNumber , arr[indexNumber]);
    } else{

        printf("Not found!\n");
    }

    return 0;
}