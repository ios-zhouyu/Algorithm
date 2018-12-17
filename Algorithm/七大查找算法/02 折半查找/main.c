//
//  main.c
//  02 折半查找
//
//  Created by zhouyu on 2018/12/17.
//  Copyright © 2018 zhouyu. All rights reserved.
/*
 要求是有序元素
 */

#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    int mid = 0;
    
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        } else {
            if (arr[mid] < key) {//在右半段
                left = mid + 1;
            } else {//在左半段
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int arr[11]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key = 1;
    int result = binarySearch(arr, length, key);
    if (result == -1) {
        printf("can not find this key! \n");
    } else {
        printf("arr[%d] == %d \n", result, key);
    }
    printf("\n");
    return 0;
}
