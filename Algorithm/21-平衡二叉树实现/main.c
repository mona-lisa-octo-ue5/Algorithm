//
//  main.c
//  21-平衡二叉树实现
//
//  Created by 石玉龙 on 2021/1/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
#define LH +1
#define EH 0
#define RH -1

typedef int Status;
typedef struct BiTNode{
    int data;
    int bf;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void R_Rotate(BiTree *p) {
    BiTree L;
    L=(*p)->lchild;
    (*p)->lchild=L->rchild;
    L->rchild=(*p);
    *p=L;
}
void L_Rotate(BiTree *p){
    BiTree R;
    R=(*p)->rchild;
    (*p)->rchild=R->lchild;
    R->lchild=(*p);
    *p=R;
}
void LeftBalance(BiTree *T){
    BiTree L,Lr;
    L=(*T)->lchild;
    switch (L->bf) {
        case LH:
            (*T)->bf=L->bf=EH;
            R_Rotate(T);
            break;
        case RH:
            Lr=L->rchild;
            switch (Lr->bf) {
                case LH:
                    (*T)->bf=RH;
                    L->bf=EH;
                    break;
                case EH:
                    (*T)->bf=L->bf=EH;
                    break;
                case RH:
                    (*T)->bf=EH;
                    L->bf=LH;
                    break;
            }
            
            Lr->bf=EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
    }
}
void RightBalance(BiTree *T){
    BiTree R,R1;
    R=(*T)->rchild;
    switch (R->bf) {
        case RH:
            (*T)->bf=R->bf=EH;
            L_Rotate(T);
            break;
        case LH:
            R1=R->lchild;
            switch (R1->bf) {
                case RH:
                    (*T)->bf=LH;
                    R->bf=EH;
                    break;
                case EH:
                    (*T)->bf=R->bf=EH;
                    break;
                case LH:
                    (*T)->bf=EH;
                    R->bf=RH;
                    break;
            }
            
        R1->bf=EH;
        R_Rotate(&(*T)->rchild);
        L_Rotate(T);
    }
}
Status InsertAVL(BiTree *T,int e,Status *taller){
    if (!*T) {
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=NULL;
        (*T)->bf=EH;
        *taller=TRUE;
    }else{
        if (e==(*T)->data) {
            *taller=FALSE;
            return FALSE;
        }
        if (e<(*T)->data) {
            if (!InsertAVL(&(*T)->lchild, e, taller)) {
                return FALSE;
            }
            if (*taller) {
                switch ((*T)->bf) {
                    case LH:
                        LeftBalance(T);
                        *taller=FALSE;
                        break;
                    case EH:
                        (*T)->bf=LH;
                        *taller=TRUE;
                        break;
                    case RH:
                        (*T)->bf=EH;
                        *taller=FALSE;
                        break;
                }
            }
        }else{
            if (!InsertAVL(&(*T)->rchild, e, taller)) {
                return FALSE;
            }
            if (*taller) {
                switch ((*T)->bf) {
                    case LH:
                        (*T)->bf=EH;
                        *taller=FALSE;
                        break;
                    case EH:
                        (*T)->bf=RH;
                        *taller=TRUE;
                        break;
                    case RH:
                        RightBalance(T);
                        *taller=FALSE;
                        break;
                }
            }
        }
    }
    return TRUE;
}
Status SearchBST(BiTree T,int key,BiTree f,BiTree *p){
    if (!T) {
        *p=f;
        return FALSE;
    }else if (key==T->data){
        *p=T;
        return TRUE;
    }else if (key<T->data){
        return SearchBST(T->lchild, key, T, p);
    }else{
        return SearchBST(T->rchild, key, T, p);
    }
}
int main(int argc, const char * argv[]) {
    int i;
    int a[10]={3,2,1,4,5,6,7,10,9,8};
    BiTree T=NULL;
    Status taller;
    int sum=0;
    for (i=0; i<10; i++) {
        InsertAVL(&T, a[i], &taller);
        sum+=taller;
        printf("插入%d,是否增加树的高度(%d)[YES->1 / NO->0]\n",a[i],taller);
    }
    printf("将数组a插入到平衡二叉树后,最终形成高度为%d的平衡二叉树\n",sum);
    BiTree p;
    int statusValue=SearchBST(T, 10, NULL, &p);
    printf("查找%d是否成功:%d (1->YES/0->NO)\n",p->data,statusValue);
    return 0;
}
