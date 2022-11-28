//
// Created by National Cyber City on 11/21/2022.
//

#include "stdio.h"

//int main(){
//
////    int *p , data;
//
////    data = 100;
////
////    p = &data;
////
////    data = 10;
////
////    printf("%d",data);
////    printf(" pointer %d",*p);
//
//
//    return 0;
//}


/*C program to change the value of constant integer using pointers.*/

//#include <stdio.h>
//
//int main()
//{
//    const int a=10;     //declare and assign constant integer
//    int *p;             //declare integer pointer
//    p=&a;               //assign address into pointer p
//
//    printf("Before changing - value of a: %d",a);
//
//    //assign value using pointer
//    *p=20;
//
//    printf("\nAfter  changing - value of a: %d",a);
//    printf("\nWauuuu... value has changed.");
//
//    return 0;
//}

#include "stdio.h"

int main(){

    int i , data[10] , total=0;

    printf("Enter 10 Number:");

    for(i=0; i<10 ; i++){

        scanf("%d",data+i);

        // &data[i]

       total += *(data+i);

        // total +=data[i];

    }

    printf("Total Number =%d\n",total);


    for(int x=0 ; x<10 ; x++){

        printf(" Data at index = %d : memaddr=%X\n",data[x],&data[x]);

    }



    return 0;
}

