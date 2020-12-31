//
//  main.c
//  9.4-爬楼梯
//
//  Created by 石玉龙 on 2020/12/31.
//

#include <stdio.h>
#include <stdlib.h>

int ClimbStairs(int n) {
    if (n<1) {
        return 0;
    }else if (n==1) {
        return 1;
    }else if (n==2) {
        return 2;
    }else{
        return ClimbStairs(n-1)+ClimbStairs(n-2);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
