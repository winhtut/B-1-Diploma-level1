//
// Created by National Cyber City on 11/14/2022.
//

#include "stdio.h"
#include "time.h"
#include "stdlib.h"

int main(){
    srand(time(NULL));
    int pass[10];
    int count=0;

    for(int i=0 ; i<100 ; i++){

        int randNumber = rand()%90;

        if(randNumber>=64 && randNumber<=90){
            count++;
            pass[count] = randNumber;
            printf("random number %c\n",randNumber);
            if(count==10){
                break;
            }
        }

    }

    printf("Our Generated Password:");
    for (int i = 0; i <=10 ; i++) {
        printf("%c",pass[i]);
    }

    return 0;
}


