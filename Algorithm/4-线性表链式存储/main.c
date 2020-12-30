//
//  main.c
//  4-线性表链式存储
//
//  Created by 石玉龙 on 2020/12/30.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OK 1
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

Status InitList(LinkList *L) {
    *L=(LinkList)malloc(sizeof(Node));
    if (*L==NULL) {
        return ERROR;
    }
    (*L)->next=NULL;
    return OK;
}
Status ListInsert(LinkList *L,int i,ElemType e) {
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while (p&&j<i) {
        p=p->next;
        ++j;
    }
    if (!p||j>1) {
        return ERROR;
    }
    s=(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}
Status GetElem(LinkList L,int i,ElemType *e) {
    int j;
    LinkList p;
    p=L->next;
    j=1;
    while (p&&j<i) {
        p=p->next;
        ++j;
    }
    if (!p||j>i) {
        return ERROR;
    }
    *e=p->data;
    return OK;
}
Status ListDelete(LinkList *L,int i,ElemType *e) {
    int j;
    LinkList p,q;
    p=(*L)->next;
    j=1;
    
    while (p->next&&j<(i-1)) {
        p=p->next;
        ++j;
    }
    if (!(p->next)||(j>i-1)) {
        return ERROR;
    }
    q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
    
    return OK;
}
void CreateListHead(LinkList *L,int n) {
    LinkList p;
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
    
    for (int i=0; i<n; i++) {
        p=(LinkList)malloc(sizeof(Node));
        p->data=i;
        p->next=(*L)->next;
        (*L)->next=p;
    }
}
void CreateListTail(LinkList *L,int n) {
    LinkList p,r;
    *L=(LinkList)malloc(sizeof(Node));
    r=*L;
    for (int i=0; i<n; i++) {
        p=(Node *)malloc(sizeof(Node));
        p->data=i;
        r->next=p;
        r=p;
    }
    r->next=NULL;
}
Status ListTraverse(LinkList L) {
    LinkList p=L->next;
    while (p) {
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
Status ClearList(LinkList *L) {
    LinkList p,q;
    p=(*L)->next;
    while (p) {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return OK;
}

int main(int argc, const char * argv[]) {
    
    Status iStatus;
    LinkList L1,L;
    struct Node *L2;
    ElemType e;
    
    L1=(LinkList)malloc(sizeof(Node));
    L2=(LinkList)malloc(sizeof(Node));
    L1->data=1;
    L2->data=2;
    printf("L1->data =%d,L2->data =%d\n", L1->data,L2->data);
    iStatus=InitList(&L);
    printf("L 是否初始化成功？（0:失败，1:成功）%d\n", iStatus);
    for (int j=1; j<=10; j++) {
        iStatus=ListInsert(&L, 1, j);
    }
    printf("L 插入后\n");
    ListTraverse(L);
    GetElem(L, 5, &e);
    printf("第5 个元素的值为：%d\n", e);
    iStatus=ListDelete(&L, 5, &e);
    printf("删除第5 个元素值为：%d\n", e);
    ListTraverse(L);
    iStatus=ClearList(&L);
    CreateListHead(&L, 20);
    printf("整理创建L 的元素（前插法）：\n");
    ListTraverse(L);
    iStatus = ClearList(&L);
    CreateListTail(&L, 20);
    printf("整理创建L 的元素（后插法）：\n");
    ListTraverse(L);
    return 0;
}
