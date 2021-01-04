//
//  main.c
//  12-线索化二叉树
//
//  Created by 石玉龙 on 2021/1/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef char CElemType;
CElemType NIL='#';
int indexs=1;
typedef char String[24];
String str;
Status StrAssign(String T,char *chars) {
    int i;
    if (strlen(chars)>MAXSIZE) {
        return ERROR;
    }else{
        T[0]=strlen(chars);
        for (i=1; i<=T[0]; i++) {
            T[i]=*(chars+i-1);
        }
        return OK;
    }
}
typedef enum {Link,Threed} PointerTag;
typedef struct BiThrNode{
    CElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode,*BiThrTree;

Status visit(CElemType e) {
    printf("%c ",e);
    return OK;
}
Status CreateBiThrTree(BiThrTree *T) {
    CElemType h;
    h=str[indexs++];
    if (h==NIL) {
        *T=NULL;
    }else{
        *T=(BiThrTree)malloc(sizeof(BiThrNode));
        if (!*T) {
            exit(OVERFLOW);
        }
        (*T)->data=h;
        CreateBiThrTree(&(*T)->lchild);
        if ((*T)->lchild) {
            (*T)->LTag=Link;
        }
        CreateBiThrTree(&(*T)->rchild);
        if ((*T)->rchild) {
            (*T)->RTag=Link;
        }
    }
    return OK;
}
BiThrTree pre;
void InThreading(BiThrTree p) {
    if (p) {
        InThreading(p->lchild);
        if (!p->lchild) {
            p->LTag=Threed;
            p->lchild=pre;
        }else{
            p->LTag=Link;
        }
        if (!pre->rchild) {
            pre->RTag=Threed;
            pre->rchild=p;
        }else{
            pre->RTag=Link;
        }
        pre=p;
        InThreading(p->rchild);
    }
}
Status InOrderThreading(BiThrTree *Thrt,BiThrTree T) {
    *Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
    if (!*Thrt) {
        exit(OVERFLOW);
    }
    (*Thrt)->LTag=Link;
    (*Thrt)->RTag=Threed;
    (*Thrt)->rchild=(*Thrt);
    if (!T) {
        (*Thrt)->lchild=*Thrt;
    }else{
        (*Thrt)->lchild=T;
        pre=(*Thrt);
        InThreading(T);
        pre->rchild=*Thrt;
        pre->RTag=Threed;
        (*Thrt)->rchild=pre;
    }
    return OK;
}
Status InOrderTraverse_Thr(BiThrTree T) {
    BiThrTree p;
    p=T->lchild;
    while (p!=T) {
        while (p->LTag==Link) {
            p=p->lchild;
        }
        if (!visit(p->data)) {
            return ERROR;
        }
        while (p->RTag==Threed&&p->rchild!=T) {
            p=p->rchild;
            visit(p->data);
        }
        p=p->rchild;
    }
    return OK;
}
int main(int argc, const char * argv[]) {
    BiThrTree H,T;
    StrAssign(str, "ABDH##I##EJ###CF##G##");
    CreateBiThrTree(&T);
    InOrderThreading(&H, T);
    InOrderTraverse_Thr(H);
    printf("\n");
    return 0;
}
