/* LB22_Yarosh.cpp : Реалізувати програмний пошук певного підрядка в рядку засобами різних алгоритмів пошуку:
1. послідовного;
2. Кнута-Морріса-Пратта;
3. Бойера-Мура.
Для кожного з алгоритмів програмно організувати пошук
в одному і тому самому рядку. Для кожного алгоритму програмно визначити кількість ітерацій та порівнянь */

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// Алгоритм послідовного пошуку
int sequentialSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int countIterations = 0;
    int countComparisons = 0;

    for (int i = 0; i <= n - m; i++) {
        bool found = true;
        for (int j = 0; j < m; j++) {
            countIterations++;
            countComparisons++;
            if (text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return -1;
}

// Алгоритм Кнута-Морріса-Пратта
int kmpSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int countIterations = 0;
    int countComparisons = 0;

    int* lps = new int[m];
    lps[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++) {
        countIterations++;
        while (j > 0 && pattern[j] != pattern[i]) {
            countIterations++;
            j = lps[j - 1];
        }
        countIterations++;
        if (pattern[j] == pattern[i]) {
            j++;
        }
        lps[i] = j;
    }

    j = 0;
    for (int i = 0; i < n; i++) {
        countIterations++;
        while (j > 0 && pattern[j] != text[i]) {
            countIterations++;
            j = lps[j - 1];
        }
        countIterations++;
        if (pattern[j] == text[i]) {
            j++;
        }
        if (j == m) {
            delete[] lps;
            return i - m + 1;
        }
    }
    delete[] lps;
    return -1;
}

// Алгоритм Бойера-Мура
int boyerMooreSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int countIterations = 0;
    int countComparisons = 0;

    int* skip = new int[256];
    for (int i = 0; i < 256; i++) {
        skip[i] = m;
    }
    for (int i = 0; i < m - 1; i++) {
        skip[pattern[i]] = m - i - 1;
    }

    int i = m - 1;
    while (i < n) {
        int k = i;
        int j = m - 1;
        while (j >= 0 && text[k] == pattern[j]) {
            countIterations++;
            countComparisons++;
            k--;
            j--;
        }
        if (j < 0) {
            delete[] skip;
            return k + 1;
        }
        countIterations++;
        i += skip[text[i]];
    }
    delete[] skip;
    return -1;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string text = "ababababcababababac";
    string pattern = "abac";
    int pos;
    // Пошук методом послідовного перебору
    pos = sequentialSearch(text, pattern);
    if (pos == -1) {
        cout << "Підрядок не знайдено" << endl;
    }
    else {
        cout << "Підрядок знайдено на позиції " << pos << endl;
    }

    // Пошук методом Кнута-Морріса-Пратта
    pos = kmpSearch(text, pattern);
    if (pos == -1) {
        cout << "Підрядок не знайдено" << endl;
    }
    else {
        cout << "Підрядок знайдено на позиції " << pos << endl;
    }

    // Пошук методом Бойера-Мура
    pos = boyerMooreSearch(text, pattern);
    if (pos == -1) {
        cout << "Підрядок не знайдено" << endl;
    }
    else {
        cout << "Підрядок знайдено на позиції " << pos << endl;
    }

    return 0;
}