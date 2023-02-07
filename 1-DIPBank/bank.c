//
// Created by National Cyber City on 2/6/2023.
//


#include "stdio.h"
#define SIZE 1000 // symbolic constant
struct trans{
    char note[200];
};
//id name nrc email password pOrb loan_status monthly_income
// loan_amount loan_rate accountStatus account_Level phNumber current_amount address TransRC
struct data{
    unsigned int id;
    char name[30];
    char nrc[50];
    char email[50];
    char password[50];
    char pOrb[20]; // personal or business
    char loan_s[2]; // loan status
    unsigned int monthly_income;
    unsigned int loan_amount; // ဘယ်လောက်ချေးထားသလဲ
    float loan_rate;
    char acc_s[10]; //account status
    int acc_level;
    unsigned int phNumber;
    unsigned int cur_amount; //current amount
    char address[100];
    int transAmoLimitPerDay; // transAmountLimitPerDay minimize for our project 5min
    struct trans trc[100];

};

struct data db[SIZE];

// Global Variable Declaration

int users=0;
int gValid=-1;
int emailExist=-1;


// For Function Declaration
void welcome();
void userSector();
void loadingAllDataFromFile();
void printingAllData();
void registration();
int charCounting(char toCount[50]);
void myGmailValidation(char toValidate[50]);
void emailExistChecking(char toCheck[50]);


int main(){

    loadingAllDataFromFile();
    printingAllData();
    welcome();

    return 0;
}

void welcome(){

    int option=0;
    printf("Welcome to our Bank!\n");
    printf("Press 1 to Login!\nPress 2 to Register!\nPress 3 to Exit!:::");
    scanf("%d",&option);

    if(option == 1){
        printf("This is login!\n");

    } else if(option == 2){
        registration();

    } else if( option == 3){

        //exit
    } else {
        welcome();
    }

}

void userSector(){

    printf("This is user Sector\n");


}
//id name nrc email password pOrb loan_status monthly_income
// loan_amount loan_rate accountStatus account_Level phNumber current_amount address TransRC
void loadingAllDataFromFile(){

    FILE *fptr = fopen("ncc_db1.txt","r");

    if( fptr == NULL){
        printf("Error at loadingAllDataFromFile Function!\n");
    } else{
        for(int ncc=0; ncc<SIZE ; ncc++){

            fscanf(fptr ,"%u%s%s%s%s%s%s%u%u%f%s%d%u%u%s%s",&db[ncc].id,&db[ncc].name,&db[ncc].nrc,&db[ncc].email,&db[ncc].password,&db[ncc].pOrb,&db[ncc].loan_s,&db[ncc].monthly_income,&db[ncc].loan_amount ,&db[ncc].loan_rate , &db[ncc].acc_s ,&db[ncc].acc_level,&db[ncc].phNumber , &db[ncc].cur_amount,&db[ncc].address ,&db[ncc].trc[0].note );



            if(db[ncc].email[0] == '\0'){
                break;
            }

            users++;

        }

    }

    fclose(fptr);

}
void printingAllData(){

    for(int ncc=0; ncc<users ; ncc++){


        printf("%u-%s-%s-%s-%s-%s-%s-%u-%u-%f-%s-%d-%u-%u-%s-%s\n",db[ncc].id,db[ncc].name,db[ncc].nrc,db[ncc].email,db[ncc].password,
               db[ncc].pOrb, db[ncc].loan_s,db[ncc].monthly_income,db[ncc].loan_amount ,db[ncc].loan_rate , db[ncc].acc_s ,db[ncc].acc_level,
               db[ncc].phNumber , db[ncc].cur_amount,db[ncc].address ,db[ncc].trc[0].note);
    }

}

void registration(){

    char reEmail[50];
    printf("This is NCC Bank User Registration!\n");
    printf("Enter your email:");
    scanf(" %[^\n]",&reEmail);
    gValid=-1;
    myGmailValidation(reEmail);
    if( gValid != -1){

        emailExist=-1;
        emailExistChecking(reEmail);

        if( emailExist == -1 ){

            printf("Your email is valid!\n");
            printf("Enter your name:");
        } else{

            printf("Your gmail already taken!\n");
            registration();

        }



    } else{
        printf("Your gmail format not valid!\n");
        registration();
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

void emailExistChecking(char toCheck[50]){

    int toCheckCount = charCounting(toCheck);
    int sameCounting=0;

    for(int ncc=0; ncc<users ; ncc++){
        int dbEmailCount = charCounting(db[ncc].email);

        sameCounting=0;
        if( toCheckCount == dbEmailCount){

            for(int gcc=0; gcc<toCheckCount ; gcc++){

                if(toCheck[gcc] != db[ncc].email[gcc] ){
                    break;
                } else{
                    sameCounting++;
                }

            }


        }

        if(toCheckCount == sameCounting){

            emailExist = ncc;
        }

    }


}
