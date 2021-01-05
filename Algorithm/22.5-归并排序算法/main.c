//
//  main.c
//  22.5-归并排序算法
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
void Merge(int SR[],int TR[],int i,int m,int n){
    int j,k,l;
    for (j=m+1,k=i; i<=m&&j<=n; k++) {
        if (SR[i]<SR[j]) {
            TR[k]=SR[i++];
        }else{
            TR[k]=SR[j++];
        }
    }
    if (i<=m) {
        for (l=0; l<=m-i; l++) {
            TR[k+l]=SR[i+l];
        }
    }
    if (j<=n) {
        for (l=0; l<=n-j; l++) {
            TR[k+l]=SR[j+l];
        }
    }
}
void MSort(int SR[],int TR1[],int low,int hight){
    int mid;
    int TR2[MAXSIZE+1];
    if (low==hight) {
        TR1[low]=SR[low];
    }else{
        mid=(low+hight)/2;
        MSort(SR, TR2, low, mid);
        MSort(SR, TR2, mid+1, hight);
        Merge(TR2, TR1, low, mid, hight);
    }
}
void MergeSort(SqList *L){
    MSort(L->r, L->r, 1, L->length);
}
void MergePass(int SR[],int TR[],int s,int length){
    int i=1;
    int j;
    while (i<=length-2*s+1) {
        Merge(SR, TR, i, i+s-1, i+2*s-1);
        i=i+2*s;
    }
    if (i<length-s+1) {
        Merge(SR, TR, i, i+s-1, length);
    }else{
        for (j=i; j<=length; j++) {
            TR[j]=SR[j];
        }
    }
}
void MergeSort2(SqList *L){
    int *TR=(int *)malloc(sizeof(int)*L->length);
    int k=1;
    while (k<L->length) {
        MergePass(L->r, TR, k, L->length);
        k=2*k;
        MergePass(TR, L->r, k, L->length);
        k=2*k;
    }
}
int main(int argc, const char * argv[]) {
    int i;
    int d[N]={-7,1,5,8,3,7,4,6,2};
    SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
    for (i=0; i<N; i++) {
        l0.r[i+1]=d[i];
    }
    l0.length=N;
    l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
    printf("排序前:\n");
    print(l0);
    printf("\n");
    printf("归并排序(递归):\n");
    MergeSort(&l7);
    print(l7);
    printf("\n");
    printf("归并排序(非递归):\n");
    MergeSort2(&l8);
    print(l8);
    printf("\n");
    return 0;
}
