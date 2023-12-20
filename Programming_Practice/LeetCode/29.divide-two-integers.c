/*
 * @lc app=leetcode id=29 lang=c
 *
 * [29] Divide Two Integers
 */

// @lc code=start

#include <limits.h>
int divide(long long int dividend, long long int divisor) {
    if (dividend / divisor > INT_MAX)
        return INT_MAX;
    else if (dividend / divisor < INT_MIN)
        return INT_MIN;
    else
        return dividend / divisor;
}

// @lc code=end