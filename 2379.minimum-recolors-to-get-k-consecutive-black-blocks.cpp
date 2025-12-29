/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 * @lcpr version=30204
 *
 * [2379] 得到 K 个黑块的最少涂色次数
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
    int minimumRecolors(string blocks, int k) {
       int ans = INT_MAX;
       int cnt = 0;
        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                cnt++;
            }//enter
            if (0 > i - k + 1) {
                continue;
            }
            ans = min(ans, cnt);//update
            if (blocks[i - k + 1] == 'W') {
                cnt--;
            }//output


        }
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "WBBWWBBWBW"\n7\n
// @lcpr case=end

// @lcpr case=start
// "WBWBBBW"\n2\n
// @lcpr case=end

 */

