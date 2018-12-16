//
//  main.c
//  05 堆排序
//
//  Created by zhouyu on 2018/12/16.
//  Copyright © 2018 zhouyu. All rights reserved.
/*
 和完全二叉树相关
 堆的概念: 大顶堆和小顶堆
 
                     4
            5                   2
    10           7       1         8
 3     6    9
 
 和希尔排序的时间复杂度一样: O(nlogn)
 */

#include <stdio.h>

void heapAdjust(int arr[], int s, int n) {
    int i, temp;
    temp = arr[s];
    for (i = 2 * s; i <= n; i *= 2) {
        if (i < n && arr[i] < arr[i + 1]) {
            i++;
        }
        if (temp >= arr[i]) {
            break;
        }
        arr[s] = arr[i];
        s = i;
    }
    arr[s] = temp;
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2; i > 0; i--) {
        heapAdjust(arr, i, n);
    }
    for (i = n; i >= 1; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapAdjust(arr, 0, i - 1);
    }
}

int main(int argc, const char * argv[]) {
    
    int nums[11] = {-999, 4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int length = sizeof(nums) / sizeof(nums[0]);
    heapSort(nums, length);
    
    for (int i = 1; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
