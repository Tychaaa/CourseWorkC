#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Hello, World!" << endl;
    cout << "Привет, Мир!" << endl;
    return 0;
}