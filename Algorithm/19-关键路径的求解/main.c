//
//  main.c
//  19-关键路径的求解
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
#define MAXEDGE 30
#define MAXVEX 30
#define INFINITYC 65535

typedef int Status;
typedef struct {
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
}MGraph;
typedef struct EdgeNode{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode{
    int in;
    int data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];
typedef struct {
    AdjList adjList;
    int numVertexes,numEdges;
}graphAdjList,*GraphAdjList;

void CreateMGraph(MGraph *G) {
    int i,j;
    G->numEdges=13;
    G->numVertexes=10;
    for (i=0; i<G->numVertexes; i++) {
        G->vexs[i]=i;
    }
    for (i=0; i<G->numVertexes; i++) {
        for (j=0; j<G->numVertexes; j++) {
            if (i==j) {
                G->arc[i][j]=0;
            }else{
                G->arc[i][j]=INFINITYC;
            }
        }
    }
    G->arc[0][1]=3;
    G->arc[0][2]=4;
    G->arc[1][3]=5;
    G->arc[1][4]=6;
    G->arc[2][3]=8;
    G->arc[2][5]=7;
    G->arc[3][4]=3;
    G->arc[4][6]=9;
    G->arc[4][7]=4;
    G->arc[5][7]=6;
    G->arc[6][9]=2;
    G->arc[7][8]=5;
    G->arc[8][9]=3;
}
void CreateALGraph(MGraph G,GraphAdjList *GL) {
    int i,j;
    EdgeNode *e;
    *GL=(GraphAdjList)malloc(sizeof(graphAdjList));
    (*GL)->numVertexes=G.numVertexes;
    (*GL)->numEdges=G.numEdges;
    for (i=0; i<G.numVertexes; i++) {
        (*GL)->adjList[i].in=0;
        (*GL)->adjList[i].data=G.vexs[i];
        (*GL)->adjList[i].firstedge=NULL;
    }
    for (i=0; i<G.numVertexes; i++) {
        for (j=0; j<G.numVertexes; j++) {
            if (G.arc[i][j]!=0&&G.arc[i][j]<INFINITYC) {
                e=(EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex=j;
                e->weight=G.arc[i][j];
                e->next=(*GL)->adjList[i].firstedge;
                (*GL)->adjList[i].firstedge=e;
                (*GL)->adjList[j].in++;
            }
        }
    }
}
int *etv,*ltv;
int *stack2;
int top2;
Status TopologicalSort(GraphAdjList GL) {
    EdgeNode *e;
    int i,k,gettop;
    int top=0;
    int count=0;
    int *stack=(int *)malloc(GL->numVertexes*sizeof(int));
    for (i=0; i<GL->numVertexes; i++) {
        if (0==GL->adjList[i].in) {
            stack[++top]=i;
        }
    }
    top2=0;
    stack2=(int *)malloc(sizeof(int)*GL->numVertexes);
    etv=(int*)malloc(sizeof(GL->numVertexes*sizeof(int)));
    for (i=0; i<GL->numVertexes; i++) {
        etv[i]=0;
    }
    printf("TopologicSort:\t");
    while (top!=0) {
        gettop=stack[top--];
        printf("%d -> ", GL->adjList[gettop].data);
        count++;
        stack2[++top2]=gettop;
        for (e=GL->adjList[gettop].firstedge; e; e=e->next) {
            k=e->adjvex;
            if (!(--GL->adjList[k].in)) {
                stack[++top]=k;
            }
            if ((etv[gettop]+e->weight)>etv[k]) {
                etv[k]=etv[gettop]+e->weight;
            }
        }
    }
    printf("\n");
    if (count<GL->numVertexes) {
        return ERROR;
    }else{
        return OK;
    }
    return OK;
}
void CriticalPath(GraphAdjList GL) {
    EdgeNode *e;
    int i,gettop,k,j;
    int ete,lte;
    TopologicalSort(GL);
    printf("etv:\n");
    for (i=0; i<GL->numVertexes; i++) {
        printf("etv[%d] = %d \n",i,etv[i]);
    }
    printf("\n");
    ltv=(int*)malloc(sizeof(int)*GL->numVertexes);
    for (i=0; i<GL->numVertexes; i++) {
        ltv[i]=etv[GL->numVertexes-1];
    }
    while (top2!=0) {
        gettop=stack2[top2--];
        for (e=GL->adjList[gettop].firstedge; e; e=e->next) {
            k=e->adjvex;
            if (ltv[k]-e->weight<ltv[gettop]) {
                ltv[gettop]=ltv[k]-e->weight;
            }
        }
    }
    printf("ltv:\n");
    for (i=0; i<GL->numVertexes; i++) {
        printf("ltv[%d] = %d \n",i,ltv[i]);
    }
    printf("\n");
    for (j=0; j<GL->numVertexes; j++) {
        for (e=GL->adjList[j].firstedge; e; e=e->next) {
            k=e->adjvex;
            ete=etv[j];
            lte=ltv[k]-e->weight;
            if (ete==lte) {
                printf("<%d-%d> length:%d\n",GL->adjList[j].data, GL->adjList[k].data, e->weight);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    MGraph G;
    GraphAdjList GL;
    CreateMGraph(&G);
    CreateALGraph(G, &GL);
    CriticalPath(GL);
    printf("\n");
    return 0;
}
