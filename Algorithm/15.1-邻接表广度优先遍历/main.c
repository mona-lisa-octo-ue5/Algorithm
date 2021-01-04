//
//  main.c
//  15.1-邻接表广度优先遍历
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
#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITYC 65535

typedef int Status;
typedef int Boolean;
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
}MGraph;
typedef struct EdgeNode{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode{
    int in;
    char data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];
typedef struct {
    AdjList adjList;
    int numVertexes,numEdges;
}graphAdjList,*GraphAdjList;
typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
}Queue;
Status InitQueue(Queue *Q) {
    Q->front=0;
    Q->rear=0;
    return OK;
}
Status QueueEmpty(Queue Q) {
    if (Q.front==Q.rear) {
        return TRUE;
    }
    return FALSE;
}
Status EnQueue(Queue *Q,int e) {
    if ((Q->rear+1)%MAXSIZE==Q->front) {
        return ERROR;
    }
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}
Status DeQueue(Queue *Q,int *e) {
    if (Q->front==Q->rear) {
        return ERROR;
    }
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return OK;
}
Boolean visited[MAXSIZE];
void BFSTraverse(GraphAdjList GL) {
    EdgeNode *p;
    Queue Q;
    InitQueue(&Q);
    for (int i=0; i<GL->numVertexes; i++) {
        visited[i]=FALSE;
    }
    for (int i=0; i<GL->numVertexes; i++) {
        if (!visited[i]) {
            visited[i]=TRUE;
            printf("%c ",GL->adjList[i].data);
            EnQueue(&Q, i);
            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &i);
                p=GL->adjList[i].firstedge;
                while (p) {
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex]=TRUE;
                        printf("%c ",GL->adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p=p->next;
                }
            }
        }
    }
}

void CreateMGraph(MGraph *G) {
    int i,j;
    G->numEdges=15;
    G->numVertexes=9;
    G->vexs[0]='A';
    G->vexs[1]='B';
    G->vexs[2]='C';
    G->vexs[3]='D';
    G->vexs[4]='E';
    G->vexs[5]='F';
    G->vexs[6]='G';
    G->vexs[7]='H';
    G->vexs[8]='I';
    for (i=0; i<G->numVertexes; i++) {
        for (j=0; j<G->numVertexes; j++) {
            G->arc[i][j]=0;
        }
    }
    G->arc[0][1]=1;
    G->arc[0][5]=1;
    G->arc[1][2]=1;
    G->arc[1][8]=1;
    G->arc[1][6]=1;
    G->arc[2][3]=1;
    G->arc[2][8]=1;
    G->arc[3][4]=1;
    G->arc[3][7]=1;
    G->arc[3][6]=1;
    G->arc[3][8]=1;
    G->arc[4][5]=1;
    G->arc[4][7]=1;
    G->arc[5][6]=1;
    G->arc[6][7]=1;
    for (i=0; i<G->numVertexes; i++) {
        for (j=i; j<G->numVertexes; j++) {
            G->arc[j][i]=G->arc[i][j];
        }
    }
}
void CreateALGraph(MGraph G,GraphAdjList *GL) {
    *GL=(GraphAdjList)malloc(sizeof(graphAdjList));
    (*GL)->numVertexes=G.numVertexes;
    (*GL)->numEdges=G.numEdges;
    for (int i=0; i<G.numVertexes; i++) {
        (*GL)->adjList[i].in=0;
        (*GL)->adjList[i].data=G.vexs[i];
        (*GL)->adjList[i].firstedge=NULL;
    }
    EdgeNode *e;
    for (int i=0; i<G.numVertexes; i++) {
        for (int j=0; j<G.numVertexes; j++) {
            if (G.arc[i][j]==1) {
                e=(EdgeNode*)malloc(sizeof(EdgeNode));
                e->adjvex=j;
                e->next=(*GL)->adjList[i].firstedge;
                (*GL)->adjList[i].firstedge=e;
                (*GL)->adjList[j].in++;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    MGraph G;
    GraphAdjList GL;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);
    BFSTraverse(GL);
    printf("\n");
    return 0;
}
