/* LB24(1)_Yarosh.cpp : Створіть хеш-таблицю з  електроних пошт у форматі xxxxxxxx@gmail.com.
Відкрите хешування. Хеш-функція повинна прагнути до оптимальної.
Визначте найкращий і найгірший варіант розподілу елементів.*/

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// Хеш-функція
int hashFunction(string email, int tableSize) {
    int hash = 0;
    for (int i = 0; i < email.length(); i++) {
        hash += email[i];
    }
    return hash % tableSize;
}

// Структура електронної пошти
struct Email {
    string address;
    string name;
};

// Клас хеш-таблиці
class HashTable {
private:
    int size; // Розмір таблиці
    vector<Email>* table; // Вказівник на масив списків елементів
public:
    HashTable(int size) {
        this->size = size;
        table = new vector<Email>[size];
    }

    // Вставка елемента
    void insert(Email email) {
        int index = hashFunction(email.address, size);
        table[index].push_back(email);
    }

    // Виведення таблиці
    void printTable() {
        for (int i = 0; i < size; i++) {
            cout << "Індекс " << i << ": ";
            for (int j = 0; j < table[i].size(); j++) {
                cout << "(" << table[i][j].address << ", " << table[i][j].name << ") ";
            }
            cout << endl;
        }
    }

    // Найкращий варіант розподілу елементів
    int bestDistribution() {
        int min = table[0].size();
        for (int i = 1; i < size; i++) {
            if (table[i].size() < min) {
                min = table[i].size();
            }
        }
        return min;
    }

    // Найгірший варіант розподілу елементів
    int worstDistribution() {
        int max = table[0].size();
        for (int i = 1; i < size; i++) {
            if (table[i].size() > max) {
                max = table[i].size();
            }
        }
        return max;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Створення хеш-таблиці
    HashTable emailTable(10);

    // Введення даних в таблицю
    int numEntries;
    cout << "Введіть кількість записів електронної пошти: ";
    cin >> numEntries;

    for (int i = 0; i < numEntries; i++) {
        string address, name;
        cout << "Введіть електронну адресу: ";
        cin >> address;
        cout << "Введіть ім'я: ";
        cin >> name;

        emailTable.insert({ address, name });
    }

    // Виведення таблиці
    emailTable.printTable();

    // Виведення найкращого та найгіршого варіантів розподілу елементів
    cout << "Найкращий розподіл: " << emailTable.bestDistribution() << "%" << endl;
    cout << "Найгірший розподіл: " << emailTable.worstDistribution() << "%" << endl;
    return 0;
}
