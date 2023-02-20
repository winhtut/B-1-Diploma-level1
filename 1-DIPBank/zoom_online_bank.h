//
// Created by National Cyber City on 2/20/2023.
//

#ifndef DIPLEVEL1_ZOOM_ONLINE_BANK_H
#define DIPLEVEL1_ZOOM_ONLINE_BANK_H

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
int two_charArray=-1;
int nrc_valid = -1;
int strongPass=-1;


// For Function Declaration
void welcome();
void userSector();
void loadingAllDataFromFile();
void printingAllData();
void registration();
int charCounting(char toCount[50]);
void myGmailValidation(char toValidate[50]);
void emailExistChecking(char toCheck[50]);
void compare_two_charArray(char first[50] , char second[50]);
void nrc_validation(char nrc_toCheck[50]);
void myStrongPassword(char pass[50]);


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
    char re_name[50];
    char re_nrc[50];
    char re_pass[50];
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
            scanf(" %[^\n]",&re_name);
            nrc_valid=-1;
            while (nrc_valid==-1){
                printf("Enter your NRC:");
                scanf(" %[^\n]",&re_nrc);

                nrc_validation(re_nrc);
                if(nrc_valid == -1){
                    printf("Your NRC Format was Not Valid!\n");
                }

            }
            printf("Your NRC Format was Valid!\n");
            strongPass=-1;
            while (strongPass == -1){
                printf("Enter your password!:");
                scanf(" %[^\n]",&re_pass);
                myStrongPassword(re_pass);
                if(strongPass == -1){
                    printf("Your Password Format too weak and Try Again!\n");
                }
            }
            printf("Your password format was valid and saved!\n");



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

void nrc_validation(char nrc_toCheck[50]){

    int nrc_counter =charCounting(nrc_toCheck);
    int nrc_char=0;

    for(register int i=0; i< nrc_counter ; i++){

        if( nrc_toCheck[i] == ')'){
            break;
        }
        nrc_char++;
    }

    for(int i=0; i<3; i++){

        two_charArray=-1;
        compare_two_charArray(nrc_toCheck,db[i].nrc);
        if(two_charArray == 1){
            nrc_valid=1;
            break;
        }

    }


}

void compare_two_charArray(char first[50] , char second[50]){

   int first_counter =  charCounting(first);
    int second_counter = charCounting(second);
    int same_counter = 0;

    if( first_counter == second_counter) {
        for (register int i = 0; i < first_counter; i++) {
                if(first[i] != second[i]){
                    break;
                }
                same_counter++;
        }

        if( first_counter == same_counter){
            two_charArray = 1;
        }
    }

}

void myStrongPassword(char pass[50]){

    int i=0;
    int special=0;
    int numberChar=0;
    int capChar=0;
    int smallChar=0;
    int pass_counter = charCounting(pass);
    while (strongPass == -1){
        if( i == pass_counter){
            strongPass=-1;
            break;
        }
        if( pass[i] >= 33 && pass[i] <= 42){

            special++;
        } else  if( pass[i] >= 48 && pass[i] <= 57){

            numberChar++;

        } else if( pass[i] >= 65 && pass[i] <= 90){

            capChar++;
        } else if( pass[i] >= 97 && pass[i] <= 122) {

            smallChar++;
        }
        i++;
        if( special > 0 && numberChar >0 && capChar > 0 && smallChar >0){
            strongPass = 1;
        }
    }


}


#endif //DIPLEVEL1_ZOOM_ONLINE_BANK_H
