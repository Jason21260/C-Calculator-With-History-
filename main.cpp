#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> calc_history;

int calculator();
void history();
void choice();

int main() {
    int x;
    std::cout << "\t\t\t\tWhat do you want to do?\n\n";
    std::cout << "\t\t\t\t[1] Standard calculator\n";
    std::cout << "\t\t\t\t[2] History\n";
    std::cout << "\t\t\t\t[3] Exit\n\n\n\n";
    std::cout << "\t\t\t\tChoice:";
    std::cin >> x;

    switch (x) {
        case 1:
            calculator();
            break;
        case 2:
            history();
            break;
        case 3:
            exit(0);
            break;
        default:
            std::cout << "Enter Correct choice!\n";
            main();
    }
    return 0;
}

int calculator() {
    double num1, num2, result;
    char op;
    char back;

    std::cout << "Welcome to My Calculator!\n";
    std::cout << "Enter Your First Number: ";
    std::cin >> num1;
    std::cout << "Enter Your Second Number: ";
    std::cin >> num2;
    std::cout << "Enter Operator *, +, -, /, : ";
    std::cin >> op;

    bool valid = true;
    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 == 0) {
                std::cout << "No Division by Zero!\n";
                valid = false;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Enter Correct Operator!\n";
            valid = false;
            break;
    }

    if (valid) {
        std::cout << num1 << " " << op << " " << num2 << " = " << result << std::endl;


        std::stringstream ss;
        ss << num1 << " " << op << " " << num2 << " = " << result;
        calc_history.push_back(ss.str());
    }

    std::cout << "\nContinue[Y/N]: ";
    std::cin >> back;
    if (back == 'Y' || back == 'y') {
        calculator();
    } else {
        system("clear");
        main();
    }
    return 0;
}

void history() {
    std::cout << "\n--- Calculation History ---\n";
    if (calc_history.empty()) {
        std::cout << "No history yet.\n";
    } else {
        for (int i = 0; i < calc_history.size(); i++) {
            std::cout << "[" << i + 1 << "] " << calc_history[i] << std::endl;
        }
    }
    std::cout << "\nPress any key to go back...";
    char temp;
    std::cin >> temp;
    system("clear");
    main();
}

void choice() {
    char c;
    while (true) {
        std::cout << "Do you want to continue? [Y/y or N/n]" << std::endl;
        std::cin >> c;
        if (c == 'Y' || c == 'y')
            calculator();
        else if (c == 'N' || c == 'n') {
            system("clear");
            main();
        }
    }
}
