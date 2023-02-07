//
// Created by National Cyber City on 1/10/2023.
// pre 1 struct

#include "stdio.h"
#include "stdlib.h"
#define SIZE 10000
struct Worker{
    int id;
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
void passChecking(char pass[50] , int userIndex);
void recordingAllDataToFile();
void userActionSector();
void loadingAllDataFromFile();
void registration();
void lobby();
void myGmailValidation(char toValidate[50]);
void copyToArray(char transmit[50]);
void myStrongPassword(char pass[50]);
void myStringCopy(char first[50] , char second[50] );

int eFound = -1;
int pFound=-1;
int gValid=-1;

int globalIndex=0;
int strongPass = -1;

int main(){


    loadingAllDataFromFile();
    printingAllData();
    lobby();


    return 0;
}
void lobby(){
    int lob=0;
    printf("This is Lobby Sector!\n");
    printf("Press 1 to Register:\n");
    printf("Press 2 to Login:\n");
    printf("Press 3 to Exit:");

    scanf(" %d",&lob);

    if(lob == 1){
        registration();

    } else if(lob == 2){

        login();
    } else if(lob == 3){
        recordingAllDataToFile();
        exit(1);
    } else{
        printf("Invalid Option!\n");
        lobby();
    }


}

void printingAllData(){

    for(int gcc=0; gcc< globalIndex ; gcc++ ){

        printf("id: %d-name:%s - age:%d - email:%s - password:%s\n",info[gcc].id,info[gcc].name , info[gcc].age , info[gcc].email , info[gcc].password);

    }
}

void login(){
    char lEmail[50];
    char passWord[50];
    int found  = -1;
    printf("This is login form:\n");

    printf("Enter your email to login:");
    scanf(" %[^\n]",&lEmail);

    eFound = -1;
    myStrCmp(lEmail);

    printf("Enter your password :");
    scanf(" %[^\n]",&passWord);

    pFound = -1;
    passChecking(passWord , eFound);


    if(eFound != -1 && pFound == 1){
        userActionSector();


    } else{
        printf("Invalid email: or Password \n");
        login();
    }

}

void myStrCmp(char userInputChar[50]){

    int sameCount=0;
    int sec = charCounting(userInputChar);

    for(int i=0; i<globalIndex ; i++){
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

void passChecking(char pass[50] , int userIndex){

    int passCount = charCounting(pass);
    int infoPassCount = charCounting(info[userIndex].password);

    int sameCount=0;

    if(passCount == infoPassCount) {

        for (int ncc = 0; ncc < passCount; ncc++) {

            if (pass[ncc] == info[userIndex].password[ncc]) {

                sameCount++;

            } else{
                break;
            }


        }

        if( sameCount == passCount){
            pFound = 1;
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

void recordingAllDataToFile(){

    FILE *fptr = fopen("db.txt","w");

    if(fptr == NULL){
        printf("Error at recordingAllDataToFile fun():\n");
    } else{

        for(int gcc=0; gcc<globalIndex; gcc++){


            fprintf(fptr , "%d %d %s %s %s\n",info[gcc].id , info[gcc].age , info[gcc].name , info[gcc].email  , info[gcc].password);


        }
        printf("Recording all data to dipDB.txt is complete!\n");
    }

    fclose(fptr);

}

void userActionSector(){

    int userAction=0;

    printf("Welcome Sir: %s\n",info[eFound].name);
    printf("Press 1 to User Action Sector:\n");
    printf("Press 2 to Home:\n");
    printf("Press 3 to Exit:");
    scanf(" %d",&userAction);

    if(userAction == 1){
        printf("this is user action sector:\n");
    } else if( userAction == 2){
        login();
    } else if(userAction == 3){
        recordingAllDataToFile();
    } else{
        printf("Invalid Option!\n");
        userActionSector();
    }
}

void loadingAllDataFromFile(){

    FILE *fptr = fopen("db.txt","r");

    if(fptr == NULL){
        printf("Error at loading!\n");
    } else{

        for(int gcc=0; gcc<SIZE ; gcc++){

            fscanf(fptr ,"%d%d%s%s%s",&info[gcc].id , &info[gcc].age, &info[gcc].name,&info[gcc].email,&info[gcc].password);

            if(info[gcc].name[0] == '\0'){
                break;
            }
            globalIndex++;

        }

    }


}

void registration(){
    char rePassword[50];
    char reEmail[50];
    printf("This is registration!\n");
    printf("Enter your email:");
    scanf(" %[^\n]",&reEmail[0]);
    gValid = -1;
    myGmailValidation(reEmail);

    if( gValid != -1){

        eFound=-1;
        myStrCmp(reEmail);

        if(eFound == -1){
            //globalIndex++;
            copyToArray(reEmail);
            info[globalIndex].id = globalIndex+1;
            printf("U can register enter your name pls:");
            scanf(" %[^\n]",&info[globalIndex].name);

            printf("U can register enter your age pls:");
            scanf("%d",&info[globalIndex].age);
            int a=0;
            while (a==0){
                printf("Enter Your password:");
                scanf(" %[^\n]",&rePassword);
                strongPass=-1;
                myStrongPassword(rePassword);
                if( strongPass != -1){
                    myStringCopy(info[globalIndex].password , rePassword);
                    a = 1;

                } else{
                    printf("Weak Password Try Again!\n");
                }
            }
            globalIndex++;
            printingAllData();
            login();

        } else{

            printf(" Your email was already exist!\n");
            registration();
        }


    } else{
        printf("Your gmail not valid format:\n");
        registration();
    }
}

void myGmailValidation(char toValidate[50]){

    // winhtut@gmail.com
    int toEndPoint = charCounting(toValidate);
    char form[10]={'@','g','m','a','i','l','.','c','o','m'};
    int count=0;

    for(int i=0; i<toEndPoint; i++){

        if(toValidate[i] == '@' || toValidate[i] ==' '){
            break;
        }else{
            count++;
        }

    }
    int tocheck=0;
    for( int i=0 ; i< toEndPoint ; i++){

        if( toValidate[count] != form[i]){
            break;
        } else{
            count++;
            tocheck++;
        }
    }

    if( tocheck == 10){
        gValid=1;
    }


}

void copyToArray(char transmit[50]){

    int toEnd = charCounting(transmit);

    for(int i=0; i<toEnd ; i++){

        info[globalIndex].email[i]= transmit[i];

    }

}

void myStringCopy(char first[50] , char second[50] ){

    int secondCount =charCounting(second);
    for( int i=0; i<50; i++){
        first[i]='\0';
    }

    for(int a=0; a<secondCount ; a++){

        first[a] = second[a];

    }

}

void myStrongPassword(char pass[50]){

    int i=0;
    int special=0;
    int numberChar=0;
    int capChar=0;
    int smallChar=0;
    while (strongPass == -1){
        if( pass[i] >= 33 && pass[i] <= 42){

            special++;
        } else  if( pass[i] >= 48 && pass[i] <= 57){

            numberChar++;

        } else if( pass[i] >= 65 && pass[i] <= 90){

            capChar++;
        } else if( pass[i] >= 97 && pass[i] <= 122)

            smallChar++;
        i++;
    }

    if( special > 0 && numberChar >0 && capChar > 0 && smallChar >0){
        strongPass = 1;
    } else{
        printf("Weak password:\nTryAgain\n");
            }


}

// gmail validation
// winhtut@gmail.com
// winhtut@gmil.com