/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 * @lcpr version=30204
 *
 * [1423] 可获得的最大点数
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
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;//本题目可以逆向理解为：求n-k窗口和的最小值，以为n固定，当这个窗口的和最小，则k数目的和最大
        int sum = reduce(cardPoints.begin(), cardPoints.begin() + m);//计算下标0到m-1的和并且初始化为minSum，后续将以右边界从下标m开始到n-1结束长度为m的滑动窗口更新最值
        int minSum = sum;
        int oSum = reduce(cardPoints.begin(), cardPoints.end());
        if (m == 0) return oSum;//特例：当n == k时，直接返回所有的和
        for (int i = m; i < n; i++) {
            sum += cardPoints[i] - cardPoints[i-m];//i(右边界)从下标m到n-1,i-m(左边界)同样移动m到n-1个单位
            minSum = min(minSum, sum);
        }
        return oSum - minSum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [9,7,7,9,7,7,9]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,1000,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,79,80,1,1,1,200,1]\n3\n
// @lcpr case=end

 */

