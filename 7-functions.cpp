//
// Created by National Cyber City on 11/8/2022.
//

/*Functions
 * standard library functions , programmer defined functions
 * // declaration , type , parameters , return value ;
 * // return ပြန်တဲ့ function , return မပြန်တဲ့ function
 * // non-parametrized fucntion  , parametrized function
 * */
#include "stdio.h"

int hello(int firstNumber , int SecNumber);
int main(){
    int myNumber;
    int a = 10;
    int b=10;
    myNumber = hello(a,b);

    printf("%d",myNumber);
    return 0;
}

int hello(int firstNumber , int SecNumber){
    printf("Hello this is from hello function \n");
    int multiValue = firstNumber*SecNumber;
    return multiValue;
}