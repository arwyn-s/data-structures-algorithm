
#define M 3
#define N 3
#include <stdio.h>

void printSprial(int mat[M][N], int m, int n, int ioff, int joff){
    
    if(m==0 || n==0) {
        return;
    }
    else if(m==1) {
        for(int k=0;k < n;k++){
            printf("%d ",mat[ioff][k+joff]);
        }
        return; 
    } else if(n==1){
        for(int k=0;k < m;k++){
            printf("%d ", mat[ioff+k][joff]);
        }
        return;
    }

    int i = ioff;
    int j = joff;
    for(int k=0;k < n-1;k++){
        printf("%d ", mat[i][j+k]);
    }
    for(int k=0;k < m-1;k++){
        printf("%d ", mat[i+k][j+n-1]);
    }
    for(int k=n-1;k > 0;k--){
        printf("%d ", mat[i+m-1][j+k]);
    }
    for(int k=m-1;k>0;k--){
        printf("%d ", mat[i+k][j]);
    }
    printSprial(mat,m-2,n-2,i+1,j+1);
}

int main(){
    int matrix[M][N] ={{1,2,3},{4,5,6},{7,8,9}};
    int visited[M][N] = {{0}};

    printSprial(matrix,M,N,0,0);
    printf("\n");
    return 0;
}