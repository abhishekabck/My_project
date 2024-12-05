# include <bits/stdc++.h>
using namespace std;
int total_buttons_pressed(int number_of_buttons){
    if (number_of_buttons == 1){
        return 1;
    }
    int cf = 0; // used to store Total Number of the correct buttons found
    int total_pressed = 0;
    for (int i = number_of_buttons; i > 0; i--){
        total_pressed += 1; // for correct found
        cf++; // incrementing the cf by 1 as cf number of times an key as to be pressed to reach that current state
        total_pressed += (i-1)*cf;
    }
    return total_pressed;
}

int main(){
    int buttons;
    cin>>buttons;
    cout<<total_buttons_pressed(buttons)<<endl;
    return 0;
}