//
// Created by National Cyber City on 12/5/2022.
//

#include "stdio.h"
#include "stdlib.h"
struct node{

    int data;
    struct node *next;


};

struct node* atBeginning(struct node *myNode , int newData){

    struct node *beginNode =(struct node*)malloc(sizeof (struct node));

    beginNode->data = newData;

    beginNode->next = myNode;

    myNode = beginNode;
    return myNode;
}


void atBeginningREF(struct node **myNode , int newData){

    struct node *beginNode =(struct node*)malloc(sizeof (struct node));

    beginNode->data = newData;

    beginNode->next = (*myNode);

    (*myNode) = beginNode;

}



int searchingData(struct node *myNode , int data){

    if(myNode == NULL){

        printf("Node is NULL:\n");
        return -1;
    }

    while (myNode != NULL){

        if(myNode->data == data){
            return 1;
        } else{
            myNode = myNode->next;
        }

    }

    return -1;
}

void insertAfter(struct node* prev_node , int data_forNewNode){


    if(prev_node == NULL){
        printf("Previous node is NULL!");
        return;
    }

   struct node *new_node = static_cast<node *>(malloc(sizeof(struct node)));
    new_node->data = data_forNewNode;
    new_node->next =prev_node->next;
    prev_node->next  = new_node;


}

void printData(struct node* myNode){

    while (myNode != NULL){
        printf("data: %d\n",myNode->data);
        myNode = myNode->next;

    }

}
int main(){

    struct node *head=NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = static_cast<node *>(malloc(sizeof(struct node)));
    two = static_cast<node *>(malloc(sizeof(struct node)));
    three = static_cast<node *>(malloc(sizeof(struct node)));

    one->data = 10;
    two->data = 20;
    three->data =30 ;

    one->next = two;
    two->next = three;
    three->next = NULL;
    printf("\n");

    printData(one);
    insertAfter(one , 15);
    printf("After inserted new node:\n");
    printData(one);

    int result = searchingData(one , 35);
    if(result==1){
        printf("We found:\n");
    } else{
        printf("Not found!\n");
    }

    //struct node *newLL = atBeginning(one , 5);
    atBeginningREF(&one , 5);
    printData(one);

    return 0;
}
