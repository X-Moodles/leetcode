/*
 * @lc app=leetcode.cn id=643 lang=cpp
 * @lcpr version=30204
 *
 * [643] 子数组最大平均数 I
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
    double findMaxAverage(vector<int>& nums, int k) {
        int max_s = INT_MIN;
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];

            if (0 > i - k + 1) {
                continue;
            }
            max_s = max(max_s, s);

            s -= nums[i - k + 1];

        }
        return (double) max_s / k;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,12,-5,-6,50,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n
// @lcpr case=end

 */

