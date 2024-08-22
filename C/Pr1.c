# include <stdio.h>
# include <limits.h>
# include "sysfile.c"
// variables and input and output

// // Matrix addition
// int main(){
//     int rows = 3, cols = 3;
//     int** arr1 = allocateArray(rows, cols);
//     int** arr2 = allocateArray(rows, cols);
//     int result[rows][cols];
//     // Matrix Input;
//     readArr(arr1,rows, cols);
//     readArr(arr2, rows, cols);

//     // Matrix Addition
//     for (int i = 0; i<rows; i++){
//         for (int j = 0; j< cols; j++){
//             result[i][j] = arr1[i][j] + arr2[i][j];
//         }
//     }
//     // Printing result
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             writeint(result[i][j]);
//         }
//         nl();
//     }

// }


// Matrix Multiplication

// int main() {
//     int r1 = 2, c1 = 3;
//     int r2 = 3, c2 = 2;

//     int arr1[r1][c1] = {
//         {2, 4, 5},
//         {3, 5, 7}
//     };

//     int arr2[r2][c2] = {
//         {2, 4},
//         {3, 5},
//         {2, 5}
//     };

//     int result[r1][c2] = {0};  // Initialize result array with 0

//     // Matrix multiplication
//     for (int i = 0; i < r1; i++) {
//         for (int j = 0; j < c2; j++) {  // Corrected loop condition
//             for (int k = 0; k < r2; k++) {
//                 result[i][j] += arr1[i][k] * arr2[k][j];  // Accumulate product
//             }
//         }
//     }

//     // Printing result
//     for (int i = 0; i < r1; i++) {
//         for (int j = 0; j < c2; j++) {
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

int main(){
    int arr[] = {2,6,3,5,3,6,4,5,3};
    int size =sizeof(arr)/sizeof(arr[0]);
    int num = 5;
    for (int i = 1; i < num; i++) {
        for (int j = 0; j< num - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i ; j++) {
            printf("* ");
        }
        printf("\n");
    }

    for (int i = num ; i > 0; i--) {
        for (int j = 0; j< num - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i ; j++) {
            printf("* ");
        }
        printf("\n");
    }
}