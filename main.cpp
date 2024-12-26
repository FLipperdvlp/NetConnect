#include <iostream>
#include <iomanip>  // Для форматирования вывода

// ***************************************************
//                 NetConnect
// ***************************************************
// Лицензия: MIT License
// Автор: Gleb
// Платформа: Windows/Linux/macOS
// Язык программирования: C++
// ***************************************************

void printBanner() {
    std::cout << "**********************************************" << std::endl;
    std::cout << "*             NetConnect                    *" << std::endl;
    std::cout << "*             MIT License                   *" << std::endl;
    std::cout << "*             Автор: Gleb                   *" << std::endl;
    std::cout << "*             Платформа: Windows/Linux/macOS*" << std::endl;
    std::cout << "*             Язык: C++                     *" << std::endl;
    std::cout << "**********************************************" << std::endl;
}

int main() {
    printBanner();
    
    std::cout << std::endl;
    std::cout << "Привет, мир!" << std::endl;
    std::cout << "Добро пожаловать в проект Connect++!" << std::endl;

    return 0;
}
