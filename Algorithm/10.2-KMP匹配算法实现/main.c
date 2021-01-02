//
//  main.c
//  10.2-KMP匹配算法实现
//
//  Created by 石玉龙 on 2021/1/2.
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
#define MAXSIZE 100

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
int StrLength(String S) {
    return S[0];
}
void get_next(String T,int *next) {
    int i,j;
    j=1;
    i=0;
    next[1]=0;
    while (j<T[0]) {
        if (i==0||T[i]==T[j]) {
            ++i;
            ++j;
            next[j]=i;
        }else{
            i=next[i];
        }
    }
}
void NextPrint(int next[],int length) {
    int i;
    for (i=1; i<=length; i++) {
        printf("%d",next[i]);
    }
    printf("\n");
}
int count=0;
int Index_KMP(String S,String T,int pos) {
    int i=pos;
    int j=1;
    int next[MAXSIZE];
    get_next(T, next);
    count=0;
    while (i<=S[0]&&j<=T[0]) {
        if (j==0||S[i]==T[j]) {
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if (j>T[0]) {
        return i-T[0];
    }else{
        return -1;
    }
}
void get_nextVal(String T,int *nextVal) {
    int i,j;
    j=1;
    i=0;
    nextVal[1]=0;
    while (j<T[0]) {
        if (i==0||T[i]==T[j]) {
            ++j;
            ++i;
            if (T[i]!=T[j]) {
                nextVal[j]=1;
            }else{
                nextVal[j]=nextVal[i];
            }
        }else{
            i=nextVal[i];
        }
    }
}
int Index_KMP2(String S,String T,int pos) {
    int i=pos;
    int j=1;
    int next[MAXSIZE];
    get_nextVal(T, next);
    count=0;
    while (i<=S[0]&&j<=T[0]) {
        if (j==0||S[i]==T[j]) {
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if (j>T[0]) {
        return i-T[0];
    }else{
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    int i,*p,*t;
    String s1,s2;
    int Status;
    StrAssign(s1,"aaaaax");
    printf("子串为: ");
    StrPrint(s1);
    i=StrLength(s1);
    p=(int*)malloc((i+1)*sizeof(int));
    get_next(s1,p);
    printf("Next为: ");
    NextPrint(p,StrLength(s1));
    t=(int*)malloc((i+1)*sizeof(int));
    get_nextVal(s1, t);
    printf("NextVal为: ");
    NextPrint(t,StrLength(s1));
    printf("\n");
    
    StrAssign(s1,"abcababca");
    printf("主串为: ");
    StrPrint(s1);
    StrAssign(s2,"abcdex");
    printf("子串为: ");
    StrPrint(s2);
    Status = Index_KMP(s1,s2,1);
    printf("主串和子串在第%d个字符处首次匹配（KMP算法）[返回位置为负数表示没有匹配] \n",Status);
    Status = Index_KMP2(s1, s2, 1);
    printf("主串和子串在第%d个字符处首次匹配（KMP_2算法）[返回位置为负数表示没有匹配] \n\n",Status);
    
    StrAssign(s1,"abccabcceabc");
    printf("主串为: ");
    StrPrint(s1);
    StrAssign(s2,"abcce");
    printf("子串为: ");
    StrPrint(s2);
    Status = Index_KMP(s1,s2,1);
    printf("主串和子串在第%d个字符处首次匹配（KMP算法）[返回位置为负数表示没有匹配] \n",Status);
    Status = Index_KMP2(s1, s2, 1);
    printf("主串和子串在第%d个字符处首次匹配（KMP_2算法）[返回位置为负数表示没有匹配] \n\n",Status);
    
    StrAssign(s1,"aaaabcde");
    printf("主串为: ");
    StrPrint(s1);
    StrAssign(s2,"aaaaax");
    printf("子串为: ");
    StrPrint(s2);
    Status = Index_KMP(s1,s2,1);
    printf("主串和子串在第%d个字符处首次匹配（KMP算法）[返回位置为负数表示没有匹配] \n",Status);
    Status = Index_KMP2(s1, s2, 1);
    printf("主串和子串在第%d个字符处首次匹配（KMP_2算法）[返回位置为负数表示没有匹配] \n\n",Status);
    return 0;
}
