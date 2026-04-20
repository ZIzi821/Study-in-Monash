#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Utility function: trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

// Utility function: convert string to lowercase
std::string to_lower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return result;
}

// Utility function: check if a string is numeric
bool is_numeric(const std::string& str) {
    return !str.empty() &&
           std::all_of(str.begin(), str.end(), ::isdigit);
}

// Utility function: safe integer input
int read_int() {
    int value;
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        input = trim(input);
        if (is_numeric(input)) {
            value = std::stoi(input);
            break;
        } else {
            std::cout << "Invalid input, please enter a number: ";
        }
    }
    return value;
}

// ---- Program entry point ----
int main() {
    std::cout << "==============================" << std::endl;
    std::cout << "   Welcome to TravelCalculator" << std::endl;
    std::cout << "==============================" << std::endl;

    std::cout << "Iteration 2: Now with Utilities!" << std::endl;

    // Example usage of utilities
    std::cout << "Enter a number: ";
    int n = read_int();
    std::cout << "You entered: " << n << std::endl;

    std::string s = "   HeLLo World   ";
    std::cout << "Original: '" << s << "'" << std::endl;
    std::cout << "Trimmed: '" << trim(s) << "'" << std::endl;
    std::cout << "Lowercase: '" << to_lower(s) << "'" << std::endl;

    return 0;
}
