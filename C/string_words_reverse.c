# include <stdio.h>
# include <string.h>

void reverse(char* s, int start, int end){
    int i = start, j = end;
    while (i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int rectify(char* s, int n){
    int i = 0, k = 0;
    while (s[i] == ' ') i++;
    int count_space = 0;
    while (i < n){
        if (s[i] == ' ') count_space += 1;
        else count_space = 0;
        if (count_space <= 1) {
            s[k++] = s[i];
        }
        i++;
    }

    s[k] = '\0';
    return k;
}

char* reverseWords(char* s) {
    int n = strlen(s);
    n = rectify(s, n);
    reverse(s, 0, n - 1);

    // reversing words
    int start = 0;
    for (int i = 0; i <= n; i++){
        if (s[i] == ' ' || s[i] == '\0'){
            reverse(s, start, i-1);
            start = i+1;
        }
    }
    return s;
}

int main(){
    char s[] = "hello world";
    printf("%d\n", strlen(s));
    char* y = reverseWords(s);
    int size = rectify(s, strlen(s));
    printf("%d\n", size);
    printf("%s\n", y);
    return 0;
}