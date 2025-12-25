// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30103
 *
 * [209] 长度最小的子数组
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
    // int k = 0;
    int minSubArrayLen(int target, vector<int> &nums)
    {
        vector<int> len(nums.size(), 10000001);
        // int k = 0;
        for (unsigned i = 0, j = i + 1; i < nums.size();)
        {
            j = i + 1;

            for (; j < nums.size();)
            {
                if (nums[i] >= target)
                {
                    len[i] = j - i + 1;
                    // k = len[i];
                    break;
                }
                else
                {
                    nums[i] = nums[i] + nums[j];
                    j++;
                }
            }
            if (nums[i] < target)
            {
                i++;
                continue;
            }
            len[i] = j - i;
            i++;
        }
        int min = 100000002;
        vector<int> cop(nums.size(), 10000001);
        if (len == cop)
            return 0;
        for (unsigned int i = 0; i < nums.size(); i++)
        {

            if (len[i] < min)
            {
                min = len[i];
            }
        }
        return min;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */
