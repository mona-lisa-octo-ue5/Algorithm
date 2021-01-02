//
//  main.c
//  11-二叉树顺序存储实现
//
//  Created by 石玉龙 on 2021/1/2.
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
#define MAX_TREE_SIZE 100

typedef int Status;
typedef int CElemType;
typedef CElemType SqBiTree[MAX_TREE_SIZE];
CElemType NIL=0;
typedef struct {
    int level;
    int order;
}Position;

Status visit(CElemType c) {
    printf("%d ",c);
    return OK;
}
Status InitBiTree(SqBiTree T) {
    for (int i=0; i<MAX_TREE_SIZE; i++) {
        T[i]=NIL;
    }
    return OK;
}
Status CreateBiTree(SqBiTree T) {
    int i=0;
    while (i<10) {
        T[i]=i+1;
        printf("%d ",T[i]);
        if (i!=0&&T[(i+1)/2-1]==NIL&&T[i]!=NIL) {
            printf("出现无双亲的非根结点%d\n",T[i]);
            exit(ERROR);
        }
        i++;
    }
    while (i<MAX_TREE_SIZE) {
        T[i]=NIL;
        i++;
    }
    return OK;
}
#define ClearBiTree InitBiTree
Status BiTreeEmpty(SqBiTree T) {
    if (T[0]==NIL) {
        return TRUE;
    }
    return FALSE;
}
int BiTreeDepth(SqBiTree T) {
    int j=-1;
    int i;
    for (i=MAX_TREE_SIZE-1; i>=0; i--) {
        if (T[i]!=NIL) {
            break;
        }
    }
    do {
        j++;
    } while (powl(2, j)<=i);
    return j;
}
CElemType Value(SqBiTree T,Position e) {
    printf("%d\n",(int)pow(2, e.level-1));
    printf("%d\n",e.order);;
    return T[(int)pow(2, e.level-1)+e.order-2];
}
Status Root(SqBiTree T,CElemType *e) {
    if (BiTreeEmpty(T)) {
        return ERROR;
    }
    *e=T[0];
    return OK;
}
Status Assign(SqBiTree T,Position e,CElemType value) {
    int i=(int)powl(2, e.level-1)+e.order-2;
    if (value!=NIL&&T[(i+1)/2-1]==NIL) {
        return ERROR;
    }
    if (value==NIL&&(T[i*2+1]!=NIL||T[i*2+2]!=NIL)) {
        return ERROR;
    }
    T[i]=value;
    return OK;
}
CElemType Parent(SqBiTree T,CElemType e) {
    if (T[0]==NIL) {
        return NIL;
    }
    for (int i=1; i<MAX_TREE_SIZE; i++) {
        if (T[i]==e) {
            return T[(i+1)/2-1];
        }
    }
    return NIL;
}
CElemType LeftChild(SqBiTree T,CElemType e) {
    if (T[0]==NIL) {
        return NIL;
    }
    for (int i=0; i<MAX_TREE_SIZE-1; i++) {
        if (T[i]==e) {
            return T[i*2+1];
        }
    }
    return NIL;
}
CElemType RightChild(SqBiTree T,CElemType e) {
    if (T[0]==NIL) {
        return NIL;
    }
    for (int i=0; i<MAX_TREE_SIZE-1; i++) {
        if (T[i]==e) {
            return T[i*2+2];
        }
    }
    return NIL;
}
CElemType LeftSibling(SqBiTree T,CElemType e) {
    if (T[0]==NIL) {
        return NIL;
    }
    for (int i=1; i<=MAX_TREE_SIZE-1; i++) {
        if (T[i]==e&&i%2==0) {
            return T[i-1];
        }
    }
    return NIL;
}
CElemType RightSibling(SqBiTree T,CElemType e) {
    if (T[0]==NIL) {
        return NIL;
    }
    for (int i=1; i<=MAX_TREE_SIZE-1; i++) {
        if (T[i]==e&&i%2==1) {
            return T[i+1];
        }
    }
    return NIL;
}
void LevelOrderTraverse(SqBiTree T) {
    int i=MAX_TREE_SIZE-1;
    while (T[i]==NIL) {
        i--;
    }
    for (int j=0; j<=i; j++) {
        if (T[j]!=NIL) {
            visit(T[j]);
        }
    }
    printf("\n");
}
void PreTraverse(SqBiTree T,int e) {
    visit(T[e]);
    if (T[2*e+1]!=NIL) {
        PreTraverse(T, 2*e+1);
    }
    if (T[2*e+2]!=NIL) {
        PreTraverse(T, 2*e+2);
    }
}
Status PreOrderTraverse(SqBiTree T) {
    if (!BiTreeEmpty(T)) {
        PreTraverse(T, 0);
    }
    printf("\n");
    return OK;
}
void InTraverse(SqBiTree T,int e) {
    if (T[2*e+1]!=NIL) {
        InTraverse(T, 2*e+1);
    }
    visit(T[e]);
    if (T[2*e+2]!=NIL) {
        InTraverse(T, 2*e+2);
    }
}
Status InOrderTraverse(SqBiTree T) {
    if (!BiTreeEmpty(T)) {
        InTraverse(T, 0);
    }
    printf("\n");
    return OK;
}
void PostTraverse(SqBiTree T,int e) {
    if (T[2*e+1]!=NIL) {
        PostTraverse(T, 2*e+1);
    }
    if (T[2*e+2]!=NIL) {
        PostTraverse(T, 2*e+2);
    }
    visit(T[e]);
}
Status PostOrderTraverse(SqBiTree T) {
    if (!BiTreeEmpty(T)) {
        PostTraverse(T, 0);
    }
    printf("\n");
    return OK;
}

int main(int argc, const char * argv[]) {
    Status iStatus;
    Position p;
    CElemType e;
    SqBiTree T;
    
    InitBiTree(T);
    CreateBiTree(T);
    printf("建立二叉树后,树空否？%d(1:是 0:否) \n",BiTreeEmpty(T));
    printf("树的深度=%d\n",BiTreeDepth(T));
    
    p.level=3;
    p.order=2;
    e=Value(T,p);
    printf("第%d层第%d个结点的值: %d\n",p.level,p.order,e);
    
    
    iStatus = Root(T, &e);
    if (iStatus) {
        printf("二叉树的根为:%d\n",e);
    }else
    {
        printf("树为空,无根!\n");
    }
    
    e = 99;
    Assign(T, p, e);//向树中3层第2个结点位置上结点赋值99
    e=Value(T,p);//获取树中3层第2个结点位置结点的值是多少:
    printf("第%d层第%d个结点的值: %d\n",p.level,p.order,e);
    printf("结点%d的双亲为%d_",e,Parent(T, e));
    printf("左右孩子分别为:%d,%d\n",LeftChild(T, e),RightChild(T, e));
    printf("结点%d的左右兄弟:%d,%d\n",e,LeftSibling(T, e),RightSibling(T, e));
    
    
    Assign(T, p, 5);
    printf("二叉树T层序遍历:");
    LevelOrderTraverse(T);
    printf("二叉树T先序遍历:");
    PreOrderTraverse(T);
    printf("二叉树T中序遍历:");
    InOrderTraverse(T);
    printf("二叉树T后序遍历:");
    PostOrderTraverse(T);
    return 0;
}
