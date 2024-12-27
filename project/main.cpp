#include <pybind11/pybind11.h>
#include <pybind11/embed.h> // Python埋め込み用
#include <fstream>
#include <sstream>
#include <iostream>

namespace py = pybind11;

// C++関数
int add(int a, int b) {
    return a + b;
}

PYBIND11_MODULE(mymodule, m) {
    m.def("add", &add, "A function that adds two numbers");
}

int main() {
    py::scoped_interpreter guard{}; // Pythonインタープリタを初期化

    try {
        // Pythonスクリプトをファイルから読み込み
        std::ifstream script_file("../script.py");
        if (!script_file.is_open()) {
            throw std::runtime_error("Failed to open script.py");
        }

        std::stringstream buffer;
        buffer << script_file.rdbuf();  // ファイル内容をバッファに読み込む
        std::string script_content = buffer.str();

        // Pythonスクリプトを実行
        py::exec(script_content);
    } catch (const py::error_already_set& e) {
        std::cerr << "Python Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
