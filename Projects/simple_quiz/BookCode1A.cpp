#include <bits/stdc++.h>

using namespace std;

string playerName;
char playerChoice;
int totalScore;
const int totalQs = 6;
string Questions[totalQs] =
{
    "Red is three Letter word? [t]rue or [f]alse->:",
    "Result of maths operation 5+3 is 7?[t]rue or [f]alse->:",
    "Milky is the name of galaxy? [t]rue or [f]alse->:",
    "Blue color is the sky? [t]rue or [f]alse->:",
    "Seven sides does a cube have?[t]rue or [f]alse->:",
    "Green color is grass?[t]rue or [f]alse->:"
};

char Answers[totalQs] = {'t', 'f', 't', 't', 'f', 't'};

// start of main
int main(){
    cout<< "Enter Your Name: ";
    getline(cin, playerName);
    cout<<"Hello "<<playerName;
    cout<<"\n-----------------------------------------\n";
    cout<<"Let us play quiz, which asks only true of false."<<endl;
    cout<<"Answer the question by pressing either 't' or 'f"<<endl;
    cout<<endl;     // new line is inserted

    totalScore = 0;

    for(int i = 0; i < totalQs; i++){
        cout<<Questions[i] << '\n';
        cin>>playerChoice;

        if (playerChoice == Answers[i]){
            cout<<"Correct answer!\n";
            totalScore += 1;
        }

        else {
            cout<<"Incorrect answer!\n";
        }
    }

    cout<< endl<<playerName<<": your total score is "<<totalScore \
    <<" out of total questions "<< totalQs<<endl;
}// end of main
// end of program