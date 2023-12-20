/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

// @lc code=start
bool isPalindrome(int x) {
    if(x < 0)
        return false;
    if(x == 0)
        return true;
    long int r = 0;
    int c = x;
    while(c > 0){
        r = r * 10 + c % 10;
        c /= 10;
    }
    return x == r;
}
// @lc code=end

