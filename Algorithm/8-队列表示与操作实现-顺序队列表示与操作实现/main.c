//
//  main.c
//  8-队列表示与操作实现-顺序队列表示与操作实现
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
typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue *Q) {
    Q->front=0;
    Q->rear=0;
    return OK;
}
Status ClearQueue(SqQueue *Q) {
    Q->front=Q->rear=0;
    return OK;
}
Status QueueEmpty(SqQueue Q) {
    if (Q.front==Q.rear) {
        return TRUE;
    }
    return FALSE;
}
int QueueLength(SqQueue Q) {
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
Status GetHead(SqQueue Q,QElemType *e) {
    if (Q.front==Q.rear) {
        return ERROR;
    }
    *e=Q.data[Q.front];
    return OK;
}
Status EnQueue(SqQueue *Q,QElemType e) {
    if ((Q->rear+1)%MAXSIZE==Q->front) {
        return ERROR;
    }
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}
Status DeQueue(SqQueue *Q,QElemType *e) {
    if (Q->front==Q->rear) {
        return ERROR;
    }
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return OK;
}
Status QueueTraverse(SqQueue Q) {
    int i;
    i=Q.front;
    while ((i+Q.front)!=Q.rear) {
        printf("%d   ",Q.data[i]);
        i=(i+1)%MAXSIZE;
    }
    printf("\n");
    return OK;
}


int main(int argc, const char * argv[]) {
    Status j;
    int i=0,l;
    QElemType d;
    SqQueue Q;
    InitQueue(&Q);
    printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    
    printf("入队:\n");
    while (i < 10) {
        EnQueue(&Q, i);
        i++;
    }
    QueueTraverse(Q);
    printf("队列长度为: %d\n",QueueLength(Q));
    printf("现在队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    printf("出队:\n");
   
   //出队
    DeQueue(&Q, &d);
    printf("出队的元素:%d\n",d);
    QueueTraverse(Q);

    //获取队头
    j=GetHead(Q,&d);
    if(j)
        printf("现在队头元素为: %d\n",d);
    ClearQueue(&Q);
    printf("清空队列后, 队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
    return 0;
}
