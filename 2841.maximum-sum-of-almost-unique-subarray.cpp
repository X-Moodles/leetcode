/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 * @lcpr version=30204
 *
 * [2841] 几乎唯一子数组的最大和
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
    long long maxSum(vector<int>& nums, int m, int k) {
       long long sum = 0, maxSum = 0;
       unordered_map<int, int> cnt;
       for (int j = 0; j < nums.size();j++) {
        //in 
        sum += nums[j];
        cnt[nums[j]]++;
        int i = j - k + 1;
        if (i < 0) {
            continue;
        }
        //update logic
        if (cnt.size() >= m) {
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



/*
// @lcpr case=start
// [2,6,7,3,1,7]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [5,9,9,2,4,5,4]\n1\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,1]\n3\n3\n
// @lcpr case=end

 */

