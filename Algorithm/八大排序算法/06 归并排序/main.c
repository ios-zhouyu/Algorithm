//
//  main.c
//  06 归并排序
//
//  Created by zhouyu on 2018/12/16.
//  Copyright © 2018 zhouyu. All rights reserved.
/* 
 2路归并排序
 递归思路
 */

#include <stdio.h>

void mergeSort(int arr[], int n) {
    
    if (n <= 1) {//终止条件
        return;
    }
    int *listLeft = arr;
    int listLeftSize = n / 2;
    int *listRight = arr + n / 2;
    int listRightSize = n - listLeftSize;
    
    //递归
    mergeSort(listLeft, listLeftSize);
    mergeSort(listRight, listRightSize);
    
    //合并
    int i, j, k;
    i = j = k = 0;
    int temp[n];
    while (i < listLeftSize && j < listRightSize) {
        if (listLeft[i] < listRight[j]) {
            temp[k++] = listLeft[i++];
        } else {
            temp[k++] = listRight[j++];
        }
    }
    //最后的数据
    while (i < listLeftSize) {
        temp[k++] = listLeft[i++];
    }
    while (j < listRightSize) {
        temp[k++] = listRight[j++];
    }
    
    //排序好的数据赋值给原数组
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main(int argc, const char * argv[]) {
    int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int length = sizeof(nums) / sizeof(nums[0]);
    mergeSort(nums, length);
    
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    return 0;
}
