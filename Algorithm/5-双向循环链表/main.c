//
//  main.c
//  5-双向循环链表
//
//  Created by 石玉龙 on 2020/12/31.
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
typedef struct Node {
    ElemType data;
    struct Node *prior;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

Status CreateLinkList(LinkList *L) {
    *L=(LinkList)malloc(sizeof(Node));
    if (*L==NULL) {
        return ERROR;
    }
    (*L)->prior=NULL;
    (*L)->next=NULL;
    (*L)->data=-1;
    
    LinkList p=*L;
    for (int i=0; i<10; i++) {
        LinkList temp=(LinkList)malloc(sizeof(Node));
        temp->prior=NULL;
        temp->next=NULL;
        temp->data=i;
        p->next=temp;
        temp->prior=p;
        p=p->next;
    }
    return OK;
}

void display(LinkList L) {
    LinkList temp=L->next;
    if (temp==NULL) {
        printf("打印的双向链表为空！\n");
        return;
    }
    while (temp) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

Status ListInsert(LinkList *L,int i,ElemType data) {
    if (i<1) {
        return ERROR;
    }
    LinkList temp=(LinkList)malloc(sizeof(Node));
    temp->data=data;
    temp->prior=NULL;
    temp->next=NULL;
    LinkList p=*L;
    for (int j=1; j<i && p; j++) {
        p=p->next;
    }
    if (p==NULL) {
        return ERROR;
    }
    if (p->next==NULL) {
        p->next=temp;
        temp->prior=p;
    }else{
        p->next->prior=temp;
        temp->next=p->next;
        p->next=temp;
        temp->prior=p;
    }
    return OK;
}

Status ListDelete(LinkList *L,int i,ElemType *e) {
    int k=1;
    LinkList p=(*L);
    if (*L==NULL) {
        return ERROR;
    }
    while (k<i&&p!=NULL) {
        p=p->next;
        k++;
    }
    if (k>i||p==NULL) {
        return ERROR;
    }
    LinkList delTemp=p->next;
    *e=delTemp->data;
    p->next=delTemp->next;
    if (delTemp->next!=NULL) {
        delTemp->next->prior=p;
    }
    free(delTemp);
    return OK;
}

Status LinkListDeletVAL(LinkList *L,int data) {
    LinkList p=*L;
    while (p) {
        if (p->data==data) {
            p->prior->next=p->next;
            if (p->next!=NULL) {
                p->next->prior=p->prior;
            }
            free(p);
            break;
        }
        p=p->next;
    }
    return OK;
}

int SelectElem(LinkList L,ElemType elem) {
    LinkList p=L->next;
    int i=1;
    while (p) {
        if (p->data==elem) {
            return i;
        }
        i++;
        p=p->next;
    }
    return -1;
}

Status ReplaceLinkList(LinkList *L,int index,ElemType newElem) {
    LinkList p=(*L)->next;
    for (int i=1; i<index; i++) {
        p=p->next;
    }
    p->data=newElem;
    return OK;
}

int main(int argc, const char * argv[]) {
    Status iStatus=0;
    LinkList L;
    int temp,item,e;
    iStatus=CreateLinkList(&L);
    printf("iStatus = %d:\n", iStatus);
    printf("双向循环链表创建成功，打印链表：\n");
    display(L);
    printf("请输入前向插入的位置(位置空格数值)，例如：2 5 \n");
    scanf("%d %d", &temp, &item);
    iStatus = ListInsert(&L, temp, item);
    printf("插入数据，打印双向循环链表：\n");
    display(L);
    printf("请输入中间插入的位置(位置空格数值)，例如：2 5 \n");
    scanf("%d %d", &temp, &item);
    iStatus = ListInsert(&L, temp, item);
    printf("插入数据，打印双向循环链表：\n");
    display(L);
    printf("请输入尾部插入的位置(位置空格数值)，例如：2 5 \n");
    scanf("%d %d", &temp, &item);
    iStatus = ListInsert(&L, temp, item);
    printf("插入数据，打印双向循环链表：\n");
    display(L);
    printf("请输入双向循环链表删除首元结点数据位置，例如：1\n");
    scanf("%d", &temp);
    iStatus = ListDelete(&L, temp, &e);
    printf("删除元素: 删除位置为%d,data = %d\n",temp,e);
    printf("删除操作之后的,双向链表:\n");
    display(L);
    printf("请输入双向循环链表删除中间结点数据位置，例如：5\n");
    scanf("%d", &temp);
    iStatus = ListDelete(&L, temp, &e);
    printf("删除元素: 删除位置为%d,data = %d\n",temp,e);
    printf("删除操作之后的,双向链表:\n");
    display(L);
    printf("请输入双向循环链表删除末尾结点数据位置，例如：7\n");
    scanf("%d", &temp);
    iStatus = ListDelete(&L, temp, &e);
    printf("删除元素: 删除位置为%d,data = %d\n",temp,e);
    printf("删除操作之后的,双向链表:\n");
    display(L);
    printf("双向循环链表删除指定数据：\n");
    scanf("%d", &temp);
    iStatus = LinkListDeletVAL(&L, temp);
    printf("删除指定data 域等于%d 的结点，双向循环链表是：\n", temp);
    display(L);
    printf("双向循环链表查找结点数据,如 6:\n");
    scanf("%d", &temp);
    ElemType index = SelectElem(L, temp);
    printf("在双向循环链表中查找到数据域为%d 的结点，位置是：%d\n", temp, index);
    printf("双向循环链表更新结点数据，如 5 50 :\n");
    scanf("%d %d", &temp, &item);
    iStatus = ReplaceLinkList(&L, temp, item);
    printf("更新结点数据后的双向循环链表是：\n");
    display(L);
    
    return 0;
}
