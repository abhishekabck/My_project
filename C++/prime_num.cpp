#include <iostream>
#include <string>
using namespace std;

int main() {
    int num,b;
    b = 0;
    cout<<"Enter Number to check whether number is Prime or not :-";
    cin>>num;
    for (int i = 2;i<num; i++ ) {
        if (num%i == 0) {
            b = 1;
            break;
        }
    }
    string c = (b==1)?"Not Prime":"Prime";
    cout<< c;
        
    return 0;
}