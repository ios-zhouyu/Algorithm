//
//  main.c
//  04 希尔排序
//
//  Created by zhouyu on 2018/12/15.
//  Copyright © 2018 zhouyu. All rights reserved.
/*
 插入排序的改进:
 
 
 非稳定排序算法: 
 */

#include <stdio.h>

void hillSort(int arr[], int length) {
    int gap = length;
    
    do {
        gap = gap / 3 + 1;
        for (int i = gap; i < length; i++) {
            if (arr[i] < arr[i - gap]) {
                int temp = arr[i];
                int j;
                for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
                    arr[j + gap] = arr[j];
                }
                arr[j + gap] = temp;
            }
        }
    } while (gap > 1);
}

int main(int argc, const char * argv[]) {
    int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int length = sizeof(nums) / sizeof(nums[0]);
    hillSort(nums, length);
    
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    return 0;
}
