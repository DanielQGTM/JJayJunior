#include "Calc.h"
#include <ctime>
#include <cstdlib>

int main()
{

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 10; i++)
    {
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;

        std::cout << "First number is: " << num1 << std::endl;
        std::cout << "Second number is: " << num2 << std::endl;

        Calc value1(num1);
        Calc value2(num2);

        int randomOperation = rand() % 4;
        char operation;
        switch (randomOperation)
        {
        case 0:
            operation = '+';
            break;
        case 1:
            operation = '-';
            break;
        case 2:
            operation = '*';
            break;
        case 3:
            operation = '/';
            break;
        }
        switch (operation)
        {
        case '+':
            std::cout << value1.getValue() << " + " << value2.getValue()
                      << " = " << (value1 + value2).getValue() << std::endl;
            break;
        case '-':
            std::cout << value1.getValue() << " - " << value2.getValue()
                      << " = " << (value1 - value2).getValue() << std::endl;
            break;
        case '*':
            std::cout << value1.getValue() << " * " << value2.getValue()
                      << " = " << (value1 * value2).getValue() << std::endl;
            break;
        case '/':
            if (value1.getValue() != 0 || value2.getValue())
            {
                std::cout << value1.getValue() << " / " << value2.getValue()
                          << " = " << (value1 / value2).getValue() << std::endl;
            }
            else
            {
                std::cout << "Division by zero is not allowed." << std::endl;
            }
            break;
        }
        std::cout << std::endl;
    };

    return 0;
}