//
//  main.c
//  01 顺序查找
//
//  Created by zhouyu on 2018/12/16.
//  Copyright © 2018 zhouyu. All rights reserved.
//

#include <stdio.h>

int orderSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return arr[i];
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int length = sizeof(nums) / sizeof(nums[0]);
    int result = orderSearch(nums, length, 5);
    printf("%d  \n", result);
    return 0;
}
