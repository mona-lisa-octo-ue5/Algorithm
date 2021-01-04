//
//  main.c
//  13.1-邻接表
//
//  Created by 石玉龙 on 2021/1/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M 100
#define TRUE 1
#define FALSE 0

typedef char Element;
typedef int BOOL;
typedef struct Node{
    int adj_vex_index;
    Element data;
    struct Node *next;
}EdgeNode;
typedef struct vNode{
    Element data;
    EdgeNode *firstedge;
}VertexNode,Adjlist[M];
typedef struct Graph{
    Adjlist adjlist;
    int arc_num;
    int node_num;
    BOOL is_directed;
}Graph,*GraphLink;

void CreateGraph(GraphLink *g) {
    int i,j,k;
    EdgeNode *p;
    printf("输入顶点数目,边数和有向？：\n");
    scanf("%d %d %d",&(*g)->node_num,&(*g)->arc_num,&(*g)->is_directed);
    printf("输入顶点信息：\n");
    for (i=0; i<(*g)->node_num; i++) {
        getchar();
        scanf("%c",&(*g)->adjlist[i].data);
        (*g)->adjlist[i].firstedge=NULL;
    }
    printf("输入边信息：\n");
    for (k=0; k<(*g)->arc_num; k++) {
        getchar();
        scanf("%d %d",&i,&j);
        p=(EdgeNode *)malloc(sizeof(EdgeNode));
        p->adj_vex_index=j;
        p->next=(*g)->adjlist[i].firstedge;
        (*g)->adjlist[i].firstedge=p;
        if (!(*g)->is_directed) {
            p=(EdgeNode *)malloc(sizeof(EdgeNode));
            p->adj_vex_index=i;
            p->next=(*g)->adjlist[j].firstedge;
            (*g)->adjlist[j].firstedge=p;
        }
    }
}
void PutGraph(GraphLink g) {
    int i;
    printf("邻接表中存储信息:\n");
    for (i=0; i<g->node_num; i++) {
        EdgeNode *p=g->adjlist[i].firstedge;
        while (p) {
            printf("%c->%c ", g->adjlist[i].data, g->adjlist[p->adj_vex_index].data);
            p=p->next;
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    GraphLink g=(Graph *)malloc(sizeof(Graph));
    CreateGraph(&g);
    PutGraph(g);
    return 0;
}
