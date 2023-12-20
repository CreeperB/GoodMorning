/*
 * @lc app=leetcode id=70 lang=c
 *
 * [70] Climbing Stairs
 */

// @lc code=start
int climbStairs(int n){
    int f[50] = {1, 1};
    for(int i = 2; i <= n; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
// @lc code=end

// 1
// 1

// 2
// 1 1
// 2

// 3
// 1 1 1
// 2 1
// 1 2

// 4

// 1 1 1 1
// 2 1 1
// 1 2 1
// 1 1 2
// 2 2

// 5
// 1 1 1 1 1
// 2 1 1 1
// 1 2 1 1
// 1 1 2 1
// 1 1 1 2
// 2 2 1
// 2 1 2
// 1 2 2
