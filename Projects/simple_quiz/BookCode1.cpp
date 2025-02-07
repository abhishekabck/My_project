# include <bits/stdc++.h>

using namespace std;

string playerName;
char playerChoice;
int totalScore;

// start of main
int main() {
    cout<< "Enter Your Name: ";
    getline(cin, playerName);
    cout<<"Hello "<<playerName;
    cout<<"\n-----------------------------------------\n";
    cout<<"Let us play quiz, which asks only true of false."<<endl;
    cout<<"Answer the question by pressing either 't' or 'f"<<endl;
    cout<<endl;     // new line is inserted
    
    totalScore = 0;
    cout<< "Red is three letter word? [t]rue or [f]alse->:";
    cin>>playerChoice;

    if (playerChoice == 't') totalScore += 1;
    cout<<endl;

    cout<<"Result of maths operation 5+3=7?[t]rue or [f]alse";
    cin>> playerChoice;
    
    if (playerChoice == 'f') totalScore += 1;
    cout<<endl;

    cout<<"Milky is the name of galaxy? [t]rue or [f]alse:";
    cin>> playerChoice;

    
    if (playerChoice == 't') totalScore += 1;
    cout<<endl;

    cout<< endl<<playerName <<": your total score is "<<totalScore;
}
//end of main program