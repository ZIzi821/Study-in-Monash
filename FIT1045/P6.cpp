#include "splashkit.h"
#include <string>
using namespace std;

// 定义一个结构体来保存每支队伍的数据
struct TeamData
{
    string name;
    int goals;
    int behinds;
    int score;
};

// 读取字符串输入
string read_string(string prompt)
{
    write(prompt);
    return read_line();
}

// 判断字符串是否为整数
bool is_integer(const string &s)
{
    if (s.empty())
        return false;
    for (char c : s)
    {
        if (!(c >= '0' && c <= '9'))
            return false;
    }
    return true;
}

// 读取整数输入并验证
int read_integer(string prompt)
{
    string input_line = read_string(prompt);
    while (!is_integer(input_line))
    {
        write_line("Please enter a whole number.");
        input_line = read_string(prompt);
    }
    return stoi(input_line);
}

// 计算并更新队伍得分
void calculate_score(TeamData &team)
{
    team.score = (team.goals * 6) + team.behinds;
}

// 获取队伍信息
TeamData get_team_details(int team_number)
{
    TeamData team;
    write_line("\nEnter team " + to_string(team_number) + " details:");
    team.name = read_string("Enter team " + to_string(team_number) + " name: ");
    team.goals = read_integer("Enter " + team.name + "'s goals: ");
    team.behinds = read_integer("Enter " + team.name + "'s behinds: ");
    calculate_score(team);
    return team;
}

// 打印比分详情并判断胜负
void print_details(const TeamData &team1, const TeamData &team2)
{
    write_line("\n---Current Scores---");
    write_line(team1.name + ": " + to_string(team1.goals) + " goals, " +
               to_string(team1.behinds) + " behinds, " + to_string(team1.score) + " total");
    write_line(team2.name + ": " + to_string(team2.goals) + " goals, " +
               to_string(team2.behinds) + " behinds, " + to_string(team2.score) + " total");

    write_line("\n---Match Status---");
    if (team1.score > team2.score)
    {
        write_line(team1.name + " are currently winning!");
    }
    else if (team2.score > team1.score)
    {
        write_line(team2.name + " are currently winning!");
    }
    else
    {
        write_line("It's a draw!");
    }
}

// 主循环：菜单与操作
void run_game_loop(TeamData &team1, TeamData &team2)
{
    bool quit = false;
    while (!quit)
    {
        write_line("\n---Menu---");
        write_line("1: Update " + team1.name + "'s goals");
        write_line("2: Update " + team1.name + "'s behinds");
        write_line("3: Update " + team2.name + "'s goals");
        write_line("4: Update " + team2.name + "'s behinds");
        write_line("5: Print detailed scores");
        write_line("6: Quit");

        int choice = read_integer("Enter your choice: ");

        switch (choice)
        {
        case 1:
            team1.goals = read_integer("Enter new goals for " + team1.name + ": ");
            calculate_score(team1);
            break;
        case 2:
            team1.behinds = read_integer("Enter new behinds for " + team1.name + ": ");
            calculate_score(team1);
            break;
        case 3:
            team2.goals = read_integer("Enter new goals for " + team2.name + ": ");
            calculate_score(team2);
            break;
        case 4:
            team2.behinds = read_integer("Enter new behinds for " + team2.name + ": ");
            calculate_score(team2);
            break;
        case 5:
            print_details(team1, team2);
            break;
        case 6:
        {
            string answer = read_string("Are you sure you want to quit? [y/n]: ");
            if (answer == "y" || answer == "Y")
            {
                write_line("Bye!");
                quit = true;
            }
            break;
        }
        default:
            write_line("Invalid choice. Please enter a number between 1 and 6.");
            break;
        }
    }
}

// 主函数入口
int main()
{
    write_line("Welcome to the AFL score calculator!");

    TeamData team1 = get_team_details(1);
    TeamData team2 = get_team_details(2);

    run_game_loop(team1, team2);

    return 0;
}
