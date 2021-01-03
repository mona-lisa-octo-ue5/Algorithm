//
//  main.c
//  11.1-二叉树链式存储实现
//
//  Created by 石玉龙 on 2021/1/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
int indexs=1;
typedef char String[24];
String str;

Status StrAssign(String T,char *chars) {
    int i;
    if (strlen(chars)>MAXSIZE) {
        return ERROR;
    }else{
        T[0]=strlen(chars);
        for (i=1; i<=T[0]; i++) {
            T[i]=*(chars+i-1);
        }
        return OK;
    }
}
typedef char CElemType;
CElemType NIL=' ';
typedef struct BiTNode{
    
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
