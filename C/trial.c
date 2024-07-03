# include <stdio.h>

void main(){
    char s[] = "4356";
    char temp = s[2];
    s[2] = s[3];
    s[3] = temp;
    printf("%s",s);
}
