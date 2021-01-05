//
//  main.c
//  22.4-堆排序算法
//
//  Created by 石玉龙 on 2021/1/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
void HeapAjust(SqList *L,int s,int m){
    int temp,j;
    temp=L->r[s];
    for (j=2*s; j<=m; j*=2) {
        if (j<m&&L->r[j]<L->r[j+1]) {
            ++j;
        }
        if (temp>=L->r[j]) {
            break;
        }
        L->r[s]=L->r[j];
        s=j;
    }
    L->r[s]=temp;
}
void HeapSort(SqList *L){
    int i;
    for (i=L->length/2; i>0; i--) {
        HeapAjust(L, i, L->length);
    }
    for (i=L->length; i>1; i--) {
        swap(L, 1, i);
        HeapAjust(L, 1, i-1);
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
    printf("堆排序:\n");
    HeapSort(&l6);
    print(l6);
    printf("\n");
    return 0;
}
