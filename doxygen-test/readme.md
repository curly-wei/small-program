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
