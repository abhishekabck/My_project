# include <stdio.h>
# include <C:\Users\Public\Documents\Projects\C\matrix.c>

int main(){
    int rows = 4;
    int matrix1[rows][4], matrix2[rows][4], matrix3[rows][4];
    
    printf("Input the values of First matrix:\n");
    input_matrix(matrix1, rows, 4);
    
    printf("\nInput the values of Second matrix:\n");
    input_matrix(matrix2, rows, 4);

    // Matrix Addition
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < 4; j++){
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nResultant Matrix (Sum of matrices):\n");
    Print_matrix(matrix3, rows, 4);
    
    return 0;
}
