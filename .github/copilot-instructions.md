# AI Copilot Instructions for LeetCode C++ Solutions

## Project Overview
This is a **LeetCode problem-solving repository** using C++17, managed by the LCPR (LeetCode Problem Runner) tool. Each file represents one LeetCode problem with local testing capabilities. Problems are sourced from LeetCode CN with multilingual support.

## Build & Execution Workflow
- **Build system:** Custom `launcher.cpp` wrapper that compiles with `g++ -std=c++17 -g` and places binaries in `build/`
- **Quick run:** Use the VS Code task `"LeetCode Local Run"` or execute `run.bat <filename.cpp>`
- **Launcher features:**
  - Auto-detects Windows vs Unix and applies correct executable suffix
  - Automatically creates `build/` directory if missing
  - Supports optional `-fsanitize=address` for memory checking (may need removal on some MinGW versions)
  - File extension auto-completion: `launcher 1.two-sum` compiles `1.two-sum.cpp`

## Code Structure & Conventions
All solution files follow a strict structure managed by LCPR:

```
// @lcpr-before-debug-begin
[Debug preamble - minimal, rarely used]

// @lc app=leetcode.cn id=<NUM> lang=cpp
// @lcpr version=30204

// @lcpr-template-start
[Standard headers: vector, unordered_map, unordered_set, queue, stack, etc.]

// @lc code=start
class Solution { /* Actual solution logic */ }
// @lc code=end

int main() { /* Local test cases */ }

// @lcpr case=start
// [Input]\n
// @lcpr case=end
```

**Critical rules:**
- Never remove or modify `@lc`, `@lcpr`, or `@lcpr-template-start/end` markers—they're tool-managed
- Place all solution logic between `// @lc code=start` and `// @lc code=end`
- Use provided standard library headers; add new ones within the template section if needed
- Test locally in `main()` before submission

## Common Patterns & Approaches
- **Hash-based solutions:** Frequent use of `unordered_map<T, int>` for O(1) lookups (e.g., two-sum, complement finding)
- **Data structure selection:** Stacks for parentheses/expressions, queues for BFS/level-order traversal, priority queues for heaps
- **Comments:** Often include commented-out O(n²) approaches alongside optimized O(n) solutions for reference
- **Linked list traversal:** Use three-pointer technique (pre, cur, next) for reversals and manipulations
- **Algorithm mix:** Combines graph (DFS/BFS), dynamic programming, greedy, and search algorithms

## Development Hints
- **Testing multilingual problems:** Files may have Chinese characters (e.g., `209.长度最小的子数组.cpp`)—UTF-8 support required
- **Memory testing:** Consider compiling with `-fsanitize=address` to catch buffer overflows in array/pointer problems
- **Template includes:** All common STL containers available; no external libraries needed
- **Problem metadata:** Ignore `@lc` comments unless checking problem number—LCPR handles these automatically

## File Organization
- **Naming:** `<id>.<slug>.cpp` (e.g., `1.two-sum.cpp`, `206.reverse-linked-list.cpp`)
- **Metadata:** `.lcpr_data/` contains spaced-repetition tracking (`bricks.json`) and problem grouping—avoid manual edits
- **Binaries:** Compiled executables stored in `build/` (e.g., `build/1.two-sum.exe`)
