//
//  main.c
//  10-字符串匹配算法BF算法
//
//  Created by 石玉龙 on 2021/1/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 40

typedef int Status;
typedef int ElemType;
typedef char String[MAXSIZE+1];

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

Status ClearString(String S) {
    S[0]=0;
    return OK;
}

void StrPrint(String T) {
    int i;
    for (i=1; i<=T[0]; i++) {
        printf("%c",T[i]);
    }
    printf("\n");
}

void NextPrint(int next[],int length) {
    int i;
    for (i=1; i<=length; i++) {
        printf("%d",next[i]);
    }
    printf("\n");
}

int StrLength(String S) {
    return S[0];
}

int Index_BF(String S,String T,int pos) {
    int i=pos;
    int j=1;
    while (i<=S[0]&&j<=T[0]) {
        if (S[i]==T[j]) {
            i++;
            j++;
        }else{
            i=i-j+2;
            j=1;
        }
    }
    if (j>T[0]) {
        return i-T[0];
    }else{
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    int i,*p;
    String s1,s2;
    StrAssign(s1, "abcdex");
    printf("s1子串为");
    StrPrint(s1);
    
    
    StrAssign(s2, "xe");
    printf("s2子串为");
    StrPrint(s2);
    
    i = Index_BF(s1, s2, 1);
    printf("i = %d\n",i);
    return 0;
}
