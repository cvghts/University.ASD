/* LB24(3)_Yarosh.cpp : Побудувати хеш-таблицю зі слів довільного текстового файлу, 
задаючи її розмірність з екрану. Вивести побудовану таблицю слів на екран. 
Здійснити пошук введеного слова. Виконати програму для різних розмірностей таблиці 
та порівняти кількість порівнянь. Видалити всі слова, які починаються на вказану літеру, вивести таблицю.*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string filename = "E:\\text.txt"; // шлях до текстового файлу
    ifstream infile(filename);

    if (!infile.is_open()) {
        cerr << "Не вдалося відкрити файл.\n";
        return 1;
    }

    // Введення розміру хеш-таблиці
    int table_size;
    while (true) {
        cout << "Введіть розмір хеш-таблиці: ";
        if (cin >> table_size && table_size > 0) {
            break;
        }
        cin.clear();
    }

    // Читання слів з файлу та побудова хеш-таблиці
    unordered_map<string, int> word_table(table_size);
    string word;
    while (infile >> word) {
        word_table[word]++;
    }

    // Виведення хеш-таблиці на екран
    cout << "\nХеш-таблиця:\n";
    for (const auto& kv : word_table) {
        cout << kv.first << ": " << kv.second << endl;
    }

    // Пошук введеного слова
    string search_word;
    cout << "\nВведіть слово для пошуку: ";
    cin >> search_word;

    if (word_table.count(search_word) == 0) {
        cout << search_word << " не знайдено.\n";
    }
    else {
        cout << search_word << " знайдено " << word_table[search_word] << " разів.\n";
    }

    // Видалення слів, які починаються на вказану літеру
    char start_char;
    cout << "\nВведіть початковий символ для видалення: ";
    cin >> start_char;

    int num_removed = 0;
    for (auto it = word_table.begin(); it != word_table.end();) {
        if (it->first[0] == start_char) {
            it = word_table.erase(it);
            num_removed++;
        }
        else {
            ++it;
        }
    }
    cout << num_removed << " слова видалені.\n";

    // Виведення хеш-таблиці на екран
    cout << "\nХеш-таблиця (після видалення):\n";
    for (const auto& kv : word_table) {
        cout << kv.first << ": " << kv.second << endl;
    }

    return 0;
}
