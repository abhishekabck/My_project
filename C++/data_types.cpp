#include <iostream>
#include <string>

using namespace std;

// C++ DataTypes :- 

int main() {
    int num1,num2,num3; // int datatype consist of 2 or 4 bytes 
    num1 = 3,num2 = 5, num3 =6;

    char c,c2; // char datatypes include only 1 charater of size of 1 byte
    c = '!',c2 = 65; /* can also be given ascii value of that charater
                        char can be used to calculation with integer with respect ascii of char value's */

    string name="Abhishek Chaurasiya",subject = "Engineering Physics" ; // string datatype is required to be called #include <string>

    double val = 0.789,va ;
    float val1 = 7.779 ; //e/E means in power of 10. like 2e-2 = 0.02
    /* double and float both used to record decimal and integer values but double can store double values than float 
    where float has 7 digits but double can record upto 15 digits..*/

    bool ch = false; // bool data type which is store values either in  true and false means 1 and 0 repectivally..

    cout<<"Thank you!";

    return 0;
}