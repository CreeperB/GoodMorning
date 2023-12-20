/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 */

// @lc code=start
bool isAnagram(char* s, char* t) {
    int alpha[26] = {0};           // set alphabet amount array
    if (strlen(s) != strlen(t)) {  // return false if it's length isn't the same
        return false;
    }
    int s_len = strlen(s);  // set s's strlen
    for (int i = 0; i < s_len; i++) {
        alpha[s[i] - 'a']++;  // plus if s has the alphabet
        alpha[t[i] - 'a']--;  // minus if t has the alphabet
    }
    for (int i = 0; i < 26; i++)
        if (alpha[i] != 0)  // it will be 0 if t is an anagram of s
            return false;
    return true;
}
// @lc code=end
