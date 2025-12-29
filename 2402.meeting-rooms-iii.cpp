/*
 * @lc app=leetcode.cn id=2402 lang=cpp
 * @lcpr version=30204
 *
 * [2402] 会议室 III
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
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ranges::sort(meetings, {}, [](auto& m) { return m[0]; });

        priority_queue<int, vector<int>, greater<>> idle; // 会议室编号
        for (int i = 0; i < n; i++) {
            idle.push(i);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> using_; // (结束时间，会议室编号)
        vector<int> cnt(n); // 会议室的开会次数

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];

            // 在 start 时刻空出来的会议室
            while (!using_.empty() && using_.top().first <= start) {
                idle.push(using_.top().second);
                using_.pop();
            }

            int i;
            if (!idle.empty()) { // 有空闲的会议室
                i = idle.top();
                idle.pop();
            } else { // 没有空闲的会议室
                // 弹出一个最早结束的会议室（若有多个同时结束，弹出编号最小的会议室）
                auto [e, room] = using_.top();
                i = room;
                using_.pop(); 
                end += e - start; // 更新当前会议的结束时间
            }

            using_.emplace(end, i); // 使用一个会议室
            cnt[i]++;
        }

        return ranges::max_element(cnt) - cnt.begin();
    }
};


// @lc code=end



/*
// @lcpr case=start
// 2\n[[0,10],[1,5],[2,7],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,20],[2,10],[3,5],[4,9],[6,8]]\n
// @lcpr case=end

 */

