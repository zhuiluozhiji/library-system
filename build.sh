#!/bin/bash

# 创建并进入 build 目录
mkdir -p build
cd build

# 运行 cmake 生成 Makefile
cmake ..

# 编译项目
if make; then
    echo "-------------------------------------------------------------------------"
    # 编译成功，运行可执行文件
    ./bin/library-system
else
    echo "编译失败！"
fi

# 返回上级目录
cd ..