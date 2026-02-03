# AGENTS.md - LeetCode C++ Workspace Guide

## Project Overview
This is a **LeetCode problem-solving repository** using C++17, managed by LCPR (LeetCode Problem Runner) tool. Each file represents one LeetCode problem with local testing capabilities. Problems are sourced from LeetCode CN with multilingual support.

## Build & Execution Commands

### Quick Run (Recommended)
- **VS Code:** Use `"LeetCode Local Run"` task (default Ctrl+Shift+B)
- **Command Line:** `run.bat <filename.cpp>` (Windows) or `./run.sh <filename.cpp>` (Unix)
- **Launcher:** `launcher.exe <filename>` (auto-completes .cpp extension)

### Manual Build
```bash
# Basic compilation
g++ -std=c++17 -g source.cpp -o build/output

# With memory checking (recommended for debugging)
g++ -std=c++17 -g -fsanitize=address source.cpp -o build/output
```

### Testing Single Solutions
1. Open the solution file (e.g., `1.two-sum.cpp`)
2. Modify test cases in `main()` function
3. Run using any of the quick run methods above
4. Check output against expected results in `// @lcpr case=` comments

## Code Structure & Critical Rules

### LCPR Template Structure
```
// @lcpr-before-debug-begin
[Debug preamble - minimal]

// @lc app=leetcode.cn id=<NUM> lang=cpp
// @lcpr version=30204

// @lcpr-template-start
[Standard headers: vector, unordered_map, queue, stack, etc.]

// @lc code=start
class Solution { /* ACTUAL SOLUTION HERE */ }
// @lc code=end

int main() { /* Local test cases */ }
```

### Critical Rules (NEVER VIOLATE)
- ✅ **Never remove or modify** `@lc`, `@lcpr`, or `@lcpr-template-start/end` markers
- ✅ **Place all solution logic** between `// @lc code=start` and `// @lc code=end`
- ✅ **Use provided standard library headers**; add new ones within template section if needed
- ✅ **Test locally in `main()`** before submission
- ❌ **Never manually edit** `.lcpr_data/` metadata files

## Code Style Guidelines

### Naming Conventions
- **Files:** `<id>.<slug>.cpp` (e.g., `1.two-sum.cpp`, `206.reverse-linked-list.cpp`)
- **Classes:** `Solution` (LeetCode requirement)
- **Methods:** CamelCase following LeetCode problem descriptions
- **Variables:** `camelCase` for locals, `UPPER_CASE` for constants

### Import & Usage Patterns
```cpp
// Standard headers available in template:
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
// ... more in @lcpr-template-start
```

### Common Algorithm Patterns
- **Hash-based solutions:** `unordered_map<T, int>` for O(1) lookups (two-sum, complement finding)
- **Data structures:** 
  - `stack<char>` for parentheses/expressions
  - `queue<T>` for BFS/level-order traversal
  - `priority_queue<T>` for heaps
- **Linked lists:** Three-pointer technique (pre, cur, next) for reversals
- **Comments:** Keep O(n²) approaches commented alongside O(n) solutions for reference

### Error Handling
- **Memory safety:** Compile with `-fsanitize=address` to catch buffer overflows
- **Edge cases:** Always test empty inputs, single elements, maximum constraints
- **Input validation:** LeetCode handles input validation; focus on core algorithm

## Testing Strategy

### Local Testing
1. **Modify `main()`** with your test cases
2. **Use provided test cases** in `// @lcpr case=` comments
3. **Test edge cases:** empty arrays, single elements, boundary conditions
4. **Memory testing:** Run with address sanitizer for array/pointer problems

### Multilingual Support
- **UTF-8 encoding:** Files may contain Chinese characters (e.g., `209.长度最小的子数组.cpp`)
- **Compiler compatibility:** Ensure toolchain supports UTF-8

## Development Environment Setup

### Required Tools
- **Compiler:** GCC/G++ with C++17 support
- **IDE:** VS Code (recommended) with provided tasks configuration
- **Build system:** Custom `launcher.cpp` handles cross-platform compilation

### VS Code Integration
- **Task:** `"LeetCode Local Run"` (default build task)
- **Debugging:** `-g` flag enables GDB/VSCode debugger integration
- **Output:** Binaries automatically placed in `build/` directory

## Project Metadata
- **`.lcpr_data/`:** Contains spaced-repetition tracking (`bricks.json`) and problem grouping
- **`build/`:** Compiled executables (e.g., `build/1.two-sum.exe`)
- **Binary naming:** Matches source filename without extension, platform-appropriate suffix

## Performance Considerations
- **Time complexity:** LeetCode problems typically require O(n) or O(n log n) solutions
- **Space complexity:** Optimize for O(1) or O(n) space when possible
- **Hash tables:** Preferred for O(1) lookups over binary search when appropriate
- **Input sizes:** Consider constraints in original LeetCode problem statements

## Prohibited Actions
- ❌ Removing/modifying LCPR marker comments
- ❌ Editing `.lcpr_data/` files manually
- ❌ Using external libraries beyond standard C++17 STL
- ❌ Submitting without local testing
- ❌ Ignoring UTF-8 encoding for Chinese filenames

## Quick Reference Commands
```bash
# Compile and run current file
run.bat 1.two-sum.cpp    # Windows
./run.sh 1.two-sum.cpp     # Unix

# Manual compilation
g++ -std=c++17 -g 1.two-sum.cpp -o build/1.two-sum

# Run compiled binary
./build/1.two-sum        # Unix
build\1.two-sum.exe       # Windows
```