//
//  main.c
//  16.1-Kruskal
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
#define MAXEDGE 20
#define MAXVEX 20
#define INFINITYC 65535

typedef int Status;
typedef struct {
    int arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
}MGraph;
typedef struct {
    int begin;
    int end;
    int weight;
}Edge;

void CreateMGraph(MGraph *G) {
    int i,j;
    G->numEdges=15;
    G->numVertexes=9;
    for (i=0; i<G->numVertexes; i++) {
        for (j=0; j<G->numVertexes; j++) {
            if (i==j) {
                G->arc[i][j]=0;
            }else{
                G->arc[i][j]=G->arc[j][i]=INFINITYC;
            }
        }
    }
    G->arc[0][1]=10;
    G->arc[0][5]=11;
    G->arc[1][2]=18;
    G->arc[1][8]=12;
    G->arc[1][6]=16;
    G->arc[2][8]=8;
    G->arc[2][3]=22;
    G->arc[3][8]=21;
    G->arc[3][6]=24;
    G->arc[3][7]=16;
    G->arc[3][4]=20;
    G->arc[4][7]=7;
    G->arc[4][5]=26;
    G->arc[5][6]=17;
    G->arc[6][7]=19;
    for (i=0; i<G->numVertexes; i++) {
        for (j=i; j<G->numVertexes; j++) {
            G->arc[j][i]=G->arc[i][j];
        }
    }
}
void Swapn(Edge *edges,int i,int j) {
    int tempValue;
    tempValue=edges[i].begin;
    edges[i].begin=edges[j].begin;
    edges[j].begin=tempValue;
    tempValue=edges[i].end;
    edges[i].end=edges[j].end;
    edges[j].end=tempValue;
    tempValue=edges[i].weight;
    edges[i].weight=edges[j].weight;
    edges[j].weight=tempValue;
}
void sort(Edge edges[],MGraph *G) {
    int i,j;
    for (i=0; i<G->numEdges; i++) {
        for (j=i+1; j<G->numEdges; j++) {
            if (edges[i].weight>edges[j].weight) {
                Swapn(edges, i, j);
            }
        }
    }
    printf("边集数组根据权值排序之后的为:\n");
    for (i=0; i<G->numEdges; i++) {
        printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
    }
}
int Find(int *parent, int f) {
    while (parent[f]>0) {
        f=parent[f];
    }
    return f;
}
void MiniSpanTree_Kruskal(MGraph G) {
    int i,j,n,m;
    int sum=0;
    int k=0;
    int parent[MAXVEX];
    Edge edges[MAXVEX];
    for (i=0; i<G.numVertexes-1; i++) {
        for (j=i+1; j<G.numVertexes; j++) {
            if (G.arc[i][j]<INFINITYC) {
                edges[k].begin=i;
                edges[k].end=j;
                edges[k].weight=G.arc[i][j];
                k++;
            }
        }
    }
    sort(edges, &G);
    for (i=0; i<MAXVEX; i++) {
        parent[i]=0;
    }
    printf("打印最小生成树：\n");
    for (i=0; i<G.numEdges; i++) {
        n=Find(parent, edges[i].begin);
        m=Find(parent, edges[i].end);
        if (n!=m) {
            parent[n]=m;
            printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
            sum+=edges[i].weight;
        }
    }
    printf("sum = %d\n",sum);
}

int main(int argc, const char * argv[]) {
    MGraph G;
    CreateMGraph(&G);
    MiniSpanTree_Kruskal(G);
    return 0;
}
