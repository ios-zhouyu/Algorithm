//
//  main.c
//  01 冒泡排序
//
//  Created by zhouyu on 2018/12/14.
//  Copyright © 2018 zhouyu. All rights reserved.
/*
 冒泡排序算法的原理如下：
 1.  比较相邻的元素。如果第一个比第二个大，就交换他们两个。
 2. 对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
 3. 针对所有的元素重复以上的步骤，除了最后一个。
 4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较
 
 冒泡排序的时间复杂度为：O(n^2)，空间复杂度：O(1)
 
 冒泡排序是稳定的；每趟确定的是后面的元素
 */

#include <stdio.h>

void bubbleSort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {//比较n趟, 每次确定一个元素
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int length = sizeof(nums) / sizeof(nums[0]);
    bubbleSort(nums, length);
    
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
