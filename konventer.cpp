#include <iostream>
#include <iomanip>
#include <limits>
#include <clocale>

using namespace std;

void showMainMenu() {
    wcout << L"\nГлавное меню:\n";
    wcout << L"1. Преобразование длины\n";
    wcout << L"2. Преобразование массы\n";
    wcout << L"3. Преобразование температуры\n";
    wcout << L"4. Выход\n";
    wcout << L"Выберите опцию (1-4): ";
}

void lengthConverter() {
    int choice;
    double value;
    
    wcout << L"\nПреобразование длины:\n";
    wcout << L"1. Метры в километры\n";
    wcout << L"2. Километры в метры\n";
    wcout << L"3. Сантиметры в дюймы\n";
    wcout << L"4. Дюймы в сантиметры\n";
    wcout << L"5. Назад в главное меню\n";
    wcout << L"Выберите опцию (1-5): ";
    cin >> choice;
    
    if (choice == 5) return;
    
    wcout << L"Введите значение: ";
    cin >> value;
    
    switch(choice) {
        case 1:
            wcout << value << L" м = " << value / 1000 << L" км\n";
            break;
        case 2:
            wcout << value << L" км = " << value * 1000 << L" м\n";
            break;
        case 3:
            wcout << value << L" см = " << value / 2.54 << L" дюймов\n";
            break;
        case 4:
            wcout << value << L" дюймов = " << value * 2.54 << L" см\n";
            break;
        default:
            wcout << L"Неверный ввод. Пожалуйста, выберите от 1 до 5.\n";
    }
}


int main() {

    setlocale(LC_ALL, "Russian");
    

    wcout << fixed << setprecision(4);
    
    while (true) {
        int choice;
        showMainMenu();
        cin >> choice;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(choice) {
            case 1:
                lengthConverter();
                break;
            case 2:
                massConverter();
                break;
            case 3:
                temperatureConverter();
                break;
            case 4:
                wcout << L"Выход из программы...\n";
                return 0;
            default:
                wcout << L"Неверный ввод. Пожалуйста, выберите от 1 до 4.\n";
        }
    }
    
    return 0;
}
