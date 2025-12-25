// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30103
 *
 * [977] 有序数组的平方
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
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;

        while ( r >= 0)
        {
            if (nums[l] == 0 || abs(nums[l]) > abs(nums[r]))
            {
                int tmp = abs(nums[r]);
                nums[r--] = nums[l] * nums[l];
                nums[l] = tmp;
                // cout << nums[l];

            }
            else if(nums[r] == 0 || abs(nums[l]) <= abs(nums[r]))
            {
                nums[r--] = nums[r] * nums[r];
                // cout << nums[r];
            }
        }
        return nums;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */
