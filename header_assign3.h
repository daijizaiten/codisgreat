#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float** row_echelon(float**, float**, float**, int, int);
float** pro(float**, int, int);

float** row_echelon(float**B, float**C, float**I, int m, int n){

    int i, j, k, l, x, y, zero_row[m], first_nonzero[m];
    int count=0;

    for(i=0;i<m;i++){
            zero_row[i] = 1;
        }


    for(i=0;i<m;i++){
        count=0;
        for(j=0;j<m;j++){

            if (B[i][j]==0){
                count++;
            }
        }

                if (count==m)
                    zero_row [i] = 0;
    }

    float temp;

    for(i=0;i<m;i++){
        if(zero_row[i]==0){
            for(j=i+1;j<m;j++){
                if(zero_row[j]==1){
                    for(k=0;k<m;k++){
                        B[i][k] = B[j][k];
                        B[j][k] = 0;
                        temp = I[i][j];
                        I[i][j] = I[j][k];
                        I[i][j] = temp;

                    }
                    zero_row[i] = 1;
                    zero_row[j] = 0;
                    break;
                }
            }
        }
    }

    
    for(i=0;i<m;i++){
        count = 0;
        for(j=0;j<m;j++){
            if(B[i][j]!= 0){
                count++;
                first_nonzero[i] = j;
                break;
            }

            if(j == (m-1) && count==0){ // count = n implies it is a zero row
                first_nonzero[i] = -1;
            }
        }
    }

    
    for(l=0;l<m;l++){
        for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            if((first_nonzero[i] > first_nonzero[j]) && (first_nonzero[j] != (-1))){
                for(k=0;k<m;k++){
                    temp = B[i][k];
                    B[i][k] = B[j][k];
                    B[j][k] = temp;

                    temp = I[i][j];
                    I[i][j] = I[j][k];
                    I[i][j] = temp;
                    }
                    temp = first_nonzero[i];
                    first_nonzero[i] = first_nonzero[j];
                    first_nonzero[j] = temp;
                    break;
            }
        }
        }
    }

    for(i=0;i<m;i++){
        if(first_nonzero[i]>=0){
            temp=B[i][first_nonzero[i]];
            for(j=0;j<m;j++){
            B[i][j] = B[i][j]/temp;
            I[i][j] = I[i][j]/temp;
            }

            for(l=0;l<m;l++){
                if(l!=i){
                    temp=B[l][first_nonzero[i]];
                    for(k=0;k<m;k++){
                    B[l][k] = B[l][k] - B[i][k]*temp;
                    I[l][k] = I[l][k] - I[i][k]*temp;
                    
                }
                }
            }

            for(x=0;x<m;x++){
        count = 0;
        for(y=0;y<m;y++){
            if(B[x][y]!= 0){
                count++;
                first_nonzero[x] = y;
                break;
            }

            if(y == (m-1) && count==0){ // count = n implies it is a zero row
                first_nonzero[x] = -1;
            }
        }
    }

            }
        
        }

        for(i=0;i<m;i++){
            zero_row[i] = 1;
        }

    count=0;
    for(i=0;i<m;i++){
        if(first_nonzero[i]==(-1)){
            count++;
        }
    }

    float*Z[n];
    for(i=0;i<n;i++)
        Z[i] = (float*)malloc(m * sizeof(float));

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            Z[i][j] = 0;    



    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            for(k=0;k<m;k++)
                Z[i][j]= Z[i][j] + C[k][i]*I[k][j];

     if (count!=0){
        printf("\nSnap! Entered matrix is NOT invertible, as it does not have full row rank.");
    }

    else{
        printf("\n\nHere is the right inverse of the entered matrix:\n\n");
        for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<m;j++){
            printf("%f  ", Z[i][j]);
        }
    }
    }

    printf("\n\nBelow is the entered matrix:\n");
        for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%f ", C[i][j]);
        }
    }


    /* printf("\nHere is the row reduced echelon form of the entered matrix:\n");

    for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<m;j++){
                printf("%f ", I[i][j]);
            }
        }

        */

    printf("\n\nThank you.\n");
}

