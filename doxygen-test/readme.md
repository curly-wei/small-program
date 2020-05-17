# Conf guide

## Source Tree

``` text
- .
  -- ./doc <- doxygen work dir
  -- ./src
```

## Generate initial doxgen file

``` bash
doxygen -g
```

## Setting

1.Setting project_name

``` text
PROJECT_NAME = your project name
```

2.Setting input files

``` text
INPUT                  = ../src
```

3.Search sub-dir

``` text
RECURSIVE              = YES
```

4.Edit File_pattern to include \* of x.*

``` text
FILE_PATTERNS = ...
```

## Write doc for your source code

1.Write introduction of this file

### t.h

``` c
/**
 * @file t.h
 * @brief Headers of t
 * @author curlywei
 * @date 1994-07-24
 * @version 0.0.1
*/
```

### t.c

``` c
/**
 * @file t.c
 * @brief Implemention of "t.h"
*/
```

## Generate doc

``` bash
doxygen doxyfile
```

## Ref

Reference(https://blog.csdn.net/u013187057/article/details/103475548)

```
# 项目名称，将作为于所生成的程序文档首页标题
PROJECT_NAME        = “xxx”
# 文档版本号，可对应于项目版本号，譬如 svn、cvs 所生成的项目版本号
PROJECT_NUMBER      = "1.0.0"
PROJECT_BRIEF          = "xxx"
# 程序文档输出目录
OUTPUT_DIRECTORY    =  docs
 
# 程序文档输入目录 
INPUT                = @CMAKE_CURRENT_LIST_DIR@/apps    \
                       @CMAKE_CURRENT_LIST_DIR@/include \
                       @CMAKE_CURRENT_LIST_DIR@/modules \
                       @CMAKE_CURRENT_LIST_DIR@/samples
 
# 程序文档语言环境
OUTPUT_LANGUAGE      = Chinese
DOXYFILE_ENCODING  = UTF-8
# 只对头文件中的文档化信息生成程序文档 
FILE_PATTERNS        = *.h *.cpp
 
# 递归遍历当前目录的子目录，寻找被文档化的程序源文件 
RECURSIVE            = YES 
# 如果是制作 C 程序文档，该选项必须设为 YES，否则默认生成 C++ 文档格式
OPTIMIZE_OUTPUT_FOR_C  = NO
 
#提取信息，包含类的私有数据成员和静态成员
EXTRACT_ALL            = yes
EXTRACT_PRIVATE        = yes
EXTRACT_STATIC        = yes
# 对于使用 typedef 定义的结构体、枚举、联合等数据类型，只按照 typedef 定义的类型名进行文档化
TYPEDEF_HIDES_STRUCT  = YES
# 在 C++ 程序文档中，该值可以设置为 NO，而在 C 程序文档中，由于 C 语言没有所谓的域/名字空间这样的概念，所以此处设置为 YES
HIDE_SCOPE_NAMES      = YES
# 让 doxygen 静悄悄地为你生成文档，只有出现警告或错误时，才在终端输出提示信息
QUIET  = YES
# 递归遍历示例程序目录的子目录，寻找被文档化的程序源文件
EXAMPLE_RECURSIVE      = YES
# 允许程序文档中显示本文档化的函数相互调用关系
REFERENCED_BY_RELATION = YES
REFERENCES_RELATION    = YES
REFERENCES_LINK_SOURCE = YES
# 不生成 latex 格式的程序文档
GENERATE_LATEX        = NO
# 在程序文档中允许以图例形式显示函数调用关系，前提是你已经安装了 graphviz 软件包
HAVE_DOT              = YES
CALL_GRAPH            = YES
CALLER_GRAPH          = YES
#在最后生成的文档中，把所有的源代码包含在其中
SOURCE_BROWSER        = YES
#这会在HTML文档中，添加一个侧边栏，并以树状结构显示包、类、接口等的关系
GENERATE_HTML         = YES
#GENERATE_TREEVIEW      ＝ YES
————————————————
版权声明：本文为CSDN博主「六月的雨唯你」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u013187057/java/article/details/103475548
```
