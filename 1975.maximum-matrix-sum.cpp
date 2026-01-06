// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1975 lang=cpp
 * @lcpr version=30204
 *
 * [1975] 最大方阵和
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
    long long maxMatrixSum(vector<vector<int>>& matrix) {
       long long total = 0;
       int negCnt = 0;
       int mn = INT_MAX;
       for (auto& row : matrix) {
        for (int x : row) {
            if (x < 0) {
                x = -x;//把所有负数转化为整数
                negCnt++;//记录负数的个数
            }
            mn = min(mn, x);//维护绝对值最小的正数
            total += x;
        }
       } 
       if (negCnt % 2) {
        total -= 2 * mn;//如果是奇数个负数，其和等于原来的和减去两倍的绝对值最小值
       }
       return total;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxMatrixSum
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,-1],[-1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[-1,-2,-3],[1,2,3]]\n
// @lcpr case=end

 */

