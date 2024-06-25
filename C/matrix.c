# include <stdio.h>
int rows = 1, cols = 1;
void change(int r1, int c1){
    extern rows;
    extern cols;
    rows = r1;
    cols = c1;
}
void input_matrix(int matrix[rows][cols], int row, int column){
    /*
    Input Matrix Utilizes Pointer to access the addresss of Matrix.
    TO Input the matrix we run loop for i<rows and j>columns.
    After excution of this function the you can access matrix from given addres variable.
    This Function does not return any value..
    */
    for (int i = 0; i < rows; i++){
        printf("Enter the values of row no:- %d\n", i + 1);
        for (int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void Print_matrix(int matrix[rows][cols], int row, int col){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

