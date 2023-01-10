//
// Created by National Cyber City on 1/10/2023.
// pre 1 struct

#include "stdio.h"
#define SIZE 3
struct Worker{

    int age;
    char name[30];
    char email[50];
    char password[50];

};

struct Worker info[SIZE];

void printingAllData();
void login();
int charCounting(char toCount[50]);
void myStrCmp(char userInputChar[50]);

int eFound = -1;

int main(){

    for(int i=0; i< SIZE ; i++){

        printf("Enter age:");
        scanf("%d",&info[i].age);

        printf("Enter name:");
        scanf(" %[^\n]",&info[i].name);

        printf("Enter email:");
        scanf(" %[^\n]",&info[i].email);


        printf("Enter password:");
        scanf(" %[^\n]",&info[i].password);

    }

    printingAllData();
    login();

    return 0;
}

void printingAllData(){

    for(int gcc=0; gcc< SIZE ; gcc++ ){

        printf("name:%s - age:%d - email:%s - password:%s\n",info[gcc].name , info[gcc].age , info[gcc].email , info[gcc].password);

    }
}

void login(){
    char lEmail[50];
    int found  = -1;
    printf("This is login form:\n");

    printf("Enter your email to login:");
    scanf(" %[^\n]",&lEmail);

    eFound = -1;
    myStrCmp(lEmail);

    if(eFound != -1){

        printf("Welcome Sir: %s\n",info[eFound].name);

    } else{
        printf("Invalid email:\n");
        login();
    }

}

void myStrCmp(char userInputChar[50]){

    int sameCount=0;
    int sec = charCounting(userInputChar);

    for(int i=0; i<SIZE ; i++){
        int first = charCounting(info[i].email);

        if( first == sec){

                for(int gcc=0; gcc<first ; gcc++){

                    if( info[i].email[gcc] != userInputChar[gcc]){

                        break;
                    } else{
                        sameCount++;

                    }

                }

        }
        if( sec == sameCount){
            eFound = i;
            break;
        }

    }

}

int charCounting(char toCount[50]){ // toCount[50] = {'w','i','n','@'gmail.com,'\0' , '\0'}
    int charCount = 0;
    for(int gcc=0; gcc<50 ; gcc++){

        if( toCount[gcc] == '\0'){
            break;
        } else{
            charCount++;
        }
    }
    return charCount;
}

// gmail validation
// winhtut@gmail.com
// winhtut@gmil.com