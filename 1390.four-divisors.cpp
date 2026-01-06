// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1390 lang=cpp
 * @lcpr version=30204
 *
 * [1390] 四因数
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
    int sumFourDivisors(vector<int>& nums) {
        long long totalSum = 0; // 这里的总和可能溢出 int，用 long long 保险，虽题目返回 int

        for (int num : nums) {
            int count = 0;      // 记录当前数字的因数个数
            int currentSum = 0; // 记录当前数字的因数之和

            // 只需要遍历到 sqrt(num)
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) { // 找到一个因数 i
                    count++;
                    currentSum += i;
                    
                    // 找到另一个对应的因数 num/i
                    // 只有当 i 不等于 num/i 时才加（避免完全平方数重复计算，例如 4=2*2）
                    if (i * i != num) {
                        count++;
                        currentSum += num / i;
                    }
                }
                
                // 剪枝：如果因数已经超过 4 个，就没必要继续算了，直接退出内层循环
                if (count > 4) break; 
            }

            // 如果因数个数恰好是 4，加入总结果
            if (count == 4) {
                totalSum += currentSum;
            }
        }
        
        return totalSum;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=sumFourDivisors
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [21,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [21,21]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

