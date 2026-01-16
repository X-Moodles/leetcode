/*
 * @lc app=leetcode.cn id=1339 lang=cpp
 * @lcpr version=30204
 *
 * [1339] 分裂二叉树的最大乘积
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxProduct(TreeNode* root) {
        auto dfs1 = [&](this auto&& dfs1, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            return node->val + dfs1(node->left) + dfs1(node->right);
        };
        long long total = dfs1(root);

        long long ans = 0;
        auto dfs2 = [&](this auto&& dfs2, TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }
            int s = node->val + dfs2(node->left) + dfs2(node->right);
            ans = max(ans, s * (total - s));
            return s;
        };
        dfs2(root);

        return ans % 1'000'000'007;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,null,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,9,10,7,8,6,5,4,11,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

