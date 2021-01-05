//
//  main.c
//  22.6-快速排序算法
//
//  Created by 石玉龙 on 2021/1/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10000
#define MAX_LENGTH_INSERT_SORT 7
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
int Partition(SqList *L,int low,int high){
    int pivotkey;
    pivotkey=L->r[low];
    while (low<high) {
        while (low<high&&L->r[high]>=pivotkey) {
            high--;
        }
        swap(L, low, high);
        while (low<high&&L->r[low]<=pivotkey) {
            low++;
        }
        swap(L, low, high);
    }
    return low;
}
void QSort(SqList *L,int low,int high){
    int pivot;
    if (low<high) {
        pivot=Partition(L, low, high);
        printf("pivot = %d L->r[%d] = %d\n",pivot,pivot,L->r[pivot]);
        QSort(L, low, pivot-1);
        QSort(L, pivot+1, high);
    }
}
void QucikSort(SqList *L){
    QSort(L, 1, L->length);
}
int Partition2(SqList *L,int low,int high){
    int pivotkey;
    int m=low+(high-low)/2;
    if (L->r[low]>L->r[high]) {
        swap(L, low, high);
    }
    if (L->r[m]>L->r[high]) {
        swap(L, high, m);
    }
    if (L->r[m]>L->r[low]) {
        swap(L, m, low);
    }
    pivotkey=L->r[low];
    L->r[0]=pivotkey;
    while (low<high) {
        while (low<high&&L->r[high]>=pivotkey) {
            high--;
        }
        L->r[low]=L->r[high];
        while (low<high&&L->r[low]<=pivotkey) {
            low++;
        }
        L->r[high]=L->r[low];
    }
    L->r[low]=L->r[0];
    return low;
}
void InsertSort(SqList *L){
    int i,j;
    int temp=0;
    for (i=2; i<=L->length; i++) {
        if (L->r[i]<L->r[i-1]) {
            temp=L->r[i];
            for (j=i-1; L->r[j]>temp; j--) {
                L->r[j+1]=L->r[j];
            }
            L->r[j+1]=temp;
        }
    }
}
void QSort2(SqList *L,int low,int high){
    int pivot;
    if ((high-low)>MAX_LENGTH_INSERT_SORT) {
        pivot=Partition(L, low, high);
        printf("pivot = %d L->r[%d] = %d\n",pivot,pivot,L->r[pivot]);
        QSort(L, low, pivot-1);
        QSort(L, pivot+1, high);
    }else{
        InsertSort(L);
    }
}
void QuickSort2(SqList *L){
    QSort2(L, 1, L->length);
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
    printf("快速排序:\n");
    QucikSort(&l9);
    print(l9);
    printf("\n");
    printf("快速排序(优化):\n");
    QuickSort2(&l10);
    print(l10);
    printf("\n");
    return 0;
}
