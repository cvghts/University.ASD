/* LB21(1)_Yarosh.cpp : 2. Реалізувати програмний пошук певного значення в масиві 
засобами різних алгоритмів пошуку ключа в масиві :
1. лінійного;
2. рекурсивного та нерекурсивного бінарного;
3. експонентного;
4. інтерполяційного.
Для кожного з алгоритмів програмно 
згенерувати однакові масиви з 20 - ти цілих елементів.
Для бінарного, експонентного та інтерполяційного пошуку попередньо 
відсортувати відповідні масиви(або ввести 20 елементів, які відсортовані за зростанням).
Для кожного алгоритму програмно визначити кількість ітерацій та порівнянь*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <Windows.h>

using namespace std;

// Лінійний пошук
int linearSearch(int arr[], int n, int x, int& iterations, int& comparisons) {
    int i;
    for (i = 0; i < n; i++) {
        iterations++;
        if (arr[i] == x) {
            comparisons++;
            return i;
        }
        comparisons++;
    }
    return -1;
}

// Рекурсивний бінарний пошук
int recursiveBinarySearch(int arr[], int l, int r, int x, int& iterations, int& comparisons) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        iterations++;
        if (arr[mid] == x) {
            comparisons++;
            return mid;
        }
        if (arr[mid] > x) {
            comparisons++;
            return recursiveBinarySearch(arr, l, mid - 1, x, ++iterations, comparisons);
        }
        comparisons++;
        return recursiveBinarySearch(arr, mid + 1, r, x, ++iterations, comparisons);
    }
    return -1;
}

// Нерекурсивний бінарний пошук
int iterativeBinarySearch(int arr[], int n, int x, int d, int& iterations, int& comparisons) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        iterations++;
        if (arr[mid] == x) {
            comparisons++;
            return mid;
        }
        if (arr[mid] < x) {
            comparisons++;
            l = mid + 1;
        }
        else {
            comparisons++;
            r = mid - 1;
        }
    }
    return -1;
}

// Експонентний пошук
int exponentialSearch(int arr[], int n, int x, int& iterations, int& comparisons) {
    if (arr[0] == x) {
        comparisons++;
        return 0;
    }
    int i = 1;
    while (i < n && arr[i] <= x) {
        iterations++;
        comparisons++;
        i *= 2;
    }
    return recursiveBinarySearch(arr, i / 2, min(i, n - 1), x, ++iterations, comparisons);
}

// Інтерполяційний пошук
int interpolationSearch(int arr[], int n, int x, int& iterations, int& comparisons) {
    int lo = 0, hi = (n - 1);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (lo == hi) {
            iterations++;
            if (arr[lo] == x) {
                comparisons++;
                return lo;
            }
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        iterations++;
        if (arr[pos] == x) {
            comparisons++;
            return pos;
        }
        if (arr[pos] < x) {
            comparisons++;
            lo = pos + 1;
        }
        else if (arr[pos] > x) {
            comparisons++;
            hi = pos - 1;
        }
        else {
            comparisons++;
            return pos;
        }
    }
    return -1;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Генеруємо масив з 20 цілих елементів
    int arr[20];
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 100;
    }

    // Сортуємо масив для бінарного, експонентного та інтерполяційного пошуку
    sort(arr, arr + 20);

    cout << "Масив: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Пошук числа 42 з використанням кожного з алгоритмів пошуку
    int x = 42;
    int iterations, comparisons;

    // Лінійний пошук
    iterations = 0;
    comparisons = 0;
    int linearIndex = linearSearch(arr, 20, x, iterations, comparisons);
    if (linearIndex != -1) {
        cout << "Лінійний пошук: знайдено на позиції " << linearIndex << endl;
    }
    else {
        cout << "Лінійний пошук: не знайдено" << endl;
    }
    cout << "Кількість ітерацій: " << iterations << endl;
    cout << "Кількість порівнянь: " << comparisons << endl;

    // Рекурсивний бінарний пошук
    iterations = 0;
    comparisons = 0;
    int recursiveBinaryIndex = recursiveBinarySearch(arr, 0, 19, x, iterations, comparisons);
    if (recursiveBinaryIndex != -1) {
        cout << "Рекурсивний бінарний пошук: знайдено на позиції " << recursiveBinaryIndex << endl;
    }
    else {
        cout << "Рекурсивний бінарний пошук: не знайдено" << endl;
    }
    cout << "Кількість ітерацій: " << iterations << endl;
    cout << "Кількість порівнянь: " << comparisons << endl;

    // Нерекурсивний бінарний пошук
    iterations = 0;
    comparisons = 0;
    int iterativeBinaryIndex = iterativeBinarySearch(arr, 0, 19, x, iterations, comparisons);
    if (iterativeBinaryIndex != -1) {
        cout << "Нерекурсивний бінарний пошук: знайдено на позиції " << iterativeBinaryIndex << endl;
    }
    else {
        cout << "Нерекурсивний бінарний пошук: не знайдено" << endl;
    }
    cout << "Кількість ітерацій: " << iterations << endl;
    cout << "Кількість порівнянь: " << comparisons << endl;
    // Експонентний пошук
    iterations = 0;
    comparisons = 0;
    int exponentialIndex = exponentialSearch(arr, 20, x, iterations, comparisons);
    if (exponentialIndex != -1) {
        cout << "Експонентний пошук: знайдено на позиції " << exponentialIndex << endl;
    }
    else {
        cout << "Експонентний пошук: не знайдено" << endl;
    }
    cout << "Кількість ітерацій: " << iterations << endl;
    cout << "Кількість порівнянь: " << comparisons << endl;

    // Інтерполяційний пошук
    iterations = 0;
    comparisons = 0;
    int interpolationIndex = interpolationSearch(arr, 20, x, iterations, comparisons);
    if (interpolationIndex != -1) {
        cout << "Інтерполяційний пошук: знайдено на позиції " << interpolationIndex << endl;
    }
    else {
        cout << "Інтерполяційний пошук: не знайдено" << endl;
    }
    cout << "Кількість ітерацій: " << iterations << endl;
    cout << "Кількість порівнянь: " << comparisons << endl;

    return 0;
}
