#include "header_assign3.h"

int main(){

    int i,j,m,n;

    int count = 0;

    printf("\n\nHiya! This is a program to calculate the right inverse of a matrix, in case it exists. Here is how you can ensure it exists.\n\n 1) the number of columns should be greater or equal to that of rows.\n 2) the matrix must have full row rank.\n\nPlease enter the dimensions, number of rows followed by number of columns, of matrix you want to find the right inverse of.\n");

    do{

        printf("\nEnter the number of matrix rows:  ");
        scanf("%d", &m);

        printf("\nNow enter the number of matrix columns:  ");
        scanf("%d", &n);

        if (m <= 0 || n <= 0){
            printf("\nMatrix dimensions can't be negative or zero! Retry:");
            }
    }
    while(m <= 0 || n <= 0);
    
    //declaring matrix using pointer

    float*A[m];
    for(i=0;i<m;i++)
        A[i] = (float*)malloc(n * sizeof(float));
    
    
    //making matrix
    printf("\nFill %d x %d matrix entries, of one row at a time followed by those of the next row.\n", m, n);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%f", &A[i][j]);
        }
    }

    if(m > n){
        printf("\nAs number of rows are greater than that of columns, the right inverse DOES NOT exist. Below is the matrix you enetered. Thank you.\n");
        for(i=0;i<m;i++){
            printf("\n");
        for(j=0;j<n;j++){
            printf("%f  ", A[i][j]);
        }
    }
        exit(1); // 1 in the argument assures the exit function runs, 0 does the opposite
    }

    float** AAt;

    AAt = pro(A, m, n);
    
    /*for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<m;j++){
            printf("%f  ", AAt[i][j]);
            AAt = pro(A, m, n); // had to do it as it was not working out....yet to know why
            }
    } */
    //declaring identity matrix using pointer
}

float** pro(float**C, int m, int n){

    int i,j,k;

    float*Z[m];
    for(i=0;i<m;i++)
        Z[i] = (float*)malloc(m * sizeof(float));

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            Z[i][j] = 0;
   


    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            for(k=0;k<n;k++)
                Z[i][j]= Z[i][j] + C[i][k]*C[j][k];


    float*I[m];
    for(i=0;i<m;i++)
        I[i] = (float*)malloc(m * sizeof(float));
    
    
    //making identity matrix

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(i==j){
                I[i][j]=1;}
            else{
                I[i][j]=0;
            }
        }
    }

    row_echelon(Z, C, I, m, n);
}
