#include <iostream>
#include <string>

float num1 = 0.0, num2 = 0.0, result = 0.0;
char operation = '+';
bool firstRun = true;

void updateScreen(bool valid) {
    std::cout << std::string(100, '\n');

    if(!valid){
        std::cout << "INVALID ENTRY - Please try again." << std::endl;
    }

    std::cout << "--- Calculator App ---" << std::endl;
    std::cout << "[  " << num1 << "  ]  " << operation << "  [  " << num2 << "  ]" << std::endl << std::endl;
    std::cout << "Result:  " << result << std::endl << std::endl;

    return;
}

bool calculate(){
    switch(operation) {
        case '+': 
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*': case 'x':
            result = num1 * num2;
            break;
        default:
            return false;
    }

    return true;
}

int main() {
    
    if(firstRun){
        updateScreen(true);
        firstRun = false;
    }
    std::cout << "Enter First Number : ";
    std::cin >> num1;
    std::cout << std::endl;

    updateScreen(true);

    std::cout << "Enter Operator (+, -, *) : ";
    std::cin >> operation;
    std::cout << "User Operator: " << operation;
    std::cout << std::endl;

    updateScreen(true);

    std::cout << "Enter Second Number : ";
    std::cin >> num2;
    std::cout << std::endl;

    calculate() ? updateScreen(true) : updateScreen(false);
    main();

    return 0;
}