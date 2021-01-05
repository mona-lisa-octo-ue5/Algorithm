//
//  main.c
//  20.1-二叉排序树
//
//  Created by 石玉龙 on 2021/1/4.
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

typedef int Status;
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status SearchBST(BiTree T,int key,BiTree f,BiTree *p) {
    if (!T) {
        *p=f;
        return FALSE;
    }else if(key==T->data){
        *p=T;
        return TRUE;
    }else if (key<T->data){
        return SearchBST(T->lchild, key, T, p);
    }else{
        return SearchBST(T->rchild, key, T, p);
    }
}
Status InsertBST(BiTree *T,int key){
    BiTree p,s;
    if (!SearchBST(*T, key, NULL, &p)) {
        s=(BiTree)malloc(sizeof(BiTNode));
        s->data=key;
        s->lchild=s->rchild=NULL;
        if (!p) {
            *T=s;
        }else if (key<p->data){
            p->lchild=s;
        }else{
            p->rchild=s;
            return TRUE;
        }
    }
    return FALSE;
}
Status Delete(BiTree *p){
    BiTree temp,s;
    if ((*p)->rchild==NULL) {
        temp=*p;
        *p=(*p)->lchild;
        free(temp);
    }else if ((*p)->lchild==NULL){
        temp=*p;
        *p=(*p)->rchild;
        free(temp);
    }else{
        temp=*p;
        s=(*p)->lchild;
        while (s->rchild) {
            temp=s;
            s=s->rchild;
        }
        (*p)->data=s->data;
        if (temp!=*p) {
            temp->rchild=s->lchild;
        }else{
            temp->lchild=s->lchild;
        }
        free(s);
    }
    return TRUE;
}
Status DeleteBST(BiTree *T,int key){
    if (!*T) {
        return FALSE;
    }else{
        if (key==(*T)->data) {
            return Delete(T);
        }else if (key<(*T)->data){
            return DeleteBST(&(*T)->lchild, key);
        }else{
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

int main(int argc, const char * argv[]) {
    int i;
    int a[10]={62,88,58,47,35,73,51,99,37,93};
    BiTree T=NULL;
    for (i=0; i<10; i++) {
        InsertBST(&T, a[i]);
    }
    BiTree p;
    int statusValue=SearchBST(T, 99, NULL, &p);
    printf("查找%d是否成功:%d (1->YES/0->NO)\n",p->data,statusValue);
    statusValue=DeleteBST(&T, 93);
    printf("二叉排序树删除93是否成功:%d (1->YES/0->NO)\n",statusValue);
    statusValue = DeleteBST(&T,47);
    printf("二叉排序树删除47是否成功:%d (1->YES/0->NO)\n",statusValue);
    statusValue = DeleteBST(&T,12);
    printf("二叉排序树删除12是否成功:%d (1->YES/0->NO)\n",statusValue);
    statusValue = SearchBST(T, 93, NULL, &p);
    printf("查找%d是否成功:%d (1->YES/0->NO)\n",93,statusValue);
    statusValue = SearchBST(T, 47, NULL, &p);
    printf("查找%d是否成功:%d (1->YES/0->NO)\n",47,statusValue);
    statusValue = SearchBST(T, 99, NULL, &p);
    printf("查找%d是否成功:%d (1->YES/0->NO)\n",99,statusValue);
    printf("\n");
    return 0;
}
