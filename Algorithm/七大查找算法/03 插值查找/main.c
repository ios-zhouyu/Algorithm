//
//  main.c
//  03 插值查找
//
//  Created by zhouyu on 2018/12/17.
//  Copyright © 2018 zhouyu. All rights reserved.
/*
 对折半查找的修改
 
 时间复杂度: O(log2n)
 */

#include <stdio.h>

int insertSearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    int mid = 0;
    
    //(key- arr[left]) / (arr[right] - arr[left] ) 按照比例每次最接近的位置
    while (left <= right) {
        mid = left + (key- arr[left]) / (arr[right] - arr[left] ) * (right - left);
        if (arr[mid] == key) {
            return mid;
        } else {
            if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int arr[11]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key = 8;
    int result = insertSearch(arr, length, key);
    if (result == -1) {
        printf("can not find this key! \n");
    } else {
        printf("arr[%d] == %d \n", result, key);
    }
    printf("\n");
    return 0;
}
