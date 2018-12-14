//
//  main.c
//  02 选择排序
//
//  Created by zhouyu on 2018/12/14.
//  Copyright © 2018 zhouyu. All rights reserved.
/*
 选择排序的基本思想：
 每一趟在n-i+1（i=1,2,3…,n-1）个记录中选取关键字最小的记录与第i个记录交换，并作为有序序列中的第i个记录。
 
 例如：
 待排序列： 43，65，4，23，6，98，2，65，7，79
 第一趟： 2，65，4，23，6，98，43，65，7，79
 第二趟： 2，4，65，23，6，98，43，65，7，79
 第三趟： 2，4，6，23，65，98，43，65，7，79
 第四趟： 2，4，6，7，43，65，98，65，23，79
 第五趟： 2，4，6，7，23，65，98，65，43，79
 第六趟： 2，4，6，7，23，43，98，65，65，79
 第七趟： 2，4，6，7，23，43，65，98，65，79
 第八趟： 2，4，6，7，23，43，65，65，98，79
 第九趟： 2，4，6，7，23，43，65，65，79，98
 
 选择排序的时间复杂度为：O(n^2)，空间复杂度：O(1)
 
 选择排序是不稳定的；每趟确定的是前面的元素,而冒泡每次确定的是后面的元素
 */

#include <stdio.h>

void selectSort(int arr[], int length) {
    int minIndex = 0;
    for (int i = 0; i < length - 1; i++) {
        minIndex = i;
        //1. 对比记录最小元素的下标
        for (int j = i + 1; j < length; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        //2. 将每次比较的最小元素调整到第i次的位置
        if (i != minIndex) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int length = sizeof(nums) / sizeof(nums[0]);
    selectSort(nums, length);
    
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
