// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2483 lang=cpp
 * @lcpr version=30204
 *
 * [2483] 商店的最少代价
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
    int bestClosingTime(string customers) {
       //#滑动窗口 #贪心
       int n = customers.size();
       int cost = 0;
       int ans  = 0;
       for(char ch : customers) {
            if (ch == 'Y') {
                cost++;
            }
       }
       
       int minCost = cost;
       for (int i = 0; i < n; i++){//遍历h
            if (customers[i] == 'N') {
                cost++;
            } else {
                cost--;
            }
            if (cost < minCost) {
                minCost = cost;
                ans = i + 1;
            }
       }
       return ans;
    }
   
};
// @lc code=end



// @lcpr-div-debug-arg-start
// funName=int bestClosingTime(string customers)
// paramTypes=["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "YYNY"\n
// @lcpr case=end

// @lcpr case=start
// "NNNNN"\n
// @lcpr case=end

// @lcpr case=start
// "YYYY"\n
// @lcpr case=end

 */

