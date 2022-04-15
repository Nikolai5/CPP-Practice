#include <iostream>
#include <string>

float num1 = 0.0, num2 = 0.0, result = 0.0;
char operation = '+';
bool firstRun = true;
bool userError = false;

void updateScreen(bool valid) {
    for(int i = 0; i < 80; i++){
        std::cout << std::endl;
    }

    if(!valid){
        std::cout << "INVALID INPUT - Please try again." << std::endl;
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
        case '/':
            if(num2 == 0){
                return false;
            }
            result = num1 / num2;
            break;
        default:
            return false;
    }

    return true;
}

int main() {

    std::string inputNum1, inputNum2;

    if(firstRun){
        updateScreen(true);
        firstRun = false;
    } else if (userError){
        updateScreen(false);
        userError = false;
    }
    
    std::cout << "Enter First Number : ";
    std::cin >> inputNum1;
    std::cout << std::endl;

    try {
        num1 = std::stof(inputNum1);
    }
    catch(const std::exception& e) {
        inputNum1 = "0.00";
        userError = true;
        main();
    }

    updateScreen(true);

    std::cout << "Enter Operator (+, -, *, /) : ";
    std::cin >> operation;
    std::cout << "User Operator: " << operation;
    std::cout << std::endl;

    updateScreen(true);

    std::cout << "Enter Second Number : ";
    std::cin >> inputNum2;
    std::cout << std::endl;

    try {
        num2 = std::stof(inputNum2);
    }
    catch(const std::exception& e) {
        inputNum2 = "0.00";
        userError = true;
        main();
    }

    calculate() ? updateScreen(true) : updateScreen(false);
    main();    

    return 0;
}