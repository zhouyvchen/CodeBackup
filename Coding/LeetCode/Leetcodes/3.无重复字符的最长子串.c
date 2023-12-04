/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
int lengthOfLongestSubstring(char* s) {
    // 使用滑动窗口的思想
    int i = 0;
    int maxLength = 0;
    int start = 0;
    int charMap[128] = {0};
    while (s[i] != '\0') {
        // charMap[s[i]] 表示字符 s[i]
        // 在之前出现的位置（如果之前没有出现过，则为0）。start
        // 表示当前窗口的起始位置。
        if (charMap[s[i]] > start) {  // 判断s[i]是否在charMap里出现过
            start = charMap[s[i]];    // 确定窗口开始的位置
            printf("charMap = %c, start = %d", charMap[s[i]], start);
        }
        charMap[s[i]] = i + 1;
        int currentLength = i - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
        i++;
    }
    return maxLength;
}
// @lc code=end