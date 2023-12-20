/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 */

// @lc code=start
int missingNumber(int* nums, int numsSize) {
    /*
    int flag = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        flag = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i;
        }
    }
    return i;
    */
    int sum = 0;
    for (int i = 1; i <= numsSize; i++) {
        sum += i - nums[i - 1];
    }
    return sum;
}
// @lc code=end