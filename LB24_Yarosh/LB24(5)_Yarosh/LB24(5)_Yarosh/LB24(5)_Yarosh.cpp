/* LB24(5)_Yarosh.cpp : В текстовому файлі містяться цілі числа. Побудувати хеш-таблицю з чисел файлу. 
Здійснити пошук введеного цілого числа в хеш-таблиці. 
Порівняти результати кількості порівнянь для різних наборів даних в файлі.*/

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // відкриваємо файл для зчитування
    ifstream infile("E:\\text1.txt");
    if (!infile.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    // створюємо хеш-таблицю та заповнюємо її числами з файлу
    unordered_set<int> numbers;
    int num;
    while (infile >> num) {
        numbers.insert(num);
    }

    // запитуємо користувача на введення числа та шукаємо його в хеш-таблиці
    int search_num;
    while (true) {
        cout << "Введіть число для пошуку: ";
        cin >> search_num;

        if (numbers.count(search_num)) {
            cout << "Число " << search_num << " знайдено!" << endl;
        }
        else {
            cout << "Число " << search_num << " не знайдено!" << endl;
        }

        // запитуємо користувача, чи продовжувати пошук
        cout << "Продовжити пошук? (y/n): ";
        char ans;
        cin >> ans;
        if (ans == 'n' || ans == 'N') {
            break;
        }
    }

    return 0;
}