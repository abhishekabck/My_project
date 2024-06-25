/*
# include <stdio.h>

int is_digit(char chr){
    if (chr>=0 && chr<=9) return 1;
    return 0;
}

int is_alpha(char chr){
    if (chr>=)
}
void main(){
    char chr;
    printf("Enter the Charater you wish to characterized");
    scanf("%c",&chr);
    if (chr>=97 && chr<=122) printf("Entered Character is Lower case Alphabet");
}

*/
#include <stdio.h>

void checkCharacterType(char ch) {
    if ((ch>=65 && ch <=90 ) || (ch>=97 && ch<=122)) {
        if ((ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) || (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )) {
            printf("VOWEL");
        }
        else printf("CONSONANT");
    }
    else if (ch>='0' && ch<='9') printf("DIGIT");
    else printf("SPECIAL SYMBOL");
    
}

int main() {
    char ch;
    while (1){
        scanf(" %c", &ch);
        checkCharacterType(ch);
    }
    return 0;
}


