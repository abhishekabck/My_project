# include <stdio.h>
# include <stdlib.h>


int platform(int n, int m){
    int i,j,ch, display[3][3] = {
        {m,n,m},
        {n,1,n},
        {m,n,m}
    };
    for (i = 0; i<3; i++){
        for (j =0; j<3; j++){
            ch = display[j][i];
            switch (ch){
                case 1:
                    printf("%c ",'*');
                    break;
                case 0:
                    printf("%c ",' '); 
                    break;
            }
            
        }
        printf("\n");
    }
    return 1;
}

int main(){
    int n = 1, m = 0;
    while (1){
        platform(n,m);
        printf("\e[1;1H\e[2J");
        n=!n;m=!m;
    }
    return 0;
}