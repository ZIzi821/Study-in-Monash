#include "utilities.h"
#include "splashkit.h"

string read_string(string prompt)
{
    write(prompt);      // 输出提示
    return read_line(); // 读取用户输入的一整行
}

int read_integer(string prompt)
{
    string line = read_string(prompt);
    while (!is_integer(line)) // 如果输入不是整数
    {
        write_line("Please enter a whole number.");
        line = read_string(prompt);
    }
    return stoi(line); // 转换为整数并返回
}

// 新增：带范围限制的版本
int read_integer(string prompt, int min, int max)
{
    int value = read_integer(prompt);  // 先用已有的单参数版本读取
    while (value < min || value > max) // 检查范围
    {
        write_line("Please enter a number between " + std::to_string(min) + " and " + std::to_string(max) + ".");
        value = read_integer(prompt);
    }
    return value;
}