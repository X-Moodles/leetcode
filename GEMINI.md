# LeetCode Workspace (C++)

## Project Overview
This directory serves as a workspace for solving LeetCode problems using C++. It appears to be managed by a LeetCode helper tool (likely a VS Code extension or CLI like `leetcode-editor` or `lcpr`), indicated by the `.lcpr_data` directory and specific comment annotations in the source files.

## Directory Structure
*   **Source Files (`<id>.<slug>.cpp`):** Contains the C++ solution, standard library includes, a local `main()` function for testing, and test case data in comments.
    *   Example: `1.two-sum.cpp`
*   **Binaries:** Compiled executables corresponding to the source files (e.g., `1.two-sum`).
*   **`.lcpr_data/`:** Contains metadata for the helper tool, such as spaced repetition schedules (`bricks.json`) and grouping information (`group.json`).

## Development Conventions
*   **Code Sections:**
    *   `// @lc code=start` ... `// @lc code=end`: Place your actual solution logic here.
    *   `// @lcpr-template-start` ...: Includes common headers (`<vector>`, `<iostream>`, etc.) to simulate the LeetCode environment.
*   **Local Testing:**
    *   The files include a `main()` function to run the solution locally.
    *   Modify the inputs in `main()` to test different scenarios.
    *   Test cases are also documented in comments (e.g., `// @lcpr case=start`).
*   **Tool Metadata:** Avoid manually editing the `@lc ...` comments, as they are used by the plugin/tool to track problem status and submissions.

## Building and Running
To compile and run a specific solution (e.g., `1.two-sum.cpp`):

1.  **Compile:**
    ```bash
    g++ -o 1.two-sum 1.two-sum.cpp
    ```
    *(Note: You may need to add flags like `-std=c++17` depending on the features used)*

2.  **Run:**
    ```bash
    ./1.two-sum
    ```

## Tools
*   **Compiler:** GCC (`g++`) or Clang.
*   **Manager:** LeetCode VS Code extension or similar CLI tool using the `.lcpr` format.
