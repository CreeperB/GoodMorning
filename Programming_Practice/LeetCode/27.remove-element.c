/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start

#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val){
    int size = numsSize;
    for (int i = 0; i < size; i++) {
        if (val == nums[i])  //判定相同值
        {
            size--;
            for (int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j + 1];  //以相同欄起將該陣列向左搬移
            }
            if (val == nums[i] && i != numsSize - 1) {
                i -= 1;  //左移後仍相同則重複該迴圈(不要讓i增加)
            }
        }
    }
    return size;
}

// @lc code=end