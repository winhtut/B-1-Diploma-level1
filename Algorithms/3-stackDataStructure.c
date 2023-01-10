//
// Created by National Cyber City on 12/27/2022.
//

// stack data structure

#include "stdio.h"
#include "stdlib.h"

#define MAXOFSTACK 10


struct stack{

    int data[MAXOFSTACK];

    int top;

};
typedef struct stack st;

int isStackIsFull(st *myStack){

    if(myStack->top == MAXOFSTACK-1){
        return 1;
    } else{
        return 0;
    }

}
int isStackIsEmpty(st *myStack){

    if(myStack->top == -1){

        return 1;
    } else{
        return 0;
    }

}

void creat_emptyStack(st *myStack){

    myStack->top = -1;
}

void pushToStack(st *myStack , int value){

    if(isStackIsFull(myStack)){
        printf("Stack is Full!");

    } else{

        myStack->top++;

        myStack->data[myStack->top] = value;

    }

}

void popFromStack(st *myStack){

    if(isStackIsEmpty(myStack)){
        printf("Stack is empty!");
    }else{

        printf("Pop from stack data is : %d\n",myStack->data[myStack->top]);

        myStack->top--;

    }

}

int main(){

    st *myStack =(st*)malloc(sizeof(st) );

    creat_emptyStack(myStack);


    pushToStack(myStack , 10);
    pushToStack(myStack , 11);
    pushToStack(myStack , 12);
    pushToStack(myStack , 13);
    pushToStack(myStack , 14);

    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);



    return 0;
}