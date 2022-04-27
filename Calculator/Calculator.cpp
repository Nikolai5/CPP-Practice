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

bool validateInput(std::string userInput, int whichNumber){
    switch (whichNumber){
        case 1:
            if(num1 = std::stof(userInput)){
                return true;
            } else {
                userError = true;
                return false;
            }
        break;
        case 2:
            if(num2 = std::stof(userInput)){
                return true;
            } else {
                userError = true;
                return false;
            }
        break;
    }

    return false;
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
    if(std::cin >> num1){
        std::cout << "Succ";
    } else {
        userError = true;
        std::cin.ignore('\n'); // need to figure out how to sanitise the stream to get input cleanly.
    }
    std::cout << std::endl;

    updateScreen(true);

    std::cout << "Enter Operator (+, -, *, /) : ";
    std::cin >> operation;
    std::cout << "User Operator: " << operation;
    std::cout << std::endl;

    updateScreen(true);

    std::cout << "Enter Second Number : ";
    std::cin >> inputNum2;
    std::cout << std::endl;

    if(!validateInput(inputNum2, 2)){ // Potentially not needed.
        main();
    }

    calculate() ? updateScreen(true) : updateScreen(false);
    main();    

    return 0;
}