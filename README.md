# C 语言学习记录

> 大一 C 语言课的练习代码和环境配置。用 **VS Code + gcc** 写，不是 IDE 一键工程。

## 目录

| 文件 | 说明 |
|---|---|
| `hello.c` | 第一个程序，用来验证工具链是否装好 |
| `debug_practice.c` | 断点调试专用：在行号左边点红点打断点，按 F5，看左侧 VARIABLES 面板里变量怎么变 |
| `VS Code 配置 C 语言环境.md` | 从零装 gcc / 装扩展 / 配置 `tasks.json` 和 `launch.json` 的完整步骤 |

## 怎么编译运行

需要 gcc（Windows 上一般是 MinGW-w64）。

```bash
gcc hello.c -o hello.exe
./hello.exe
```

断点调试那个文件：

```bash
gcc -g debug_practice.c -o debug_practice.exe    # -g 才会带调试信息
```

然后在 VS Code 里按 F5（配置见上面那份 md）。

## 为什么代码这么少

这门课的重点是 C 语言的语法和内存模型（指针、数组、结构体），练习基本在课件和纸面上完成。这边只放**能独立跑起来、值得留档**的程序。

后面学到数组、指针、结构体、文件操作时，会按主题继续往这里加。
