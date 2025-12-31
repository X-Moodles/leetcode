/*
 * @lc app=leetcode.cn id=840 lang=cpp
 * @lcpr version=30204
 *
 * [840] 矩阵中的幻方
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
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (grid[i + 1][j + 1] != 5) {
                    continue;
                }

                int mask = 0;
                int r_sum[3]{};
                int c_sum[3]{};
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        int x = grid[i + r][j + c];
                        mask |= 1 << x;
                        r_sum[r] += x;
                        c_sum[c] += x;
                    }
                }

                if (mask == (1 << 10) - 2 &&
                    r_sum[0] == 15 && r_sum[1] == 15 &&
                    c_sum[0] == 15 && c_sum[1] == 15) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [[4,3,8,4],[9,5,1,9],[2,7,6,2]\n
// @lcpr case=end

// @lcpr case=start
// [[8]]\n
// @lcpr case=end

 */

