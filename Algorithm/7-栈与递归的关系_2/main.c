//
//  main.c
//  7-栈与递归的关系_2
//
//  Created by 石玉龙 on 2020/12/31.
//

#include <stdio.h>

int Fbi(int i) {
    if (i<2) {
        return i==0?0:1;
    }
    return Fbi(i-1)+Fbi(i-2);
}

int main(int argc, const char * argv[]) {
    for (int i =0; i < 10; i++) {
         printf("%d  ",Fbi(i));
    }
    printf("\n");
    return 0;
}
