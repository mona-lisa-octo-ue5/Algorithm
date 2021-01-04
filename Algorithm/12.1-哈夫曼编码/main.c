//
//  main.c
//  12.1-哈夫曼编码
//
//  Created by 石玉龙 on 2021/1/4.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MaxValue = 10000;
const int MaxBit=4;
const int MaxN=10;
typedef struct HaffNode {
    int weight;
    int flag;
    int parent;
    int leftChild;
    int rightChild;
}HaffNode;
typedef struct Code {
    int bit[MaxBit];
    int start;
    int weight;
}Code;

void Haffman(int weight[],int n,HaffNode *haffTree) {
    int j,m1,m2,x1,x2;
    for (int i=0; i<2*n-1; i++) {
        if (i<n) {
            haffTree[i].weight=weight[i];
        }else{
            haffTree[i].weight=0;
        }
        haffTree[i].parent=0;
        haffTree[i].flag=0;
        haffTree[i].leftChild=-1;
        haffTree[i].rightChild=-1;
    }
    for (int i=0; i<n-1; i++) {
        m1=m2=MaxValue;
        x1=x2=0;
        for (j=0; j<n+i; j++) {
            if (haffTree[j].weight<m1&&haffTree[j].flag==0) {
                m2=m1;
                x2=x1;
                m1=haffTree[j].weight;
                x1=j;
            }else if(haffTree[j].weight<m2&&haffTree[j].flag==0) {
                m2=haffTree[j].weight;
                x2=j;
            }
        }
        haffTree[x1].parent=n+i;
        haffTree[x2].parent=n+i;
        haffTree[x1].flag=1;
        haffTree[x2].flag=1;
        haffTree[n+i].weight=haffTree[x1].weight+haffTree[x2].weight;
        haffTree[n+i].leftChild=x1;
        haffTree[n+i].rightChild=x2;
    }
}
void HaffmanCode(HaffNode haffTree[],int n,Code haffCode[]) {
    Code *cd=(Code *)malloc(sizeof(Code));
    int child,parent;
    for (int i=0; i<n; i++) {
        cd->start=0;
        cd->weight=haffTree[i].weight;
        child=i;
        parent=haffTree[child].parent;
        while (parent!=0) {
            if (haffTree[parent].leftChild==child) {
                cd->bit[cd->start]=0;
            }else{
                cd->bit[cd->start]=1;
            }
            cd->start++;
            child=parent;
            parent=haffTree[child].parent;
        }
        int temp=0;
        for (int j=cd->start-1; j>=0; j--) {
            temp=cd->start-j-1;
            haffCode[i].bit[temp]=cd->bit[j];
        }
        haffCode[i].start=cd->start;
        haffCode[i].weight=cd->weight;
    }
}
int main(int argc, const char * argv[]) {
    int i,j,n=4,m=0;
    int weight[]={2,4,5,7};
    HaffNode *myHaffTree=malloc(sizeof(HaffNode)*2*n-1);
    Code *myHaffCode=malloc(sizeof(Code)*n);
    if (n>MaxN) {
        printf("定义的n越界，修改MaxN!");
        exit(0);
    }
    Haffman(weight, n, myHaffTree);
    HaffmanCode(myHaffTree, n, myHaffCode);
    for (i=0; i<n; i++) {
        printf("Weight = %d\n",myHaffCode[i].weight);
        for (j=0; j<myHaffCode[i].start; j++) {
            printf("%d",myHaffCode[i].bit[j]);
        }
        m=m+myHaffCode[i].weight*myHaffCode[i].start;
        printf("\n");
    }
    printf("Huffman's WPS is:%d\n",m);
    return 0;
}
