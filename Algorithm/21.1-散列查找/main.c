//
//  main.c
//  21.1-散列查找
//
//  Created by 石玉龙 on 2021/1/5.
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
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768

typedef int Status;
typedef struct {
    int *elem;
    int count;
}HashTable;
int m=0;

Status InitHashTable(HashTable *H){
    int i;
    m=HASHSIZE;
    H->count=m;
    H->elem=(int*)malloc(m*sizeof(int));
    for (i=0; i<m; i++) {
        H->elem[i]=NULLKEY;
    }
    return OK;
}
int Hash(int key){
    return key%m;
}
void InsertHash(HashTable *H,int key){
    int addr=Hash(key);
    while (H->elem[addr]!=NULLKEY) {
        addr=(addr+1)%m;
    }
    H->elem[addr]=key;
}
Status SearchHash(HashTable H,int key,int *addr){
    *addr=Hash(key);
    while (H.elem[*addr]!=key) {
        *addr=(*addr+1)%m;
        if (H.elem[*addr]==NULLKEY||*addr==Hash(key)) {
            return UNSUCCESS;
        }
    }
    return SUCCESS;
}

int main(int argc, const char * argv[]) {
    int arr[HASHSIZE]={12,67,56,16,25,37,22,29,15,47,48,34};
    int i,p,key,result;
    HashTable H;
    InitHashTable(&H);
    for (i=0; i<m; i++) {
        InsertHash(&H, arr[i]);
    }
    key=39;
    result=SearchHash(H, key, &p);
    if (result) {
        printf("查找 %d 的地址为：%d \n",key,p);
    }else{
        printf("查找 %d 失败。\n",key);
    }
    for (i=0; i<m; i++) {
        key=arr[i];
        SearchHash(H, key, &p);
        printf("查找 %d 的地址为：%d \n",key,p);
    }
    return 0;
}
