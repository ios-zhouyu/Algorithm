//
//  main.c
//  04 斐波那契查找
//
//  Created by zhouyu on 2018/12/17.
//  Copyright © 2018 zhouyu. All rights reserved.
/*
 在二分查找的基础上根据斐波那契数列进行分割的
 
 时间复杂度: O(log2n)
 */

#include <stdio.h>

 #define FIB_MAXSIZE 1000

void produceFib(int *fib, int size) {
    int i;
    fib[0] = 1;
    fib[1] = 1;
    for (i = 2; i < size; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int fibonacciSearch(int *data, int length, int searchValue) {
    int low, high, mid, k, i, fib[FIB_MAXSIZE];
    low = 0;
    high = length - 1;
    produceFib(fib, FIB_MAXSIZE);
    k = 0;
    // 找到有序表元素个数在斐波那契数列中最接近的最大数列值
    while (high > fib[k] - 1) {
        k++;
    }
    // 补齐有序表
    for (i = length; i <= fib[k] - 1; i++){
        data[i] = data[high];
    }
    while (low <= high) {
        mid = low + fib[k - 1] - 1;   // 根据斐波那契数列进行黄金分割
        if (data[mid] == searchValue) {
                if (mid <= length - 1) {
                        return mid;
                } else {// 说明查找得到的数据元素是补全值
                        return length - 1;
                }
        }

        if (data[mid] > searchValue) {
                high = mid - 1;
                k = k - 1;
        }
        if (data[mid] < searchValue) {
                low = mid + 1;
                k = k - 2;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int arr[13]={1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 99, 121};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key = 121;
    int result = fibonacciSearch(arr, length, key);
    if (result == -1) {
        printf("can not find this key! \n");
    } else {
        printf("arr[%d] == %d \n", result, key);
    }
    printf("\n");
    return 0;
}
