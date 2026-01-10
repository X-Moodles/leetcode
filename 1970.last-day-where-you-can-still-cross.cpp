/*
 * @lc app=leetcode.cn id=1970 lang=cpp
 * @lcpr version=30204
 *
 * [1970] 你能穿过矩阵的最后一天
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
    static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 左右上下

public:
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        // 0：水
        // 1：陆地（未被感染）
        // 2：陆地（已被感染）
        vector state(m, vector<int8_t>(n));

        auto can_reach_from_top = [&](int r, int c) -> bool {
            if (r == 0) { // 已经是第一行
                return true;
            }
            for (auto& d : DIRS) {
                int x = r + d[0], y = c + d[1];
                if (0 <= x && x < m && 0 <= y && y < n && state[x][y] == 2) {
                    return true;
                }
            }
            return false;
        };

        auto dfs = [&](this auto&& dfs, int r, int c) -> bool {
            if (r == m - 1) {
                return true;
            }
            state[r][c] = 2; // 感染
            for (auto& d : DIRS) {
                int x = r + d[0], y = c + d[1];
                // 传播病毒到未被感染的陆地
                if (0 <= x && x < m && 0 <= y && y < n && state[x][y] == 1 && dfs(x, y)) {
                    return true;
                }
            }
            return false;
        };

        for (int day = cells.size() - 1; ; day--) {
            auto& cell = cells[day];
            int r = cell[0] - 1; // 改成从 0 开始的下标
            int c = cell[1] - 1;
            state[r][c] = 1; // 未被感染的陆地
            if (can_reach_from_top(r, c) && dfs(r, c)) {
                return day;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n2\n[[1,1],[2,1],[1,2],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n[[1,1],[1,2],[2,1],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n[[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]\n
// @lcpr case=end

 */