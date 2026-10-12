# VS Code 配置 C 语言：编译 + 调试 完整方法

> 适用：Windows 10 / 11，64 位。
> 目标：在 VS Code 里写 `.c` 文件 → 一键编译 → **打断点单步调试**（这是 VS Code 相比 Dev-C++ 最大的优势）。

---

## 0. 先搞清楚原则（很重要）

VS Code **本身不是编译器**，它只是个编辑器。要能编译和调试 C，必须凑齐三样东西：

| 角色 | 需要的东西 | 谁提供 |
|---|---|---|
| 编译器 `gcc` | 把 `.c` 变成 `.exe` | MinGW-w64 |
| 调试器 `gdb` | 让断点、单步能工作 | MinGW-w64（同一包里有） |
| 编辑器插件 | VS Code 的 C/C++ 支持 | 微软的 `C/C++` 扩展 |

**三样缺一不可。** 只装 VS Code 插件、不装 MinGW，一定会遇到 `gcc: 无法将"gcc"项识别为...` 或 `Cannot find "gcc"`。

另外还有个隐藏要求：**`gcc` 和 `gdb` 必须在 PATH 里**，或者配置文件里写死绝对路径。本目录的配置文件走的是"写死绝对路径"路线，所以下面第 1 步的安装位置要照做。

---

## 1. 安装 MinGW-w64（编译器 + 调试器）

### 方案 A：WinLibs 便携版（推荐，最省事）

1. 打开 <https://github.com/brechtsanders/winlibs_mingw/releases/latest>
2. 在 Assets 里找文件名形如：
   `winlibs-x86_64-posix-seh-gcc-14.x.x-mingw-w64ucrt-12.x.x-r2.zip`
   （**选 `.zip` 结尾的**，不要选 `.7z`，因为 7z 需要额外装解压软件）
3. 解压后里面会有一个 `mingw64` 文件夹
4. **把整个 `mingw64` 文件夹放到 `C:\` 下面**，最终路径必须是：
   ```
   C:\mingw64\bin\gcc.exe
   C:\mingw64\bin\gdb.exe
   ```

> ⚠️ 这就是为什么配置文件里写的是 `C:/mingw64/bin/gcc.exe`。**如果你放到别的位置**，请把下面 4 个文件里所有的 `C:/mingw64/bin` 替换成你的实际路径（VS Code 里 `Ctrl+Shift+H` 全局替换）：
> - `.vscode/tasks.json`
> - `.vscode/launch.json`
> - `.vscode/c_cpp_properties.json`
> - `.vscode/settings.json`

### 方案 B：MSYS2（更规范，能装新库）

1. 下载安装 <https://www.msys2.org/>（默认装到 `C:\msys64`）
2. 打开 **MSYS2 UCRT64** 终端，执行：
   ```bash
   pacman -Syu
   # 窗口会自动关闭，重新打开 MSYS2 UCRT64 再执行一次
   pacman -Syu
   pacman -S --needed mingw-w64-ucrt-x86_64-toolchain
   ```
   一路回车，全部安装。
3. 工具链位置变成 `C:\msys64\ucrt64\bin\`，所以要把配置里的
   `C:/mingw64/bin` → `C:/msys64/ucrt64/bin`

### 方案 C：直接用 Dev-C++ 自带的 TDM-GCC

如果你已经装了 Dev-C++ 5.11，它自带编译器，位置一般是：
```
C:\Program Files (x86)\Dev-Cpp\MinGW64\bin
```
把配置里的 `C:/mingw64/bin` 换成它即可。

> ⚠️ 但 TDM-GCC 4.9.2（2015 年）太老了：`-std=c17`、较新的警告、部分 C11 特性都不支持。
> 本目录的任务特意用了 `-std=c11` 来兼容它。**只学 C 基础够用，但不推荐长期这么干。**

---

## 2. 验证编译器装好了（必做）

按 `Win + R` → 输入 `cmd` → 回车，然后敲：

```cmd
C:\mingw64\bin\gcc.exe --version
C:\mingw64\bin\gdb.exe --version
```

两条都能打印出版本号，就说明装对了。如果提示"系统找不到指定的文件"，说明**第 1 步的路径不对**，回去检查。

（可选）想把 `gcc` 加进 PATH，让任何终端都能直接用：

```cmd
setx PATH "%PATH%;C:\mingw64\bin"
```

**设置完必须关掉所有终端和 VS Code 重开才生效。**

---

## 3. 安装 VS Code 扩展

在 VS Code 里按 `Ctrl+Shift+X`，搜索并安装：

| 扩展名 | 发布者 | 作用 |
|---|---|---|
| **C/C++** | Microsoft（`ms-vscode.cpptools`） | 必须。提供智能提示 + 调试器 |
| C/C++ Extension Pack | Microsoft | 可选，装了上面会自动带上 |

> 只要这**一个 C/C++ 扩展**就够。别去装 "C/C++ Compile Run"、"Code Runner" 之类的，它们只是帮你敲命令行，**不支持真正的断点调试**。

---

## 4. 打开正确的文件夹

VS Code 菜单：`文件 → 打开文件夹`，选择

```
C:\Users\38875\Desktop\Java学习
```

⚠️ **必须打开整个文件夹，不能只双击打开单个 `.c` 文件。** 因为配置放在 `.vscode/` 目录下，只有作为"工作区文件夹"打开时才会被读取。

打开后，左侧资源管理器里应该能看到一个 `.vscode` 文件夹（默认可能被隐藏，去 `文件 → 首选项 → 设置` 搜 `exclude` 看一眼也行）。

---

## 5. 编译运行

打开 `C语言/hello.c`，然后：

| 操作 | 快捷键 | 说明 |
|---|---|---|
| 编译 | `Ctrl + Shift + B` | 跑默认生成任务，生成 `hello.exe` |
| 编译并运行 | `Ctrl + Shift + P` → 输入 `运行测试任务` → 回车 | 先编译再执行，直接看到输出 |
| 选择其他任务 | `Ctrl + Shift + P` → `Tasks: Run Task` | 出现 4 个任务可选（见下表） |

已配置好的 4 个任务：

| 任务名 | 参数 | 什么时候用 |
|---|---|---|
| `C: 编译当前文件 (调试版)` | `-g -Wall -Wextra` | **调试前自动用这个**，带调试信息 |
| `C: 编译并运行当前文件` | 编译 + 自动执行 | 快速看结果 |
| `C: 编译当前文件 (Release 优化版)` | `-O2` | 想测性能时；**优化后断点会跳行，别用它调试** |
| `C: 编译当前文件 (数学库 -lm)` | 附加 `-lm` | 报 `undefined reference to sqrt` 时用 |

---

## 6. 调试（核心）

### 基本流程

1. 打开 `C语言/debug_practice.c`
2. **在行号左边灰色空白处点一下**，出现红点 = 断点（`F9` 也能切换）
   - 在第 11 行 `int sum = a + b;` 打一个
   - 在第 26 行 `total = add(total, i);` 打一个
3. 按 **`F5`**（或左侧"运行和调试"图标 → 绿色三角）
4. 第一次会弹出选择环境，**选 `C: 调试当前文件 (gdb)`**
   - 配置已经写好了，正常情况下不会再问
5. 程序会弹出一个**独立的黑色控制台窗口**，提示 `Enter an integer:`，输入 `5` 回车
6. 程序在第 26 行断点处停住，窗口跑到前台

### 停下来之后怎么用

| 操作 | 快捷键 | 效果 |
|---|---|---|
| 继续 | `F5` | 跑到下一个断点 |
| 单步跳过 | `F10` | 执行这一行，**函数调用当作一步**（不进函数内部） |
| 单步进入 | `F11` | 执行这一行，**如果是函数调用就钻进去** |
| 单步跳出 | `Shift + F11` | 从当前函数里跳回调用处 |
| 重启 | `Ctrl + Shift + F5` | 从头再来一遍 |
| 停止 | `Shift + F5` | 结束调试 |

### 看变量

程序停住时，左边侧栏会自动出现：

- **VARIABLES（变量）**：当前作用域所有变量的值。展开 `Locals` 能看到 `n`、`i`、`total`
  - 在 `add()` 里面停住时，能看到 `a`、`b`、`sum`
- **WATCH（监视）**：点 `+` 可以填**表达式**，比如 `total + i`、`i * 2`，会实时算给你看
- **CALL STACK（调用栈）**：能看到 `add` ← `main` 的层级。**点某一层可以跳回那一层的上下文**，看当时 `main` 里的变量是什么值
- **鼠标悬停**：直接把光标放到变量名上，会浮出当前值，最快

### 调试时最实用的三个动作

1. **在 `add()` 里 `F10` 一步步走**，看 `sum` 怎么被算出来 → 理解函数调用
2. **在循环里反复按 `F5`**，每按一次 `total` 就累加一次 → 理解循环累加
3. **在监视里填 `i` 和 `total`**，看着它们同步变化 → 这是排查"循环写错了"的标准姿势

---

## 7. 常见报错速查

| 报错 | 原因 | 解决 |
|---|---|---|
| `gcc: 无法将"gcc"项识别...` / `Cannot find "gcc"` | 路径写错，或编译器没装 | 检查 `C:\mingw64\bin\gcc.exe` 是否存在 |
| `spawn C:/mingw64/bin/gcc.exe ENOENT` | 同上，路径不存在 | 同上 |
| `miDebuggerPath` / `Unable to start debugging. gdb not found` | `gdb.exe` 不在那个位置 | 确认 `C:\mingw64\bin\gdb.exe` 存在；WinLibs 要选**完整包**（有的精简包不带 gdb） |
| 编译通过了，但 `F5` 调试报"找不到 exe" | 没先编译 / `preLaunchTask` 名字对不上 | 检查 `launch.json` 里的 `preLaunchTask` 和 `tasks.json` 的 `label` **完全一致** |
| 断点变成**空心灰圈** | exe 里没有调试信息，或源码和 exe 不同步 | 用"调试版"任务编译（必须有 `-g`）；重新编译一次 |
| 断点打不上 / 提示 `Breakpoint set but not yet bound` | 用了 `-O2` 优化 | 换回"调试版"任务 |
| `undefined reference to 'sqrt'` | 数学库没链接 | 用 `C: 编译当前文件 (数学库 -lm)` 任务 |
| `printf` 里中文变乱码 | 源码是 UTF-8，但 Windows 控制台是 GBK | 见下面第 8 节 |
| 程序跑起来一闪而过 | 直接双击 exe 了 | 在 VS Code 终端里用任务运行，或在 `main` 的 `return` 前加 `getchar();` |
| `scanf` 之后程序不响应输入 | 用的是内置 Debug Console | 用 `externalConsole: true` 那个配置（已设为默认），会弹独立窗口 |
| `.vscode` 里的文件被 VS Code 提示"JSON 有错误" | 逗号/括号写错 | 看波浪线位置；JSON **不能有注释** |

---

## 8. 两个 Windows 特有的坑

### 坑 1：中文路径

你的工作目录是 `C:\Users\38875\Desktop\Java学习`，**路径里有中文**。

- 新版 MinGW-w64 + 中文系统：一般**没问题**
- 老版 TDM-GCC 4.9.2：**很可能报奇怪的错**（找不到文件、乱码）

如果编译时报莫名其妙的"文件不存在"，第一件事就是**把代码换到纯英文路径**试试：

```
D:\code\c
```

这也是为什么我建议你以后单独建一个 `D:\code` 放 C 代码。

### 坑 2：C 源码里的中文输出乱码

Windows 控制台默认是 GBK(936)，而 VS Code 默认把文件存成 UTF-8。直接在 `printf` 里写中文会乱码。

**最简单的做法：C 源码里先别写中文**（本目录的两个示例已经改成英文提示了）。

确实需要中文的话，在 `tasks.json` 的 `args` 里加一个参数：

```json
"-fexec-charset=GBK",
```

加上之后重新编译，`printf("请输入: ");` 就能正常显示。

---

## 9. 一页速记

```
装 MinGW-w64  →  解压成 C:\mingw64  →  验证 gcc/gdb --version
      ↓
VS Code 装 "C/C++" 扩展（微软）
      ↓
打开文件夹 C:\Users\38875\Desktop\Java学习（不是单个文件！）
      ↓
写 .c 文件  →  行号左边点红点打断点  →  按 F5
      ↓
F10 单步跳过 / F11 单步进入 / 鼠标悬停看值
      ↓
左边 VARIABLES 看变量，WATCH 看表达式，CALL STACK 看调用层级
```

---

## 附：本目录已经给你准备好的文件

```
Java学习/
├── .vscode/
│   ├── tasks.json              # 4 个编译任务
│   ├── launch.json             # 2 个调试配置（cppdbg + gdb）
│   ├── c_cpp_properties.json   # 智能提示 / 头文件索引
│   ├── settings.json           # 编辑器默认设置
│   └── extensions.json         # 提示安装 C/C++ 扩展
└── C语言/
    ├── hello.c                 # 最小示例
    ├── debug_practice.c        # 调试练习（断点已经标好位置）
    └── VS Code 配置 C 语言环境.md   # 本文件
```

**唯一需要动的**：如果你没把 MinGW 装到 `C:\mingw64`，就全局替换 `C:/mingw64/bin` 为你的实际路径。
