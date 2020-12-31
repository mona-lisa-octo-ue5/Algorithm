//
//  main.c
//  9.3-杨辉三角
//
//  Created by 石玉龙 on 2020/12/31.
//

#include <stdio.h>
#include <stdlib.h>

int **generate(int numRows,int *returnSize) {
    *returnSize=numRows;
    int **res=(int **)malloc(sizeof(int *)*numRows);
    for (int i=0; i<numRows; i++) {
        res[i]=(int *)malloc(sizeof(int)*(i+1));
        res[i][0]=1;
        res[i][i]=1;
        for (int j=1; j<i; j++) {
            res[i][j]=res[i-1][j]+res[i-1][j-1];
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int numRows = 5;
    int returnSize;
    int **returnResult;
    
    returnResult =  generate(numRows, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0;  j<=i; j++) {
            printf(" %d ",returnResult[i][j]);
        }
        printf("]\n");
    }
    return 0;
}
