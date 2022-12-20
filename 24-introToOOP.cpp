#include "iostream"
using namespace std;
class MyClass{

public:
    int age;
    string myName;

    MyClass(int id , string name){
        age= id;
        myName = name;

    }



    void myMethod(){
        cout<<"This is from myMethod"<<endl;
        cout<<age<<":"<<myName<<endl;
    }

    int bankIDGetter(){

        return bankID;
    }
    void bankInfoSetter(string uname, int id, string pass){

        username = uname ;
        bankID = id;
        bankPass = pass;

    }

private:
    string username;
    int bankID;
    string bankPass;

protected:
    string pro="This is protected";
};


//derived class
class Ncc:public MyClass{

public:
    string subject="Programming";

    Ncc(int id, string name) : MyClass(id, name) {

        cout<<pro<<endl;
    }



};


int main(){

    Ncc nccObj(0, std::string());


    return 0;
}