//
//  main.c
//  6-循环链表处理
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
    struct Node *next;
}Node;
typedef struct Node *LinkList;

Status CreateList(LinkList *L) {
    int item;
    LinkList temp=NULL;
    LinkList target=NULL;
    printf("输入结点的值，输入0结束:\n");
    while (1) {
        scanf("%d",&item);
        if (item==0) {
            break;
        }
        if (*L==NULL) {
            *L=(LinkList)malloc(sizeof(Node));
            if (!L) {
                exit(0);
            }
            (*L)->data=item;
            (*L)->next=*L;
        }else{
            for (target=*L; target->next!=*L; target=target->next) {
            }
            
            temp=(LinkList)malloc(sizeof(Node));
            if (!temp) {
                return ERROR;
            }
            temp->data=item;
            temp->next=*L;
            target->next=temp;
        }
    }
    return OK;
}

void show(LinkList p) {
    if (p==NULL) {
        printf("打印的链表为空！\n");
        return;
    }else{
        LinkList temp;
        temp=p;
        do {
            printf("%5d",temp->data);
            temp=temp->next;
        } while (temp!=p);
        printf("\n");
    }
}

Status ListInsert(LinkList *L,int place,int num) {
    LinkList temp,target;
    int i;
    if (place==1) {
        temp=(LinkList)malloc(sizeof(Node));
        if (temp==NULL) {
            return ERROR;
        }
        temp->data=num;
        for (target=*L; target->next!=*L; target=target->next) {
            
        }
        temp->next=*L;
        target->next=temp;
        *L=temp;
    }else{
        temp=(LinkList)malloc(sizeof(Node));
        if (temp==NULL) {
            return ERROR;
        }
        temp->data=num;
        for (i=1,target=*L; target->next!=*L&&i!=place-1; target=target->next,i++) {

        }
        temp->next=target->next;
        target->next=temp;
    }
    return OK;
}

Status LinkListDelete(LinkList *L,int place) {
    LinkList temp,target;
    int i;
    temp=*L;
    if (temp==NULL) {
        return ERROR;
    }
    if (place==1) {
        if ((*L)->next==(*L)) {
            (*L)=NULL;
            return OK;
        }
        for (target=*L; target->next!=*L; target=target->next) {
            
        }
        temp=*L;
        *L=(*L)->next;
        target->next=*L;
        free(temp);
    }else{
        for (i=1,target=*L; target->next!=*L&&i!=place-1; target=target->next,i++) {
            
        }
        temp=target->next;
        target->next=temp->next;
        free(temp);
    }
    return OK;
}

int findValue(LinkList L,int value) {
    int i=1;
    LinkList p;
    p=L;
    while (p->data!=value&&p->next!=L) {
        i++;
        p=p->next;
    }
    if (p->next==L&&p->data!=value) {
        return -1;
    }
    return i;
}

int main(int argc, const char * argv[]) {
    LinkList head;
    int place,num;
    int iStatus;
    iStatus=CreateList(&head);
    printf("原始的链表：\n");
    show(head);
    printf("输入要插入的位置和数据用空格隔开：");
    scanf("%d %d",&place,&num);
    iStatus = ListInsert(&head,place,num);
    show(head);
    
    printf("输入要删除的位置：");
    scanf("%d",&place);
    LinkListDelete(&head,place);
    show(head);
    
    printf("输入你想查找的值:");
    scanf("%d",&num);
    place=findValue(head,num);
    if(place!=-1)
        printf("找到的值的位置是place = %d\n",place);
    else
        printf("没找到值\n");
    
    return 0;
}
