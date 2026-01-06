/*
 * @lc app=leetcode.cn id=66 lang=cpp
 * @lcpr version=30204
 *
 * [66] 加一
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
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; // 进位
                return digits;
            }
            digits[i] = 0; // 进位数字的右边数字都变成 0
        }

        // digits 全是 9，加一后变成 100...00
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};


// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [9]\n
// @lcpr case=end

 */

