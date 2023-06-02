#include <stdio.h>
#include "matrice.h"

int main() {
    Matrix A, B, C;
    A.row = 3;
    A.column = 3;
    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < A.column; j++) {
            printf("A[%d][%d] ", i, j);
            scanf("%f", &A.data[i][j]);
        }
    }
    printf("A = \n");
    display_matrix(A);

    B.row = 3;
    B.column = 3;
    for (int i = 0; i < B.row; i++) {
        for (int j = 0; j < B.column; j++) {
            printf("B[%d][%d] ", i, j);
            scanf("%f", &B.data[i][j]);
        }
    }
    printf("B = \n");
    display_matrix(B); 

    printf("+++++ addition +++++        \n");
    C = addition(A, B);
    display_matrix(C);

    printf("+++++ soustraction +++++     \n");
    C = soustraction(A, B);
    display_matrix(C);

    printf("+++++ produit +++++          \n");
    C = produit(A, B);
    display_matrix(C);

    printf("+++++ division +++++        \n");
    C = division(B, A);
    display_matrix(C);

    return 0;
}