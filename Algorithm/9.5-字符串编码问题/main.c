//
//  main.c
//  9.5-字符串编码问题
//
//  Created by 石玉龙 on 2020/12/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decodeString(char *s) {
    int len=(int)strlen(s);
    int stackSize=50;
    char *stack=(char*)malloc(stackSize*sizeof(char));
    int top=-1;
    for (int i=0; i<len; ++i) {
        if (s[i]!=']') {
            if (top==stackSize-1) {
                stack=realloc(stack, (stackSize+=50)*sizeof(char));
            }
            stack[++top]=s[i];
            printf("#① 没有遇到']'之前# top = %d\n",top);
        }else{
            int tempSize=10;
            char *temp=(char *)malloc(tempSize*sizeof(char));
            int topOfTemp=-1;
            printf("#② 开始获取要复制的字符信息之前 # top = %d\n",top);
            while (stack[top]!='[') {
                if (topOfTemp==tempSize-1) {
                    temp=realloc(temp, (tempSize+=10)*sizeof(char));
                }
                ++topOfTemp;
                temp[topOfTemp]=stack[top];
                top--;
            }
            printf("#② 开始获取要复制的字符信息之后 # top = %d\n",top);
            char strOfInt[11];
            int curTop=top;
            printf("#③ 开始获取数字,数字位置上限 # curTop = %d\n",curTop);
            top--;
            while (top!=-1&&stack[top]>='0'&&stack[top]<='9') {
                top--;
            }
            printf("#③ 开始获取数字,数字位置下限 # top = %d\n",top);
            for (int j=top+1; j<curTop; ++j) {
                strOfInt[j-(top+1)]=stack[j];
            }
            strOfInt[curTop-(top+1)]='\0';
            int curNum=atoi(strOfInt);
            for (int k=0; k<curNum; ++k) {
                int kk=topOfTemp;
                while (kk!=-1) {
                    if (top==stackSize-1) {
                        stack=realloc(stack, (stackSize+=50)*sizeof(char));
                    }
                    ++top;
                    stack[top]=temp[kk];
                    kk--;
                }
            }
            free(temp);
            temp=NULL;
        }
    }
    char *ans=realloc(stack, (top+1)*sizeof(char));
    ans[++top]='\0';
    free(stack);
    return ans;
}

int main(int argc, const char * argv[]) {
    char *s ;
    s = decodeString("12[a]");
    printf("字符编码后的结果: %s\n\n\n\n",s);
    printf("\n");
    return 0;
}
