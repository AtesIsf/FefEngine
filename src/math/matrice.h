#ifndef MATRI_H
#define MATRIX_H

typedef struct {
    int row;
    int column;
    float data[10][10];
} Matrix;

void display_matrix(Matrix A);
Matrix addition(Matrix A, Matrix B);
Matrix soustraction(Matrix A, Matrix B);
Matrix produit(Matrix A, Matrix B);
Matrix division(Matrix A, Matrix B);

#endif
