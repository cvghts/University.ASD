/* LB24(2)_Yarosh.cpp : Скласти хеш - таблицю, яка містить букви та кількість 
їх входження в уведеному рядку.Вивести таблицю на екран.Здійснити пошук введеної букви в хеш - таблиці*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string input_str;
    cout << "Введіть рядок: ";
    getline(cin, input_str);

    unordered_map<char, int> char_count_map;
    for (char c : input_str) {
        if (char_count_map.count(c) == 0) {
            char_count_map[c] = 1;
        }
        else {
            char_count_map[c]++;
        }
    }

    cout << "Таблиця частоти символів:" << endl;
    for (const auto& pair : char_count_map) {
        cout << pair.first << " : " << pair.second << endl;
    }

    char search_char;
    cout << "Введіть символ для пошуку: ";
    cin >> search_char;

    if (char_count_map.count(search_char) == 0) {
        cout << search_char << " не знайдено в рядку." << endl;
    }
    else {
        cout << search_char << " знайдено в рядку " << char_count_map[search_char] << " разів." << endl;
    }

    return 0;
}
