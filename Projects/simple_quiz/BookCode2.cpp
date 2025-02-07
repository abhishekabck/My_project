# include <bits/stdc++.h>

using namespace std;

string playerName;
int playerChoice;
int totalScore;

// start of the main
int main(){
    cout<<"Enter Your Name: ";
    getline(cin, playerName);

    cout << "Hello "<<playerName;
    cout << "\n--------------------------------------\n";
    cout << "Let us play quiz, which asks Multiple Choice Questions type."<<endl;
    cout << endl;

    totalScore = 0;

    cout << "Red is how many letter word? "<< endl;
    cout << "1> Two"<< endl;
    cout << "2> Three"<< endl;
    cout << "3> Four"<< endl;
    cout << "4> one"<< endl;
    cin >> playerChoice;
    if (playerChoice == 2)
        totalScore += 1;
    cout << endl;

    cout << "Result of maths operation 5+3 is "<< endl;
    cout << "1> Six"<< endl;
    cout << "2> Seven"<< endl;
    cout << "3> Eight"<< endl;
    cout << "4> Nine"<< endl;
    cin >> playerChoice;
    if (playerChoice == 3)
        totalScore += 1;
    cout << endl;

    cout << "Milky is the name of "<< endl;
    cout << "1> Galaxy"<< endl;
    cout << "2> Android"<< endl;
    cout << "3> Star"<< endl;
    cout << "4> Planet"<< endl;
    cin >> playerChoice;
    if (playerChoice == 1)
        totalScore += 1;
    cout << endl;

    cout << endl<< playerName << ": your total score is "<< totalScore;
}// End of main