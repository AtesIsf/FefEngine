#include <stdio.h>
#include "matrice.h" 

void display_matrix(Matrix A) {
    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < A.column; j++) {
            printf("%.2f ", A.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix addition(Matrix A, Matrix B) {
    Matrix C;
    C.row = A.row;
    C.column = A.column;
    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < A.column; j++) {
            C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
    return C;
}

Matrix soustraction(Matrix A, Matrix B) {
    Matrix C;
    C.row = A.row;
    C.column = A.column;
    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < A.column; j++) {
            C.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }
    return C;
}

Matrix produit(Matrix A, Matrix B) {
    Matrix C;
    C.row = A.row;
    C.column = B.column;
    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < B.column; j++) {
            C.data[i][j] = 0;
            for (int k = 0; k < A.column; k++) {
                C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return C;
}

int IsInvertible(Matrix B) {
// Determine if matrix B is invertible    
    return 1;  
}

Matrix inverse(Matrix B) {
    Matrix C;
    C.row = B.row;
    C.column = B.column;
   
    return C;  
}

Matrix division(Matrix A, Matrix B) {
    Matrix C;
    C.row = A.row;
    C.column = A.column;
    if (A.row != A.column && IsInvertible(B)) {
        printf("matrix  B is not  invertible");
    } else {
        return produit(A, inverse(B));
    }
}
    