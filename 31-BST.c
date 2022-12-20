//
// Created by National Cyber City on 12/20/2022.
//

#include "stdio.h"
#include "stdlib.h"

struct Node{

    int data;

    struct Node* left;
    struct Node* right;


};

struct Node* creatNode(int key){

    struct Node* newNode =(struct Node*)malloc(sizeof (struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root , int key){

    if(root == NULL){
        return creatNode(key);
    }

    if(key < root->data){

        root->left = insertNode(root->left , key); //recursive function

    } else{

        root->right = insertNode(root->right ,key);
    }

    return root;

}

void inorderTraversal(struct Node* node){

    if(node !=NULL){

        inorderTraversal(node->left);
        printf("data: %d\n",node->data);

        inorderTraversal(node->right);
    }


}

void finder(struct Node* node , int toFindKey){

    if(node !=NULL){
        if(node->data == toFindKey){

            printf("We Found\n");
        }
        inorderTraversal(node->left);


        inorderTraversal(node->right);
    }


}



int main(){

    struct Node* root = NULL;

    root = insertNode(root , 10);
    root = insertNode(root , 8);
    root = insertNode(root , 12);
    root = insertNode(root , 5);
    root = insertNode(root , 15);
    root = insertNode(root , 3);
    root = insertNode(root , 4);
    root = insertNode(root , 13);
    root = insertNode(root , 1);
    root = insertNode(root , 20);
    inorderTraversal(root);
    finder(root, 13);







    return 0;
}