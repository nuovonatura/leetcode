/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0, index = 0, start = 0, length = 0;
        unordered_map<char, int> pos = unordered_map<char, int>();
        for (char c : s) {
            if (pos.find(c) != pos.end() && pos[c] >= start) {
                length = index - start;
                count = count > length ? count : length;
                start = pos[c] + 1;
            }
            pos[c] = index;
            index++;
        }
        length = index - start;
        count = count > length ? count : length;
        return count;
    }
};
// @lc code=end

