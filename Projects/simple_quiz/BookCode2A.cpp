# include <bits/stdc++.h>

using namespace std;

string playerName;
int UserAns;
int totalScore;

class Question{
    private:
        string Question_text;
        string Answer_1;
        string Answer_2;
        string Answer_3;
        string Answer_4;
        int CorrectAns;
        int QuestionWeightage;
    
    public:
        void setValues(string, string, string, string, string, int, int);
        void askQuestion();
};


// start of main
int main() {
    cout<<"Enter Your Name: ";
    getline(cin, playerName);

    cout << "Hello "<<playerName;
    cout << "\n--------------------------------------\n";
    cout << "Let us play quiz, which asks Multiple Choice Questions type."<<endl;
    cout << endl;

    totalScore = 0;

    Question q1;
    Question q2;
    Question q3;
    
    q1.setValues("What is red?","color","Object", "Vehicle", "plant", 1, 10);
    q1.setValues("What is Milky-way?","star", "galaxy", "android", "planet", 2, 5);
    q3.setValues("What is result of 3+7", "six", "eight", "seven", "ten", 2, 5);

    q1.askQuestion();
    q2.askQuestion()
    q3.askQuestion();

    cout << endl<< playerName<<": Your total score is"<< totalScore;
}

void Question::setValues(string q, string a1, string a2, string a3, string a4, int ca, int qw){
    Question_text = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    CorrectAns = ca;
    QuestionWeightage = qw;
}

void Question::askQuestion(){
    cout <<"\n The question on defintion is: \n";
    cout << Question_text << endl;
    cout << 1. <<"Answer_1<< "\n";
}