//
//  main.c
//  11.1-二叉树链式存储实现
//
//  Created by 石玉龙 on 2021/1/2.
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
typedef char CElemType;
CElemType NIL=' ';
typedef struct BiTNode{
    CElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status visit(CElemType e) {
    printf("%c ",e);
    return OK;
}
Status InitBiTree(BiTree *T) {
    *T=NULL;
    return OK;
}
void DestroyBiTree(BiTree *T) {
    if (*T) {
        if ((*T)->lchild) {
            DestroyBiTree(&(*T)->lchild);
        }
        if ((*T)->rchild) {
            DestroyBiTree(&(*T)->rchild);
        }
        free(*T);
        *T=NULL;
    }
}
#define ClearBiTree DestroyBiTree
void CreateBiTree(BiTree *T) {
    CElemType ch;
    ch=str[indexs++];
    if (ch=='#') {
        *T=NULL;
    }else{
        *T=(BiTree)malloc(sizeof(BiTNode));
        if (!*T) {
            exit(OVERFLOW);
        }
        (*T)->data=ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
Status BiTreeEmpty(BiTree T) {
    if (T) {
        return FALSE;
    }
    return TRUE;
}
int BiTreeDepth(BiTree T) {
    int i,j;
    if (!T) {
        return 0;
    }
    if (T->lchild) {
        i=BiTreeDepth(T->lchild);
    }else{
        i=0;
    }
    if (T->rchild) {
        j=BiTreeDepth(T->rchild);
    }else{
        j=0;
    }
    return i>j?i+1:j+1;
}
CElemType Root(BiTree T) {
    if (BiTreeEmpty(T)) {
        return NIL;
    }
    return T->data;
}
CElemType Value(BiTree p) {
    return p->data;
}
void Assign(BiTree p,CElemType value) {
    p->data=value;
}
void PreOrderTraverse(BiTree T) {
    if (T==NULL) {
        return;
    }
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
void InOrderTraverse(BiTree T) {
    if (T==NULL) {
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
}
void PostOrderTraverse(BiTree T) {
    if (T==NULL) {
        return;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c",T->data);
}

int main(int argc, const char * argv[]) {
    int i;
    BiTree T;
    CElemType e1;
    InitBiTree(&T);
    StrAssign(str, "ABDH#K###E##CFI###G#J##");
    CreateBiTree(&T);
    printf("二叉树是否为空%d(1:是 0:否),树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    
    e1=Root(T);
    printf("二叉树的根为: %c\n",e1);
    
    printf("\n前序遍历二叉树:");
    PreOrderTraverse(T);
    
    printf("\n中序遍历二叉树:");
    InOrderTraverse(T);
    
    printf("\n后序遍历二叉树:");
    PostOrderTraverse(T);
    
    printf("\n");
    return 0;
}
