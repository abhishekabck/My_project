// Transpose of matrix
#include <stdio.h>

int main(){
	int r=3,c=2;
	int matrix[3][2] = {{2, 4}, {5, 7}, {3, 7}};
	int trans[2][3],i,j;
	
	// Transpose of matrix
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++){
			trans[j][i] = matrix[i][j];
		}
	}
	
	// Print the transported matrix
	for (i = 0; i < c; i++){
		for (j = 0; j < r; j++){
			printf("%d ", trans[i][j]);
		}
		printf("\n");	
	}
	
	
	return 0 ;
}