# script.py

shared_var = 0  # 共有変数

def add(a, b):
    global shared_var
    shared_var = a + b
    string_result = f"The sum of {a} and {b} is {shared_var}"
    float_list = [float(shared_var) * i for i in range(1, shared_var + 1)]
    return string_result, shared_var, float_list

def multiply(factor):
    global shared_var
    shared_var *= factor
    string_result = f"The new value of shared_var after multiplication is {shared_var}"
    float_list = [float(shared_var) * i for i in range(1, shared_var + 1)]
    return string_result, shared_var, float_list
