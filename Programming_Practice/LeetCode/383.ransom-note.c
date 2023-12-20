/*
 * @lc app=leetcode id=383 lang=c
 *
 * [383] Ransom Note
 */

// @lc code=start
bool canConstruct(char* ransomNote, char* magazine) {
    int alpha[26] = {0};                      // set alphabet amount array
    int ransomNote_len = strlen(ransomNote);  // set ransomNote's strlen
    int magazine_len = strlen(magazine);      // set magazine's strlen
    if (ransomNote_len > magazine_len)        // return false if ransomNote's length is longer than magazine's length
        return false;
    for (int i = 0; i < ransomNote_len; i++) {
        alpha[ransomNote[i] - 'a']++;  // plus if ransomNote has the alphabet
    }
    for (int i = 0; i < magazine_len; i++) {
        alpha[magazine[i] - 'a']--;  // minus if magazine has the alphabet
    }
    for (int i = 0; i < 26; i++) {
        if (alpha[i] > 0)  // it will be under or equal 0 if ransomNote can be constructed from magazine
            return false;
    }
    return true;
}
// @lc code=end
