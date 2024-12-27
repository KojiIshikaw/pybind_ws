// main.cpp

#include "ScriptExecutor.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    try {
        // ScriptExecutorのインスタンスを作成
        ScriptExecutor executor;

        // 'add'関数を実行
        py::tuple add_args = py::make_tuple(10, 2);
        py::object add_result = executor.execute("script", "add", add_args);

        // 'add'の結果を取得
        py::tuple add_tuple = add_result.cast<py::tuple>();
        if (add_tuple.size() != 3) {
            throw std::runtime_error("add関数の返り値のタプルのサイズが3ではありません");
        }

        std::string add_str = add_tuple[0].cast<std::string>();
        int add_int = add_tuple[1].cast<int>();
        py::list add_floats_py = add_tuple[2].cast<py::list>();

        std::vector<float> add_floats;
        for (auto item : add_floats_py) {
            add_floats.push_back(item.cast<float>());
        }

        // 結果の表示
        std::cout << "add関数の結果:" << std::endl;
        std::cout << "String: " << add_str << std::endl;
        std::cout << "Int: " << add_int << std::endl;
        std::cout << "Floats: ";
        for (const auto& f : add_floats) {
            std::cout << f << " ";
        }
        std::cout << std::endl;

        // 'multiply'関数を実行
        py::tuple multiply_args = py::make_tuple(3);
        py::object multiply_result = executor.execute("script", "multiply", multiply_args);

        // 'multiply'の結果を取得
        py::tuple multiply_tuple = multiply_result.cast<py::tuple>();
        if (multiply_tuple.size() != 3) {
            throw std::runtime_error("multiply関数の返り値のタプルのサイズが3ではありません");
        }

        std::string multiply_str = multiply_tuple[0].cast<std::string>();
        int multiply_int = multiply_tuple[1].cast<int>();
        py::list multiply_floats_py = multiply_tuple[2].cast<py::list>();

        std::vector<float> multiply_floats;
        for (auto item : multiply_floats_py) {
            multiply_floats.push_back(item.cast<float>());
        }

        // 結果の表示
        std::cout << "multiply関数の結果:" << std::endl;
        std::cout << "String: " << multiply_str << std::endl;
        std::cout << "Int: " << multiply_int << std::endl;
        std::cout << "Floats: ";
        for (const auto& f : multiply_floats) {
            std::cout << f << " ";
        }
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        // 実行中に発生した例外を処理
        std::cerr << "エラー: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
