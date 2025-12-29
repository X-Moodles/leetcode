/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 * @lcpr version=30204
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
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
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, sum = 0;
        for (int i =  0; i < arr.size(); i++) {
            sum += arr[i];//更新右(进)

            if (0 > i - k + 1) {
                continue;
            }
            if (sum >= k  * threshold) {
                ans++;
            }
            sum -= arr[i - k + 1];//更新左（出）


        }
        return ans;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,2,2,5,5,5,8]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [11,13,17,23,29,31,7,5,2,3]\n3\n5\n
// @lcpr case=end

 */

