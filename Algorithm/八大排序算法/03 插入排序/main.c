//
//  main.c
//  03 插入排序
//
//  Created by zhouyu on 2018/12/14.
//  Copyright © 2018 zhouyu. All rights reserved.
/*
 插入即表示将一个新的数据插入到一个有序数组中，并继续保持有序。
 
 插入排序的时间复杂度为：O(n^2)，空间复杂度：O(1)
 */

#include <stdio.h>

void insertSort(int arr[], int length) {
    for (int i = 1; i < length; i++) {//循环从第2个元素开始
        if (arr[i] < arr[i - 1]) {//当前元素需要插入排序
            int temp = arr[i];//记录需要插入的值
            int j;
            
            //跳出循环式,就是插入的位置arr[j + 1],需要将插入的值赋值给arr[j + 1]
            for (j = i - 1; j >= 0 && arr[j] > temp; j--) {//利用反向冒泡排序把小的移动到前面
                arr[j + 1] = arr[j];
            }
            //跳出循环时j-1对应的是值arr[j]
            arr[j + 1] = temp;//插入的位置
        }
    }
}

int main(int argc, const char * argv[]) {
    int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int length = sizeof(nums) / sizeof(nums[0]);
    insertSort(nums, length);
    
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    return 0;
}
