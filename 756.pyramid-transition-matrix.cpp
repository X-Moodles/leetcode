/*
 * @lc app=leetcode.cn id=756 lang=cpp
 * @lcpr version=30204
 *
 * [756] 金字塔转换矩阵
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
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        string groups[6][6];
        for (auto& s : allowed) {
            groups[s[0] - 'A'][s[1] - 'A'] += s[2];
        }

        int n = bottom.size();
        vector<string> pyramid(n);
        pyramid[n - 1] = move(bottom);

        unordered_set<string> vis;

        auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
            if (i < 0) {
                return true;
            }

            if (vis.contains(pyramid[i])) { // 之前填过一模一样的，这个局部的金字塔无法填完
                return false; // 继续递归也无法填完，直接返回
            }

            if (j == i + 1) {
                vis.insert(pyramid[i]);
                return dfs(i - 1, 0);
            }

            for (char top : groups[pyramid[i + 1][j] - 'A'][pyramid[i + 1][j + 1] - 'A']) {
                pyramid[i] += top;
                if (dfs(i, j + 1)) {
                    return true;
                }
                pyramid[i].pop_back();
            }
            return false;
        };

        return dfs(n - 2, 0);
    }
};


// @lc code=end



/*
// @lcpr case=start
// "BCD"\n["BCC","CDE","CEA","FFF"]\n
// @lcpr case=end

// @lcpr case=start
// "AAAA"\n["AAB","AAC","BCD","BBE","DEF"]\n
// @lcpr case=end

 */

