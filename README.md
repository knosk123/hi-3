# 解决clion中文乱码问题

本仓库记录 CLion 下中文乱码的处理方法，核心思路是把**源文件编码、编译编码、运行时控制台编码**统一为 UTF-8。

## 主要做法

1. 把 CLion 的项目编码和文件编码都设置为 `UTF-8`。
2. 用 `.editorconfig` 固定文本编码，避免不同编辑器写出不同编码。
3. 在 CMake 里为编译器添加 UTF-8 参数。
4. 在 Windows 程序启动时切换控制台编码到 UTF-8。
5. Windows 下清屏优先使用 `cls`，避免 ANSI 控制符在 Run 窗口里直接显示出来。

## CMake 示例

```cmake
function(add_utf8_executable target source)
    add_executable(${target} ${source})
    if (MSVC)
        target_compile_options(${target} PRIVATE /utf-8)
    else()
        target_compile_options(${target} PRIVATE -finput-charset=UTF-8 -fexec-charset=UTF-8)
    endif()
endfunction()
```

## Windows 控制台示例

```cpp
#ifdef _WIN32
#include <windows.h>
#endif

void setup_console_encoding() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}
```

## 清屏示例

```cpp
#ifdef _WIN32
system("cls");
#else
printf("\033[H\033[2J");
#endif
```

## 总结

只要把“编辑器编码、编译参数、控制台编码”三处统一，CLion 里的中文输出和输入就能稳定正常显示。
