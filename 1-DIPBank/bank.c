//
// Created by National Cyber City on 2/6/2023.
//




#include "stdio.h"
struct trans{
    char note[200];
};

struct data{
    unsigned int id;
    char name[30];
    char nrc[50];
    char email[50];
    char password[50];
    char pOrb[1]; // personal or business
    char loan_s[1]; // loan status
    unsigned int monthly_income;
    unsigned int loan_amount; // ဘယ်လောက်ချေးထားသလဲ
    unsigned int loan_rate;
    char acc_s[1]; //account status
    int acc_level;
    unsigned int phNumber;
    unsigned int cur_amount; //current amount
    char address[100];
    int transAmoLimitPerDay; // transAmountLimitPerDay minimize for our project 5min
    struct trans trc[100]


};

struct data db[1000];




void welcome();
int main(){

    welcome();

    return 0;
}

void welcome(){

    int option=0;
    printf("Welcome to our Bank!\n");
    printf("Press 1 to Login!\nPress 2 to Register!\nPress 3 to Exit!:::");
    scanf("%d",&option);

    if(option == 1){
        // login

    } else if(option == 2){
        //register

    } else if( option == 3){

        //exit
    } else {
        welcome();
    }

}

void userProfile(){



}
