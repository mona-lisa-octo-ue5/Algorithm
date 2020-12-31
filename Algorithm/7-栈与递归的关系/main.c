//
//  main.c
//  7-栈与递归的关系
//
//  Created by 石玉龙 on 2020/12/31.
//

#include <stdio.h>

int m=0;
void moves(char X,int n,int Y) {
    m++;
    printf("%d: from %c ——> %c \n",n,X,Y);
}
void Hanoi(int n,char A,char B,char C) {
    if (n==1) {
        moves(A, 1, C);
    }else {
        Hanoi(n-1, A, C, B);
        moves(A, n, C);
        Hanoi(n-1, B, A, C);
    }
}

int main(int argc, const char * argv[]) {
    Hanoi(3, 'A', 'B', 'C');
    printf("盘子数量为3:一共实现搬到次数:%d\n",m);
    
  
    Hanoi(4, 'A', 'B', 'C');
    printf("盘子数量为3:一共实现搬到次数:%d\n",m);
    return 0;
}
