# C++ 练习与课程作业

整理学习过程中留下的 C++ 练习、课程作业和 Qt 小项目。按代码内容分类，同一道题的不同实现分别保留。

## 目录

| 目录 | 内容 |
| --- | --- |
| `basics/` | 入门输出、浮点数实验 |
| `classes/` | 类与对象、运算符重载 |
| `inheritance/` | 继承、多态、字符串编辑与库存管理 |
| `templates/` | 泛型数组、容器、排序、链表派生栈和队列 |
| `stl/` | 标准库算法、lambda、最近访问去重 |
| `data_structures/linked_lists/` | 链表、约瑟夫环、学生有序链表 |
| `data_structures/stacks/` | 栈操作、后缀表达式 |
| `data_structures/trees/` | 树高、遍历转换 |
| `algorithms/strings/` | KMP、路径简化、字符消除 |
| `algorithms/sorting/` | 基数排序、桶方法求最大间距 |
| `algorithms/search/` | 迷宫搜索、24 点搜索 |
| `algorithms/math/` | 稀疏矩阵、奇偶校验、二项式展开、24 点表达式校验 |
| `qt/` | 窗口操作与拖拽排序演示 |
| `archive/` | 未完成练习、代码片段、基础模板与实验草稿 |

## 使用

大多数控制台练习为独立源文件，分别编译运行。多个文件有各自的 `main`，不要把整个仓库链接成一个程序。例如：

```sh
g++ -std=c++17 algorithms/strings/kmp_search.cpp -o kmp_search
```

有些原始源码采用 Windows 中文编码，若编译器按 UTF-8 读取时报告编码错误，可按文件实际编码设置输入字符集。整理保留了源码原始字节和注释。

`qt/` 中的每个子目录是独立 Qt 项目：有 `CMakeLists.txt` 的项目使用 CMake，有 `.pro` 的项目使用 qmake；可通过 Qt Creator 打开对应构建文件。安装相应 Qt Widgets 开发环境后构建，不附带本机 Qt 路径、缓存或编译产物。

## 版本与完成状态

- 同题不同版本根据实现方式或原项目名区分；名称中的 `project2`、`project3` 等只表示来源，不表示版本优劣。
- `archive/leetcode_templates/` 的两个文件函数体为空，保留题目模板。
- `archive/fragments/` 包含无主函数的类片段。
- `archive/drafts/` 保留未完成的表达式求值、商品管理以及形状多态草稿。
- `archive/experiments/` 和 `archive/legacy_tests/` 保留混合实验与历史脚手架；部分文件为空或无法编译。
- `archive/qt_starter/` 是基础 Qt 窗口模板。
- `archive/needs_fixes/` 的两份模板练习未通过本次语法检查：泛型容器使用了不存在的 `data` 成员，链表栈队列练习将 `Insert` 写成了 `insert`。保留原代码，等待以后修订。

此次整理只调整文件名、目录和说明，未修复历史代码。编译检查结果见 `VALIDATION.md`；通过编译不代表通过题目正确性测试。
