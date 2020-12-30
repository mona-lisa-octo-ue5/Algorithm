//
//  main.c
//  2-线性表
//
//  Created by 石玉龙 on 2020/12/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct {
    ElemType *data;
    int length;
}Sqlist;

Status InitList(Sqlist *L) {
    L->data=malloc(sizeof(ElemType)*MAXSIZE);
    if (!L->data) {
        exit(ERROR);
    }
    L->length=0;
    return OK;
}

Status ListInsert(Sqlist *L,int i,ElemType e) {
    if ((i<1)||(i>L->length+1)) {
        return ERROR;
    }
    if (L->length==MAXSIZE) {
        return ERROR;
    }
    if (i<=L->length) {
        for (int j=L->length-1; j>=i-1; j--) {
            L->data[j+1]=L->data[j];
        }
    }
    L->data[i-1]=e;
    ++L->length;
    return OK;
}

Status GetElem(Sqlist L,int i,ElemType *e) {
    if (i<1||i>L.length) {
        return ERROR;
    }
    *e=L.data[i-1];
    return OK;
}

Status ListDelete(Sqlist *L,int i) {
    if (L->length==0) {
        return ERROR;
    }
    if ((i<1)||(i>L->length)) {
        return ERROR;
    }
    for (int j=i; j<L->length; j++) {
        L->data[j-1]=L->data[j];
    }
    L->length--;
    return OK;
}

Status ClearList(Sqlist *L) {
    L->length=0;
    return OK;
}

Status ListEmpty(Sqlist L) {
    if (L.length==0) {
        return TRUE;
    }
    return FALSE;
}

int ListLength(Sqlist L) {
    return L.length;
}

Status TraverseList(Sqlist L) {
    for (int i=0; i<L.length; i++) {
        printf("%d\n",L.data[i]);
    }
    printf("\n");
    return OK;
}

int LocateElem(Sqlist L,ElemType e) {
    int i;
    if (L.length==0) {
        return 0;
    }
    for (i=0; i<L.length; i++) {
        if (L.data[i]==e) {
            break;
        }
    }
    if (i>=L.length) {
        return 0;
    }
    return i+1;
}

int main(int argc, const char * argv[]) {
    Sqlist L,Lb;
    ElemType e;
    Status iStatus;
    
    iStatus=InitList(&L);
    printf("初始化L 后：L.length = %d\n", L.length);
    
    for (int j=1; j<=5; j++) {
        iStatus=ListInsert(&L, 1, j);
    }
    printf("插入数据L 长度：%d\n", L.length);
    
    GetElem(L, 5, &e);
    printf("顺序表L 第5个元素的值为：%d\n", e);
    
    ListDelete(&L, 2);
    printf("顺序表删除第%d 元素，长度为%d \n", 2,L.length);
    
    iStatus = ClearList(&L);
    printf("清空后，L.length = %d\n", L.length);
    
    iStatus = ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n", iStatus);
    
    for (int j = 1; j <= 5; j ++)
    {
        iStatus = ListInsert(&L, 1, j);
    }
    
    TraverseList(L);
    
    return 0;
}
