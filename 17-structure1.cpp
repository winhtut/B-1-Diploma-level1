#include "iostream"
using namespace std;





class MyClass {       // The class
public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;// Attribute (string variable)

    void myFun(){ // method
        printf("Hello MyFun");
    }
};


void myFun2(){

    printf("This is myFun");
}

int main() {
    MyClass myObj;  // Create an object of MyClass
    MyClass myObj2;  // Create an object of MyClass


    // Access attributes and set values
    myObj.myNum = 15;

    myObj.myString = "Some text";


    myObj2.myNum = 25;
    myObj2.myString = "Swordst";
    myObj2.myFun();

    // Print attribute values
    cout << myObj.myNum << "\n";
    cout << myObj2.myNum << "\n";
    cout << myObj.myString;
    return 0;
}