# include <stdio.h>
# include <limits.h>
# include "sysfile.c"
// variables and input and output

int main(){
    int num = readint();
    writeint(num);
    return 0;
}