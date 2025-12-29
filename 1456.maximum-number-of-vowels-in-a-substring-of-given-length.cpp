/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 * @lcpr version=30204
 *
 * [1456] 定长子串中元音的最大数目
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
    int maxVowels(string s, int k) {
       //定滑动窗口：对右边界遍历，左边界跟上以维护窗口的长度
       int ans = 0, vowel = 0;
       for (int i = 0; i < s.size(); i++) {//遍历右窗口
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o' || s[i] == 'u') {
                vowel++;
            }
            int left = i - k + 1;
            if (left < 0){
                continue;
            }

            ans = max(ans, vowel);
            //记录最大值
            char out = s[left];
            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i'|| s[left] == 'o' || s[left] == 'u') {
                vowel--;
            }
       }
       return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abciiidef"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aeiou"\n2\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n3\n
// @lcpr case=end

// @lcpr case=start
// "rhythms"\n4\n
// @lcpr case=end

// @lcpr case=start
// "tryhard"\n4\n
// @lcpr case=end

 */

