//
//  main.c
//  14-图的深度优先遍历-邻接矩阵的深度优先遍历
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
Boolean visited[MAXVEX];
void DFS(MGraph G,int i){
    visited[i]=TRUE;
    printf("%c",G.vexs[i]);
    for (int j=0; j<G.numVertexes; j++) {
        if (G.arc[i][j]==1&&!visited[j]) {
            DFS(G, j);
        }
    }
}
void DFSTravese(MGraph G) {
    for (int i=0; i<G.numVertexes; i++) {
        visited[i]=FALSE;
    }
    for (int i=0; i<G.numVertexes; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

int main(int argc, const char * argv[]) {
    MGraph G;
    CreateMGraph(&G);
    DFSTravese(G);
    printf("\n");
    return 0;
}
