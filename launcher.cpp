#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

// 判断是否为 Windows 环境
#ifdef _WIN32
    const bool IS_WINDOWS = true;
    const std::string EXE_SUFFIX = ".exe";
#else
    const bool IS_WINDOWS = false;
    const std::string EXE_SUFFIX = "";
#endif

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./launcher <source_file.cpp>" << std::endl;
        return 1;
    }

    fs::path sourcePath = argv[1];
    
    // 如果用户忘记写 .cpp 后缀，尝试自动补全
    if (sourcePath.extension() != ".cpp") {
        sourcePath += ".cpp";
    }

    if (!fs::exists(sourcePath)) {
        std::cerr << "Error: File not found: " << sourcePath << std::endl;
        return 1;
    }

    // 准备 build 目录
    fs::path buildDir = "build";
    if (!fs::exists(buildDir)) {
        fs::create_directory(buildDir);
    }

    // 构建输出文件路径: build/filename[.exe]
    std::string stem = sourcePath.stem().string();
    fs::path outputPath = buildDir / (stem + EXE_SUFFIX);

    // 构建编译命令
    // -std=c++17: 使用 C++17
    // -g: 调试信息
    // -fsanitize=address: 内存检查 (Windows 上某些 MinGW 版本可能不支持，如果报错请去掉)
    std::string compileCmd = "g++ -std=c++17 -g ";
    
    // 注意: Windows 下某些旧版 MinGW 可能不支持 -fsanitize=address，如果编译慢或报错可移除
    // compileCmd += "-fsanitize=address "; 
    
    compileCmd += "\"" + sourcePath.string() + "\" -o \"" + outputPath.string() + "\"";

    std::cout << "[Compiling] " << sourcePath.string() << " ..." << std::endl;
    
    int compileResult = std::system(compileCmd.c_str());

    if (compileResult != 0) {
        std::cerr << "[Build Failed] Return code: " << compileResult << std::endl;
        return compileResult;
    }

    std::cout << "[Running] " << outputPath.string() << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    // 运行编译后的程序
    std::string runCmd = "\"" + outputPath.string() + "\"";
    int runResult = std::system(runCmd.c_str());

    std::cout << "\n--------------------------------------------------" << std::endl;
    
    return runResult;
}
