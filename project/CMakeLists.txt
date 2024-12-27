cmake_minimum_required(VERSION 3.14)
project(PybindExample)

# C++17を指定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# pybind11をFetchContentで取得
include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.11.1  # 適切なバージョンを指定
)
FetchContent_MakeAvailable(pybind11)

# Pythonインタプリタへのパスを取得
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Pythonモジュールのビルド
pybind11_add_module(mymodule mymodule.cpp)

# 実行ファイルのビルド
add_executable(main main.cpp)

# 実行ファイルにリンクするライブラリを指定
target_link_libraries(main PRIVATE Python3::Python pybind11::embed)

# インストールルール（オプション）
install(TARGETS mymodule DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages)
install(TARGETS main DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
