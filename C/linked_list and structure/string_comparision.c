# include <stdio.h>

int main(){
    char str[10] = "RRRRRR";
    int flag = 0;
    for (int i = 1; str[i]!= '\0'; i++){
        if (str[i] != str[0]){
            printf("\n%c != %c",str[i],str[0]);
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        printf("Equal");
    }
    else {
        printf("Not Equal");
    }
    return 0;
}