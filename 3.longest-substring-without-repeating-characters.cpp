/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30204
 *
 * [3] 无重复字符的最长子串
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> cnt;
        int n = s.size(), ans = 0, left = 0;
        for (int right = 0; right < n; right++) {
            char c = s[right];
            cnt[c]++;  // 把新加入的字符更新哈希表
            while (cnt[c] > 1) {
                cnt[s[left++]]--;  // 如果出现过
            }
            ans = max(ans, right - left + 1);
            // 更新窗口最值
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
