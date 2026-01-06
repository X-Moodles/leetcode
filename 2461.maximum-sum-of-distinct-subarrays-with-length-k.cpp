// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 * @lcpr version=30204
 *
 * [2461] 长度为 K 子数组中的最大和
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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, maxSum = 0;
        unordered_map<int, int> cnt;
        for (int j = 0; j < nums.size(); j++) {
            //in
            sum += nums[j];
            cnt[nums[j]]++;
            int i = j - k + 1;
            if (i < 0) {
                continue;
            }
            //update
            if (cnt.size() == k) {//the only diff from 2841.
                maxSum = max(maxSum, sum);
            }
            //out
            sum -= nums[i];
            if (--cnt[nums[i]] == 0) {
                cnt.erase(nums[i]);
            }
        }
        return maxSum;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumSubarraySum
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,5,4,2,9,9,9]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,4,4]\n3\n
// @lcpr case=end

 */

