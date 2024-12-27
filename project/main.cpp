#include <pybind11/pybind11.h>
#include <pybind11/embed.h> // Python埋め込み用

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

    // Pythonスクリプトを実行
    py::exec(R"(
import mymodule

# PythonでC++関数を使用
result = mymodule.add(10, 20)
print(f"Result from C++ function: {result}")
    )");

    return 0;
}
