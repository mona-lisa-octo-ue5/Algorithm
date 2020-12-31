//
//  main.c
//  8-队列表示与操作实现-链队列表示与操作实现
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
typedef int QElemType;
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct {
    QueuePtr front,rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q) {
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if (!Q->front) {
        return ERROR;
    }
    Q->front->next=NULL;
    return OK;
}
Status DestoryQueue(LinkQueue *Q) {
    while (Q->front) {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}
Status ClearQueue(LinkQueue *Q) {
    QueuePtr p,q;
    Q->rear=Q->front;
    p=Q->front->next;
    Q->front->next=NULL;
    while (p) {
        q=p;
        p=p->next;
        free(q);
    }
    return OK;
}
Status QueueEmpty(LinkQueue Q) {
    if (Q.front==Q.rear) {
        return TRUE;
    }
    return FALSE;
}
int QueueLength(LinkQueue Q) {
    int i=0;
    QueuePtr p;
    p=Q.front;
    while (Q.rear!=p) {
        i++;
        p=p->next;
    }
    return i;
}
Status EnQueue(LinkQueue *Q,QElemType e) {
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    if (!s) {
        return ERROR;
    }
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;
    return OK;
}
Status DeQueue(LinkQueue *Q,QElemType *e) {
    QueuePtr p;
    if (Q->front==Q->rear) {
        return ERROR;
    }
    p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    if (Q->rear==p) {
        Q->rear=Q->front;
    }
    free(p);
    return OK;
}
Status GetHead(LinkQueue Q,QElemType *e) {
    if (Q.front!=Q.rear) {
        *e=Q.front->next->data;
        return TRUE;
    }
    return FALSE;
}
Status QueueTraverse(LinkQueue Q) {
    QueuePtr p;
    p=Q.front->next;
    while (p) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

int main(int argc, const char * argv[]) {
    Status iStatus;
    QElemType d;
    LinkQueue q;
    
    //1.初始化队列q
    iStatus = InitQueue(&q);
    
    //2. 判断是否创建成
    if (iStatus) {
        printf("成功地构造了一个空队列\n");
    }
    
    //3.判断队列是否为空
    printf("是否为空队列?%d (1:是 0:否)\n",QueueEmpty(q));
    
    //4.获取队列的长度
    printf("队列的长度为%d\n",QueueLength(q));
    
    //5.插入元素到队列中
    EnQueue(&q, -3);
    EnQueue(&q, 6);
    EnQueue(&q, 12);
    
    printf("队列的长度为%d\n",QueueLength(q));
    printf("是否为空队列?%d (1:是 0:否)\n",QueueEmpty(q));
    
    //6.遍历队列
    printf("队列中的元素如下:\n");
    QueueTraverse(q);

    //7.获取队列头元素
    iStatus = GetHead(q, &d);
    if (iStatus == OK) {
        printf("队头元素是:%d\n",d);
    }
    
    //8.删除队头元素
    iStatus =DeQueue(&q, &d);
    if (iStatus == OK) {
        printf("删除了的队头元素为:%d\n",d);
    }
    
    //9.获取队头元素
    iStatus = GetHead(q, &d);
    if (iStatus == OK) {
        printf("新的队头元素为:%d\n",d);
    }
    
    //10.清空队列
    ClearQueue(&q);
    
    //11.销毁队列
    DestoryQueue(&q);
    return 0;
}
