//
//  main.c
//  1-时间复杂度计算
//
//  Created by 石玉龙 on 2020/12/30.
//

#include <stdio.h>

//1、常数阶时间复杂度计算 O(1); 1+1+1 = 3 O(1)
void constantOrder(int n) {
    int sum=0;
    sum=(1+n)*n/2;
    printf("%s: %d\n",__func__,sum);
}
//同上; 1+1+1+1+1+1+1 = 7 O(1)
void constantOrder_2(int n) {
    int sum=0;
    sum=(1+n)*n/2;
    sum=(1+n)*n/2;
    sum=(1+n)*n/2;
    printf("%s: %d\n",__func__,sum);
}
//2、线性阶时间复杂度; x = x+1 执行n次 O(n)
void linearOrder(int x, int n) {
    for (int i=0; i<n; i++) {
        x=x+1;
    }
    printf("%s: %d\n", __func__, x);
}
//同上；1+(n+1)+n+1 = 3+2n -> O(n)
void linearOrder_2(int n) {
    int i,sum=0;
    for (i=1; i<=n; i++) {
        sum+=i;
    }
    printf("%s: %d\n", __func__, sum);
}
///3、对数阶; 2的x次方等于n x = log2n  -> O(logn)
void logarithmicOrder(int n) {
    int count=1;
    while (count<n) {
        count*=2;
    }
    printf("%s: %d\n", __func__,count);
}
///4、平方阶; x=x+1 执行n*n次 -> O(n^2)
void squareOrder(int x, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            x+=1;
        }
    }
    printf("%s: %d\n", __func__, x);
}
//同上； n+(n-1)+(n-2)+...+1 = n(n-1)/2 = n^2/2 + n/2 = O(n^2)； sn = n(a1+an)/2
void squareOrder_2(int n) {
    int sum=0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            sum+=j;
        }
    }
}
//同上； 1+(n+1)+n(n+1)+n^2+n^2 = 2+3n^2+2n -> O(n^2)
void squareOrder_3(int n) {
    int i,j,x=0,sum=0;
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            x++;
            sum+=x;
        }
    }
    printf("%s: %d\n",__func__,sum);
}
///5、立方阶;
void cubicOrder(int n) {
    int sum=1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                sum*=2;
            }
        }
    }
    printf("%s: %d\n",__func__,sum);
}
int main(int argc, const char * argv[]) {
    constantOrder(100);
    linearOrder(1,100);
    logarithmicOrder(100);
    squareOrder(1,100);
    cubicOrder(3);
    return 0;
}
