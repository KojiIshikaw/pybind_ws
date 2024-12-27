// ScriptExecutor.h

#ifndef SCRIPT_EXECUTOR_H
#define SCRIPT_EXECUTOR_H

#include <pybind11/embed.h> // 埋め込みに必要なすべて
#include <string>
#include <iostream>

namespace py = pybind11;

class ScriptExecutor {
public:
    ScriptExecutor() {
        // Pythonインタプリタの初期化
        py::initialize_interpreter();

        // sys.path にスクリプトのディレクトリを追加
        py::module sys = py::module_::import("sys");
        py::list sys_path = sys.attr("path");
        // ここでスクリプトが存在するディレクトリを指定
        // 例えば、プロジェクトのルートディレクトリが親ディレクトリの場合
        sys_path.append("/home/koji/pybind_ws/script");
    }

    ~ScriptExecutor() {
        // Pythonインタプリタの終了
        py::finalize_interpreter();
    }

    // 指定されたPythonモジュールの関数を引数付きで実行
    py::object execute(const std::string& module_name, const std::string& function_name, const py::tuple& args) {
        try {
            // Pythonモジュールのインポート
            py::object module = py::module_::import(module_name.c_str());

            // モジュールから関数を取得
            py::object func = module.attr(function_name.c_str());

            // 関数を引数とともに呼び出し
            return func(*args);
        }
        catch (py::error_already_set& e) {
            // Python例外の処理
            std::cerr << "Pythonエラー: " << e.what() << std::endl;
            throw;
        }
    }
};

#endif // SCRIPT_EXECUTOR_H
