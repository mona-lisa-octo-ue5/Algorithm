//
//  main.c
//  10.1-字符串匹配算法RK算法
//
//  Created by 石玉龙 on 2021/1/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define d 26

int isMatch(char *S,int i,char *P,int m) {
    int is,ip;
    for (is=i,ip=0; is!=m&&ip!=m; is++,ip++) {
        if (S[is]!=P[ip]) {
            return 0;
        }
    }
    return 1;
}

int getMaxValue(int m) {
    int h=1;
    for (int i=0; i<m-1; i++) {
        h=(h*d);
    }
    return h;
}

int RK(char *S,char *P) {
    int m=(int)strlen(P);
    int n=(int)strlen(S);
    printf("主串长度为:%d,子串长度为:%d\n",n,m);
    unsigned int A=0;
    unsigned int St=0;
    for (int i=0; i!=m; i++) {
        A=(d*A+(P[i]-'a'));
        St=(d*St+(S[i]-'a'));
    }
    int hValue=getMaxValue(m);
    for (int i=0; i<=n-m; i++) {
        if (A==St) {
            if (isMatch(S, i, P, m)) {
                return i+1;
            }
        }
        St=((St-hValue*(S[i]-'a'))*d+(S[i+m]-'a'));
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    char *buf="abcababcabx";
    char *ptrn="abcabx";
    printf("主串为%s\n",buf);
    printf("子串为%s\n",ptrn);
    
    int index = RK(buf, ptrn);
    printf("find index : %d\n",index);
    return 0;
}
