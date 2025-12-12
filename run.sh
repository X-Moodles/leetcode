#!/bin/bash

# 检查是否提供了文件名
if [ -z "$1" ]; then
    echo "用法: ./run.sh <文件名.cpp>"
    echo "例如: ./run.sh 1.two-sum.cpp"
    exit 1
fi

# 确保 build 目录存在
mkdir -p build

# 获取不带路径和后缀的文件名
FILENAME=$(basename "$1")
BASENAME="${FILENAME%.*}"

# 编译命令
# -std=c++17: 使用 C++17 标准
# -g: 生成调试信息 (供 GDB/VSCode 调试使用)
# -fsanitize=address: 开启地址检查，自动检测数组越界、内存泄漏等错误
echo "[正在编译] $1 ..."
g++ -std=c++17 -g -fsanitize=address "$1" -o "build/$BASENAME"

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo "[运行中] build/$BASENAME"
    echo "--------------------------------------------------"
    "./build/$BASENAME"
    echo "--------------------------------------------------"
else
    echo "[编译失败] 请检查代码错误。"
fi
