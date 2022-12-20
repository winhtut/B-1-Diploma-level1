//
// Created by National Cyber City on 12/19/2022.
//
#include "stdio.h"
#include "stdlib.h"

struct Node{

    int data;
    struct Node* left;
    struct Node* right;

};

struct Node* createNode(int key){

    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node) );

    newNode->data = key;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

void insertAtRight(struct Node* root , int key){

    root->right=createNode(key);

}

void insertAtLeft(struct Node* root, int key){


    root->left = createNode(key);

}

int main(){

    struct Node* root =createNode(10);

    insertAtRight(root , 20);
    insertAtLeft(root , 5);
    insertAtRight(root->right , 25);

    return 0;
}

