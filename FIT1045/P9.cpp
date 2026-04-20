#include "splashkit.h"
using namespace std;

// Function to analyze grades and display results on the window
void analyseGrades(const vector<int>& grades)
{
    if (grades.empty())
    {
        draw_text("No grades entered.", COLOR_RED, 20, 200);
        return;
    }

    int sum = 0, passCount = 0, highDistinction = 0;

    // Calculate sum, pass count, and high distinction count
    for (int g : grades)
    {
        sum += g;
        if (g >= 50) passCount++;
        if (g >= 80) highDistinction++;
    }

    // Calculate average and pass rate
    double average = (double)sum / grades.size();
    double passRate = (double)passCount / grades.size() * 100.0;

    // Display results on the window
    draw_text("Average: " + to_string(average), COLOR_BLACK, 20, 250);
    draw_text("Pass rate: " + to_string(passRate) + "%", COLOR_BLACK, 20, 280);
    draw_text("High distinctions: " + to_string(highDistinction), COLOR_BLACK, 20, 310);
}

int main()
{
    // Open a window for displaying results
    open_window("Grade Analysis", 800, 600);

    vector<int> grades;

    // Display instruction on the window
    draw_text("Enter up to 20 grades (0-100). Type -1 to finish.", COLOR_BLACK, 20, 50);
    refresh_screen();

    // Input grades using SplashKit read_line()
    while (grades.size() < 20)
    {
        // Show prompt in console
        write("Enter grade " + to_string(grades.size() + 1) + ": ");

        // Read input from console
        string input = read_line();

        // Convert string to integer
        int g = stoi(input);

        if (g == -1) break;
        if (g >= 0 && g <= 100)
        {
            grades.push_back(g);
        }
        else
        {
            write_line("Grade must be between 0 and 100.");
        }
    }

    // Clear screen and display analysis results
    clear_screen(COLOR_WHITE);
    analyseGrades(grades);
    refresh_screen();

    // Keep the window open for 10 seconds
    delay(10000);
    return 0;
}