//
//  main.c
//  7-栈不同表示方式与实现
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

int main(int argc, const char * argv[]) {
    SqStack S;
    int e;
    
    if (InitStack(&S) == OK) {
        for (int j = 1 ; j < 10; j++) {
            PushData(&S, j);
        }
    }
    
    printf("顺序栈中元素为:\n");
    StackTraverse(S);
    
    Pop(&S, &e);
    printf("弹出栈顶元素为: %d\n",e);
    StackTraverse(S);
    printf("是否为空栈:%d\n",StackEmpty(S));
    GetTop(S, &e);
    printf("栈顶元素:%d \n栈长度:%d\n",e,StackLength(S));
    ClearStack(&S);
    printf("是否已经清空栈 %d, 栈长度为:%d\n",StackEmpty(S),StackLength(S));
    
    return 0;
}
