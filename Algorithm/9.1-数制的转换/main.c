//
//  main.c
//  9.1-数制的转换
//
//  Created by 石玉龙 on 2020/12/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int SElemType;
typedef struct {
    SElemType data[MAXSIZE];
    int top;
}SqStack;

Status InitStack(SqStack *S) {
    S->top=-1;
    return OK;
}
Status ClearStack(SqStack *S) {
    S->top=-1;
    return OK;
}
Status StackEmpty(SqStack S) {
    if (S.top==-1) {
        return TRUE;
    }
    return FALSE;
}
int StackLength(SqStack S) {
    return S.top+1;
}
Status GetTop(SqStack S,SElemType *e) {
    if (S.top==-1) {
        return ERROR;
    }else{
        *e=S.data[S.top];
    }
    return OK;
}
Status PushData(SqStack *S,SElemType e) {
    if (S->top==MAXSIZE-1) {
        return ERROR;
    }
    S->top++;
    S->data[S->top]=e;
    return OK;
}
Status Pop(SqStack *S,SElemType *e) {
    if (S->top==-1) {
        return ERROR;
    }
    *e=S->data[S->top];
    S->top--;
    return OK;
}
Status StackTraverse(SqStack S) {
    int i=0;
    printf("此栈中所有元素");
    while (i<=S.top) {
        printf("%d ",S.data[i++]);
    }
    printf("\n");
    return OK;
}
void conversion(int N) {
    SqStack S;
    SElemType e;
    InitStack(&S);
    while (N) {
        PushData(&S, N%8);
        N=N/8;
    }
    while (!StackEmpty(S)) {
        Pop(&S, &e);
        printf("%d\n",e);
    }
}

int main(int argc, const char * argv[]) {
    conversion(1348);
    return 0;
}
