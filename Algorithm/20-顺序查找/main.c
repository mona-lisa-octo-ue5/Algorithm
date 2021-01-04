//
//  main.c
//  20-顺序查找
//
//  Created by 石玉龙 on 2021/1/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;

int Sequential_Search(int *a,int n,int key) {
    for (int i=1; i<=n; i++) {
        if (a[i]==key) {
            return i;
        }
    }
    return 0;
}
int Sequential_Search2(int *a,int n,int key){
    int i;
    a[0]=key;
    i=n;
    while (a[i]!=key) {
        i--;
    }
    return i;
}
int Binary_Search(int *a,int n,int key){
    int low,high,mid;
    low=1;
    high=n;
    while (low<=high) {
        mid=(low+high)/2;
        if (key<a[mid]) {
            high=mid-1;
        }else if(key>a[mid]){
            low=mid+1;
        }else{
            return mid;
        }
    }
    return 0;
}
int Interpolation_Search(int *a,int n,int key){
    int low,high,mid;
    low=1;
    high=n;
    while (low<=high) {
        mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);
        if (key<a[mid]) {
            high=mid-1;
        }else if(key>a[mid]){
            low=mid+1;
        }else{
            return mid;
        }
    }
    return 0;
}
int F[100];
int Fibonacci_Search(int *a,int n,int key){
    int low,high,mid,i,k;
    low=1;
    high=n;
    k=0;
    while (n>F[k]-1) {
        k++;
    }
    for (i=n; i<F[k]-1; i++) {
        a[i]=a[n];
    }
    while (low<=high) {
        mid=low+F[k-1]-1;
        if (key<a[mid]) {
            high=mid-1;
            k=k-1;
        }else if(key>a[mid]) {
            low=mid+1;
            k=k-2;
        }else{
            if (mid<=n) {
                return mid;
            }else{
                return n;
            }
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int a[MAXSIZE+1],i,result;
    int arr[MAXSIZE]={0,1,16,24,35,47,59,62,73,88,99};
    for (i=0; i<=MAXSIZE; i++) {
        a[i]=i;
    }
    result=Sequential_Search(a, MAXSIZE, MAXSIZE);
    printf("顺序查找:%d\n",result);
    result=Sequential_Search2(a, MAXSIZE, 1);
    printf("顺序查找_哨兵:%d \n",result);
    result=Binary_Search(arr, 10, 62);
    printf("折半查找:%d \n",result);
    result=Interpolation_Search(arr, 10, 62);
    printf("插值查找:%d \n",result);
    F[0]=0;
    F[1]=1;
    for(i = 2;i < 100;i++)
    {
        F[i] = F[i-1] + F[i-2];
    }
    result=Fibonacci_Search(arr,10,99);
    printf("斐波拉契查找:%d \n",result);
    result=Fibonacci_Search(arr,10,59);
    printf("斐波拉契查找:%d \n",result);
    printf("\n");
    return 0;
}
