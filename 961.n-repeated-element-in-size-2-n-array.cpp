/*
 * @lc app=leetcode.cn id=961 lang=cpp
 * @lcpr version=30204
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
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
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (!seen.insert(x).second) { // x 在 seen 中
                return x;
            }
        }
        return -1; // 代码不会执行到这里
    }
};

// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,2,5,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,5,2,5,3,5,4]\n
// @lcpr case=end

 */

