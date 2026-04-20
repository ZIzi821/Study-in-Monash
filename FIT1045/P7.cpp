#include "splashkit.h"
#include <string>

using std::string;
using std::to_string;

// 定义枚举类型：菜单选项
enum menu_option
{
    READ_BOOK,
    PRINT_BOOK,
    QUIT
};

// 定义结构体：图书数据
struct book_data
{
    string title;
    string location;
    int pages;
};

// 自定义读取字符串
string read_string(string prompt)
{
    write(prompt);
    return read_line();
}

// 自定义读取整数
int read_integer(string prompt)
{
    string input = read_string(prompt);
    while (true)
    {
        bool valid = true;
        for (char c : input)
        {
            if (c < '0' || c > '9')
            {
                valid = false;
                break;
            }
        }
        if (valid && !input.empty())
            break;
        write_line("Please enter a whole number.");
        input = read_string(prompt);
    }
    return stoi(input);
}

// 输出图书信息
void print_book(const book_data &book)
{
    write_line("Title: " + book.title);
    write_line("Location: " + book.location);
    write_line("Pages: " + to_string(book.pages));
}

// 读取一本图书信息
book_data read_book()
{
    book_data result;
    result.title = read_string("Enter book title: ");
    result.location = read_string("Enter book location: ");
    result.pages = read_integer("Enter number of pages: ");
    return result;
}

// 显示菜单并读取用户选择
menu_option read_menu_option()
{
    write_line("Menu:");
    write_line("0 - Read a book");
    write_line("1 - Print book");
    write_line("2 - Quit");

    int choice = read_integer("Enter your choice: ");

    while (choice < 0 || choice > 2)
    {
        write_line("Invalid choice. Please enter 0, 1, or 2.");
        choice = read_integer("Enter your choice: ");
    }

    return static_cast<menu_option>(choice);
}

// 主函数
int main()
{
    book_data my_book = {"", "", 0};
    bool finished = false;

    while (!finished)
    {
        menu_option option = read_menu_option();

        switch (option)
        {
        case READ_BOOK:
            my_book = read_book();
            break;

        case PRINT_BOOK:
            print_book(my_book);
            break;

        case QUIT:
            finished = true;
            break;
        }
    }

    return 0;
}
