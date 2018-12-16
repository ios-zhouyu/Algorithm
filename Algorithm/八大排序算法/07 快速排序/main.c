//
//  main.c
//  07 快速排序
//
//  Created by zhouyu on 2018/12/14.
//  Copyright © 2018 zhouyu. All rights reserved.
/*
 冒泡排序的改进
 基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
 */

#include <stdio.h>

void swap(int arr[], int left, int right) {
    int temp;
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

int partition(int arr[],int left,int right){
    int point = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= point) {
            right--;
        }
        swap(arr, left, right);
        while (left < right && arr[left] <= point) {
            left++;
        }
        swap(arr, left, right);
    }
    return point;
}

void quicklySort(int *arr, int left, int right){
    int basePosition = 0;//找到基准划分位置
    if (left < right) {
        basePosition = partition(arr, left, right);
        quicklySort(arr, left, basePosition - 1);
        quicklySort(arr, basePosition + 1, right);
    }
}

int main(int argc, const char * argv[]) {
    int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int length = sizeof(nums) / sizeof(nums[0]);
    quicklySort(nums, 0, length - 1);
    
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    return 0;
}
