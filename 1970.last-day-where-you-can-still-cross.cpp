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
#include <cstdint>
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
    static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool can_reach_from_top(int r, int c, int m, int n, const vector<vector<int8_t>> &state)
    {
        if (r == 0)
            return true;
        for (auto &d : DIRS)
        {
            int x = r + d[0], y = c + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && state[x][y] == 2)
            {
                return true;
            }
        }
        return false;
    }

    bool dfs(int r, int c, int m, int n, vector<vector<int8_t>> &state)
    {
        if (r == m - 1)
            return true;
        state[r][c] = 2; // 标记为已感染且连通顶端
        for (auto &d : DIRS)
        {
            int x = r + d[0], y = c + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && state[x][y] == 1)
            {
                if (dfs(x, y, m, n, state))
                    return true;
            }
        }
        return false;
    }

public:
    int latestDayToCross(int m, int n, vector<vector<int>> &cells)
    {
        // 0：水，1：陆地，2：连通顶端的陆地
        vector<vector<int8_t>> state(m, vector<int8_t>(n, 0));

        for (int day = cells.size() - 1; day >= 0; day--)
        {
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            state[r][c] = 1; // 变成陆地

            if (can_reach_from_top(r, c, m, n, state))
            {
                if (dfs(r, c, m, n, state))
                    return day;
            }
        }
        return 0;
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

int main() {
    Solution sol;
    
    // Case 1
    int m1 = 2, n1 = 2;
    vector<vector<int>> cells1 = {{1,1},{2,1},{1,2},{2,2}};
    cout << "Case 1: " << sol.latestDayToCross(m1, n1, cells1) << endl;

    // Case 2
    int m2 = 2, n2 = 2;
    vector<vector<int>> cells2 = {{1,1},{1,2},{2,1},{2,2}};
    cout << "Case 2: " << sol.latestDayToCross(m2, n2, cells2) << endl;

    // Case 3
    int m3 = 3, n3 = 3;
    vector<vector<int>> cells3 = {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};
    cout << "Case 3: " << sol.latestDayToCross(m3, n3, cells3) << endl;

    return 0;
}
