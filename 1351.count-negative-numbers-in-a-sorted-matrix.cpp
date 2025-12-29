/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 * @lcpr version=30204
 *
 * [1351] 统计有序矩阵中的负数
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
    int countNegatives(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        int j  = n - 1, i = 0, ans = 0;//从右上角开始
        while (j >= 0 && i < m) {
            if (grid[i][j] < 0) {
                ans += m - i;//这一列都是负数，记录下来
                j--;
            } else {
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2],[1,0]]\n
// @lcpr case=end

 */

