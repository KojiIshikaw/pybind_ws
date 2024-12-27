// main.cpp

#include "ScriptExecutor.h"
#include <iostream>

int main() {
    try {
        // ScriptExecutorのインスタンスを作成
        ScriptExecutor executor;

        // 例1: 'add'関数を実行
        {
            // 引数をPythonのタプルとして準備
            py::tuple args = py::make_tuple(10, 20);

            // 'add'関数を実行
            py::object result = executor.execute("script", "add", args);

            // 結果をC++のintに変換
            int sum = result.cast<int>();

            std::cout << "add(10, 20) の結果: " << sum << std::endl;
        }

        // 例2: 'greet'関数を実行
        {
            // 引数をPythonのタプルとして準備
            py::tuple args = py::make_tuple("太郎");

            // 'greet'関数を実行
            py::object result = executor.execute("script", "greet", args);

            // 結果をC++のstd::stringに変換
            std::string greeting = result.cast<std::string>();

            std::cout << "挨拶: " << greeting << std::endl;
        }
    }
    catch (const std::exception& e) {
        // 実行中に発生した例外を処理
        std::cerr << "エラー: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
