//
//  main.c
//  9.2-每日温度
//
//  Created by 石玉龙 on 2020/12/31.
//

#include <stdio.h>
#include <stdlib.h>

int *dailyTemperatures(int *T,int TSize,int *returnSize) {
    int *result=(int *)malloc(sizeof(int)*TSize);
    *returnSize=TSize;
    result[TSize-1]=0;
    
    for (int i=0; i<TSize-1; i++) {
        if (i>0&&T[i]==T[i-1]) {
            result[i]=result[i-1]==0?0:result[i-1]-1;
        }else{
            for (int j=i+1; j<TSize; j++) {
                if (T[j]>T[i]) {
                    result[i]=j-i;
                    break;
                }
                if (j==TSize-1) {
                    result[i]=0;
                }
            }
        }
    }
    return result;
}
int *dailyTemperatures2(int *T,int TSize,int *returnSize) {
    int *result=(int *)malloc(sizeof(int)*TSize);
    *returnSize=TSize;
    result[TSize-1]=0;
    for (int i=TSize-2; i>=0; i--) {
        for (int j=i+1; j<TSize; j+=result[j]) {
            if (T[i]<T[j]) {
                result[i]=j-i;
                break;
            }else{
                if (result[j]==0) {
                    result[i]=0;
                    break;
                }
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int test[10]= {73, 74, 75, 75, 69, 72, 76, 73};
    int *result;
    int returnSize;
    result=dailyTemperatures2(test, 8, &returnSize);
    printf("\n");
    for (int i = 0; i < returnSize;i++ ) {
        printf("%d ",test[i]);
    }
    printf("\n");
    
    for (int i = 0; i < returnSize;i++ ) {
        printf("%d ",result[i]);
    }
    printf("\n");
    return 0;
}
