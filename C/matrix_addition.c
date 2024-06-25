# include <stdio.h>
# include <C:\Users\Public\Documents\Projects\C\matrix.c>

int main(){
    int rows = 4, cols = 4;
    int matrix1[rows][cols], matrix2[rows][cols], matrix3[rows][cols];
    
    printf("Input the values of First matrix:\n");
    change(rows,cols);
    input_matrix(matrix1[rows][cols], rows, cols);
    
    printf("\nInput the values of Second matrix:\n");
    input_matrix(matrix2[rows][cols], rows, cols);

    // Matrix Addition
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nResultant Matrix (Sum of matrices):\n");
    Print_matrix(matrix3[rows][cols], rows, cols);
    
    return 0;
}
