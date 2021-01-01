//
//  main.c
//  9.7-去掉重复字母
//
//  Created by 石玉龙 on 2021/1/1.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *removeDuplicateLetters(char *s) {
    if (s==NULL||strlen(s)==0) {
        return "";
    }
    if (strlen(s)==1) {
        return s;
    }
    char record[26]={0};
    int len=(int)strlen(s);
    char *stack=(char*)malloc(len*2*sizeof(char));
    memset(stack, 0, len*2*sizeof(char));
    int top=-1;
    int i;
    for (i=0; i<len; i++) {
        record[s[i]-'a']++;
    }
    for (i=0; i<len; i++) {
        int isExist=0;
        for (int j=0; j<=top; j++) {
            if (s[i]==stack[j]) {
                isExist=1;
                break;
            }
        }
        if (isExist==1) {
            record[s[i]-'a']--;
        }else{
            while (top>-1&&stack[top]>s[i]&&record[stack[top]-'a']>1) {
                record[stack[top]-'a']--;
                top--;
            }
            top++;
            stack[top]=s[i];
        }
    }
    stack[++top]='\0';
    return stack;
}

int main(int argc, const char * argv[]) {
    char *s ;
    s = removeDuplicateLetters("bcabc");
    printf("%s\n",s);
 
    s = removeDuplicateLetters("zab");
    printf("%s\n",s);

    s = removeDuplicateLetters("cbacdcbc");
    printf("%s\n",s);
    
    printf("\n");
    return 0;
}
