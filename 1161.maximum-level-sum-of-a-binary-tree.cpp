/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 * @lcpr version=30204
 *
 * [1161] 最大层内元素和
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
//DPS做法
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> row_sum;

        auto dfs = [&](this auto&& dfs, TreeNode* node, int level) -> void {
            if (node == nullptr) {
                return;
            }

            if (row_sum.size() == level) { // 首次访问 level 层
                row_sum.push_back(node->val); // 节点值作为层和的初始值
            } else {
                row_sum[level] += node->val;
            }

            dfs(node->left, level + 1);
            dfs(node->right, level + 1);
        };

        dfs(root, 0);
        return ranges::max_element(row_sum) - row_sum.begin() + 1; // 层号从 1 开始
    }
};

// @lc code=end



/*
// @lcpr case=start
// [1,7,0,7,-8,null,null]\n
// @lcpr case=end

// @lcpr case=start
// [989,null,10250,98693,-89388,null,null,null,-32127]\n
// @lcpr case=end

 */

