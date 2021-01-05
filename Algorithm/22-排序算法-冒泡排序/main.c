//
//  main.c
//  22-排序算法-冒泡排序
//
//  Created by 石玉龙 on 2021/1/5.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000
#define N 9

typedef int Status;
typedef struct {
    int r[MAXSIZE+1];
    int length;
}SqList;
void swap(SqList *L,int i,int j){
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
void print(SqList L){
    int i;
    for (i=1; i<L.length; i++) {
        printf("%d,",L.r[i]);
    }
    printf("%d",L.r[i]);
    printf("\n");
}
void BubbleSort(SqList *L){
    int i,j;
    for (i=1; i<L->length; i++) {
        for (j=i+1; j<=L->length; j++) {
            if (L->r[i]>L->r[j]) {
                swap(L, i, j);
            }
        }
    }
}
void BubbleSortBetter(SqList *L) {
    int i,j;
    for (i=1; i<L->length; i++) {
        for (j=L->length-1; j>=i; j--) {
            if (L->r[i]>L->r[j+1]) {
                swap(L, i, j+1);
            }
        }
    }
}
void BubbleSortBest(SqList *L){
    int i,j;
    Status flag=TRUE;
    for (i=1; i<L->length&&flag; i++) {
        flag=FALSE;
        for (j=L->length-1; j>=i; j--) {
            if (L->r[j]>L->r[j+1]) {
                swap(L, j, j+1);
                flag=TRUE;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int i;
    int d[N]={9,1,5,8,3,7,4,6,2};
    SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
    for (i=0; i<N; i++) {
        l0.r[i+1]=d[i];
    }
    l0.length=N;
    l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
    printf("排序前:\n");
    print(l0);
    printf("\n");
    printf("初级冒泡排序:\n");
    BubbleSort(&l0);
    print(l0);
    printf("\n");
    printf("冒泡排序:\n");
    BubbleSortBetter(&l1);
    print(l1);
    printf("\n");
    printf("冒泡排序(优化):\n");
    BubbleSortBest(&l2);
    print(l2);
    printf("\n");
    return 0;
}
