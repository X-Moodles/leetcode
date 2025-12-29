// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 * @lcpr version=30204
 *
 * [2090] 半径为 k 的子数组平均值
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
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n, -1);
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (0 > i - 2 * k){
                continue;
            }
            avgs[i - k] = sum / (1 + 2 * k);
            sum -= nums[i - 2 * k];

        }    
        return avgs;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=getAverages
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [7,4,3,9,1,8,5,2,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [100000]\n0\n
// @lcpr case=end

// @lcpr case=start
// [8]\n100000\n
// @lcpr case=end

 */

