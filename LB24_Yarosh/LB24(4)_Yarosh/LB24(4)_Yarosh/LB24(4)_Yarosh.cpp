/* LB24(4)_Yarosh.cpp : Побудувати хеш - таблицю для зарезервованих слів певної мови програмування(не менше 20 слів), 
яка містить HELP для кожного слова.Вивести на екран підказку по введеному слову.
Додати підказку для нового введеного слова, використовуючи за потреби реструктуризацію таблиці.
Порівняти ефективність додавання ключа в таблицю або її реструктуризацію для різної степені наповненості таблиці.*/


#include <iostream>
#include <string>
#include <unordered_map>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::unordered_map<std::string, std::string> reservedWords;
    // додати зарезервовані слова і відповідні підказки
    reservedWords.emplace("if", "перевірка умови");
    reservedWords.emplace("else", "умовний оператор else");
    reservedWords.emplace("while", "цикл while");
    reservedWords.emplace("for", "цикл for");
    reservedWords.emplace("int", "ціле число");
    reservedWords.emplace("double", "дійсне число подвійної точності");
    reservedWords.emplace("float", "дійсне число одинарної точності");
    reservedWords.emplace("char", "символьний тип даних");
    reservedWords.emplace("bool", "логічний тип даних");
    reservedWords.emplace("const", "константа");
    reservedWords.emplace("void", "пусте значення");
    reservedWords.emplace("auto", "автоматичний тип даних");
    reservedWords.emplace("typedef", "визначення нового типу даних");
    reservedWords.emplace("struct", "структура даних");
    reservedWords.emplace("break", "вихід із циклу");
    reservedWords.emplace("case", "випадок у switch-блоку");
    reservedWords.emplace("continue", "пропуск ітерації у циклі");
    reservedWords.emplace("default", "значення за замовчуванням у switch-блоку");
    reservedWords.emplace("return", "повернення значення з функції");
    reservedWords.emplace("switch", "багатовипадковий оператор");

    std::string input;
    std::cout << "Введіть зарезервоване слово: ";
    std::cin >> input;

    // знайти підказку для введеного слова
    auto hint = reservedWords.find(input);
    if (hint == reservedWords.end()) {
        std::cout << "Підказки для цього слова немає. Введіть підказку для цього слова: ";
        std::string newHint;
        std::cin >> newHint;
        reservedWords.emplace(input, newHint);
    }
    else {
        std::cout << "Підказка: " << hint->second << std::endl;
    }

    return 0;
}

