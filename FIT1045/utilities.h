#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using std::string;

/**
 * 读取用户输入的字符串
 * @param prompt 提示信息
 * @return 用户输入的字符串
 */
string read_string(string prompt);

/**
 * 读取用户输入的整数
 * @param prompt 提示信息
 * @return 用户输入的整数
 */
int read_integer(string prompt);

/**
 * 读取用户输入的整数，并限制范围
 * @param prompt 提示信息
 * @param min 最小允许值
 * @param max 最大允许值
 * @return 用户输入的整数（保证在范围内）
 */
int read_integer(string prompt, int min, int max);

#endif