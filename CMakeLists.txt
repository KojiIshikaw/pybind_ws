# CMakeLists.txt

cmake_minimum_required(VERSION 3.4...3.18)
project(EmbedPythonExample)

# C++の標準を指定
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# pybind11を見つける
find_package(pybind11 REQUIRED)

# 実行ファイルを追加
add_executable(main main.cpp)

# pybind11の埋め込みライブラリをリンク
target_link_libraries(main PRIVATE pybind11::embed)
