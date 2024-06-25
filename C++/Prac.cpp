# include <stdio.h>
# include <string.h>
# include <stdlib.h>


int main() {
    char *p = "aryan mishra";
    *p = 'p';
    fflush(stdin);
    printf("%s",p);
}