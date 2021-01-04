//
//  main.c
//  13-图的存储-邻接矩阵
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
#define MAXVEX 100
#define INFINITYC 0

typedef int Status;
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numNodes,numEdges;
}MGraph;

void CreateMGraph(MGraph *G) {
    int i,j,k,w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d",&G->numNodes,&G->numEdges);
    printf("顶点数:%d,边数:%d\n",G->numNodes,G->numEdges);
    for (i=0; i<=G->numNodes; i++) {
        scanf("%c",&G->vexs[i]);
    }
    for (i=0; i<G->numNodes; i++) {
        for (j=0; j<G->numNodes; j++) {
            G->arc[i][j]=INFINITYC;
        }
    }
    for (k=0; k<G->numEdges; k++) {
        printf("输入边(vi,vj)上的下标i,下标j,权w\n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }
    for (int i=0; i<G->numNodes; i++) {
        printf("\n");
        for (int j=0; j<G->numNodes; j++) {
            printf("%d ",G->arc[i][j]);
        }
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    MGraph G;
    CreateMGraph(&G);
    return 0;
}
