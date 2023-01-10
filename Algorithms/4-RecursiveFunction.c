//
// Created by National Cyber City on 1/10/2023.
// Recursive function
#include "stdio.h"


unsigned long long int factorail(unsigned int a){ // 3 // 2 //1
    // terminating point
    if( a <= 1){
        return 1;
    }

    return a* factorail(a-1);
    //     4 *  3 *  2 * 1

}


int main(){
    int fact=0;
    for(int i=0; i<5 ; i++){

        printf("Enter some number to find factorial value:");
        scanf("%d",&fact);

        printf("Over value := %u\n", factorail(fact));

    }

    return 0;
}

