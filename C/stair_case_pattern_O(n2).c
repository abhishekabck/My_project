# include <stdio.h>

int main(){
	int n = 4, i, j;
	char s[4] = {'%',' ','c'};
	for (i = n;i>0; i--){
		s[1] = (char)(i+48);
		printf(s,'*');
		for (j = 1;j<=(n-i);j++){
			printf("%c",'*');
		}
		printf("\n");
	}
	
	return 0;
}