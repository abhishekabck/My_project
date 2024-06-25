# include <stdio.h>

/* Pattern
    *
    * *
    * * *
    * * * *
    * * * * *
    * * * * * *
int main(){
   int n = 5, i, j;
   for (i = 0; i<n; i++){
        for (j = 0; j<= i; j++) 
            printf("* ");
    printf("\n");
   }
}



Pattern
1 
1 2 
1 2 3 
1 2 3 4
1 2 3 4 5

int main(){
    int n = 5,i ,j;
    for (i = 1; i<=n; i++){
        for (j = 1; j <= i; j++){
            printf("%d ",j);
        }
        printf("\n");
    }
}

pattern
A
A B 
A B C 
A B C D
A B C D E


int main(){
    int n = 5,i ,j;
    for (i = 1; i<=n; i++){
        for (j = 1; j <= i; j++){
            printf("%c ",j+64);
        }
        printf("\n");
    }
}


pattern
        A
      A B 
    A B C 
  A B C D
A B C D E

int main(){
    int n = 5, i, j, k;
    for (i = 0; i<=n; i++){
        for (k = n-i; k>0; k--)
            printf("  ");
        for (j = 0; j<i; j++)
            printf("%c ",j+65);
        printf("\n");
    }
    return 0;
}


pattern
        1
      2 3
    3 4 5
  4 5 6 7
5 6 7 8 9

int main(){
    int n = 5, i, j, k;
    for (i = 1; i <= n; i++){
        for (k = n - i; k>0; k--){
            printf("  ");
        }
        for (j = 0; j<i; j++){
            printf("%d ", i+j);
        }
        printf("\n");
    }
    return 0;
}

Pattern :- Floyd's Triangle

        1
      2 3
    4 5 6
  7 8 9 10


int main(){
    int n = 4, i, j, k, c = 1;
    for (i = 1; i <= n; i++){
        for (k = n - i; k>0; k--){
            printf("  ");
        }
        for (j = 0; j<i; j++){
            printf("%d ", c++);
        }
        printf("\n");
    }
    return 0;
}
Pattern :- pyramid
                *
              * * *
            * * * * *
          * * * * * * *
        * * * * * * * * *

int main(){
    int n = 5, i, j, k;
    for (i = 1; i <= n; i++){
        for (k = n - i; k>0; k--){
            printf("  ");
        }
        for (j = 0; j<2*i-1 ; j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
Pattern :- Diamond
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
  * * * * * * *
    * * * * * 
      * * *
        *


int main(){
    int n = 5, i, j, k;
    for (i = 1; i <= n; i++){
        for (k = n - i; k>0; k--){
            printf("  ");
        }
        for (j = 0; j<2*i-1 ; j++){
            printf("* ");
        }
        printf("\n");
    }
    for (i = n-1; i > 0; i--){
        for (k = n-i; k>0; k--){
            printf("  ");
        }
        for (j = 2*i - 1; j>0 ; j--){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

*/
