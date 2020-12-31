//
//  main.c
//  9-栈与队列算法题集训-括号匹配检验
//
//  Created by 石玉龙 on 2020/12/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Stack_Init_Size 100
#define Stack_Increment 10

typedef struct {
    char *base;
    char *top;
    int stacksize;
}SqStack;

int Init(SqStack *stack) {
    stack->base=(char*)malloc(Stack_Init_Size*sizeof(char));
    stack->top=stack->base;
    if (stack->top) {
        return -1;
    }
    stack->stacksize=Stack_Init_Size;
    printf("初始化成功\n");
    return 0;
}
char GetTop(SqStack stack) {
    if (stack.base==stack.top) {
        printf("栈中没有数据\n");
        return '#';
    }
    return *(stack.top-1);
}
int Push(SqStack *stack,char element) {
    if (stack->top-stack->base==stack->stacksize) {
        stack->base=(char*)realloc(stack->base, Stack_Increment*sizeof(char));
        stack->top=stack->base+stack->stacksize;
        stack->stacksize+=Stack_Increment;
    }
    *stack->top=element;
    stack->top+=1;
    return 0;
}
char Pop(SqStack *stack) {
    if (stack->top==stack->base) {
        printf("栈为空\n");
        return '#';
    }
    return *--stack->top;
}
int Destroy(SqStack *stack) {
    free(stack->base);
    stack->stacksize=0;
    return 0;
}
int ExecuteData(SqStack stack,char *data) {
    Push(&stack, data[0]);
    for (int i=1; i<strlen(data); i++) {
        char top=GetTop(stack);
        switch (top) {
            case '(':
                if (data[i]==')') {
                    Pop(&stack);
                }else{
                    Push(&stack, data[i]);
                }
                break;
            case '[':
                if (data[i]==']') {
                    Pop(&stack);
                }else{
                    Push(&stack, data[i]);
                }
                break;
            case '#':
                if (data[i]=='('||data[i]=='[') {
                    Push(&stack, data[i]);
                }else{
                    return -1;
                }
                break;
            default:
                return -1;
                break;
        }
    }
    if (stack.top==stack.base) {
        Destroy(&stack);
        return 0;
    }else{
        Destroy(&stack);
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    SqStack stack;
    Init(&stack);
    char data[180];
    printf("请输入待匹配的字符串\n");
    scanf("%s",data);
    int result = ExecuteData(stack,data);
    if(result==0)printf("括号是正确匹配的\n");
    else printf("括号匹配不正确\n");
    return 0;
}
