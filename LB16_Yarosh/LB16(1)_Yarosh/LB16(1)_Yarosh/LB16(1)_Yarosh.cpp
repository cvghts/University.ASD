// LB16(1)_Yarosh.cpp : Перевірити, чи є введений рядок паліндромом.

#include <iostream>
#include <string>
#include <cctype> //для регістру
using namespace std;

//функція для переведення всіх символів рядка в нижній регістр
void toLowerCase(string& str) {
    for (char& c : str) {
        c = tolower(c);
    }
}

//рекурсивна функція для визначення, чи є рядок паліндромом
bool isPalindrome(string str, int start, int end) {
    //коли рядок має 0 або 1 символ
    if (start >= end) {
        return true;
    }

    //ігноруємо пробіли і перетворюємо символи на нижній регістр
    char leftChar = str[start];
    if (isspace(leftChar)) {
        return isPalindrome(str, start + 1, end);
    }
    tolower(leftChar);

    char rightChar = str[end];
    if (isspace(rightChar)) {
        return isPalindrome(str, start, end - 1);
    }
    tolower(rightChar);

    //порівнюємо перший та останній символи
    if (leftChar != rightChar) {
        return false;
    }
    else {
        return isPalindrome(str, start + 1, end - 1);
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    toLowerCase(str);

    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << "The string is a palindrome." << endl;
    }
    else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}

//Madam Im Adam