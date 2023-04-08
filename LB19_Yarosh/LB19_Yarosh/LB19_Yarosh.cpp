/*LB19_Yarosh.cpp : Для кожного алгоритму розробити програму сортування масивів
випадкових чисел не менше 1000 елементів, де визначити кількість
ітерацій, кількість порівнянь і кількість присвоювань та визначити час
виконання кожним з алгоритмів та їх варіантів. (вставками (3 варіанти: простими вставками, па́рне сортування
простими вставками, простими вставками з бінарним пошуком) та Шелла)*/

#include <iostream>
#include <chrono>
#include <algorithm>
#include<Windows.h>
using namespace std;
using namespace std::chrono;

//Функція для сортування простими вставками
void insertionSort(int arr[], int n)
{
    int i, j, key, comp = 0, swap = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Порівнюємо елемент зі всіма попередніми елементами,
        // щоб знайти його відповідне місце у відсортованій частині масиву
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comp++;
            swap++;
        }
        arr[j + 1] = key;
        swap++;
    }
    cout << "Прості вставки: ітерацій - " << n - 1 << ", порівнянь - " << comp << ", присвоєнь - " << swap << endl;
}

//Функція для парного сортування простими вставками
void oddEvenInsertionSort(int arr[], int n)
{
    int i, j, key, comp = 0, swap = 0;

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (j = 2; j < n; j += 2) {
                // Порівнюємо елементи з парними індексами, обмінюємо їх,
                // якщо вони не відсортовані
                if (arr[j] < arr[j - 1]) {
                    key = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = key;
                    swap++;
                }
                comp++;
            }
        }
        else {
            for (j = 1; j < n; j += 2) {
                // Порівнюємо елементи з непарними індексами, обмінюємо їх,
                // якщо вони не відсортовані
                if (arr[j] < arr[j - 1]) {
                    key = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = key;
                    swap++;
                }
                comp++;
            }
        }
    }
    cout << "Парне сортування простими вставками: ітерацій - " << n - 1 << ", порівнянь - " << comp << ", присвоєнь - " << swap << endl;
}

//Функція сортування простими вставками з бінарним пошуком
void binaryInsertionSort(int arr[], int n)
{
    int i, j, key, comp = 0, swap = 0;
    int left, right, mid;

    for (i = 1; i < n; i++) {
        key = arr[i];
        /*Функція upper_bound повертає ітератор на перший елемент відсортованого підмасиву,
        який є більшим, ніж key.Віднімаємо ітератор на початок масиву arr, щоб отримати позицію цього елемента в масиві.*/
        int pos = upper_bound(arr, arr + i, key) - arr;
        for (int j = i - 1; j >= pos; j--) {
            arr[j + 1] = arr[j];
            comp++;
            swap++;
        }

        swap++;
        arr[pos] = key;
    }

cout << "Прості вставки з бінарним пошуком: ітерацій - " << n - 1 << ", порівнянь - " << comp << ", присвоєнь - " << swap << endl;
}

//Шелла
void shellSort(int arr[], int n)
{
    int i, j, gap, key, comp = 0, swap = 0;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            key = arr[i];
            for (j = i; j >= gap && arr[j - gap] > key; j -= gap) {
                arr[j] = arr[j - gap];
                comp++;
                swap++;
            }
            arr[j] = key;
            swap++;
        }
    }
    cout << "Шелла: ітерацій - " << gap << ", порівнянь - " << comp << ", присвоєнь - " << swap << endl;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int n = 1000;
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    auto start = high_resolution_clock::now();
    insertionSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Час виконання простих вставок: " << duration.count() << " мікросекунд" << endl;

    start = high_resolution_clock::now();
    oddEvenInsertionSort(arr, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Час виконання парного сортування простими вставками: " << duration.count() << " мікросекунд" << endl;

    start = high_resolution_clock::now();
    binaryInsertionSort(arr, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Час виконання простих вставок з бінарним пошуком: " << duration.count() << " мікросекунд" << endl;

    start = high_resolution_clock::now();
    shellSort(arr, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Час виконання Шелла: " << duration.count() << " мікросекунд" << endl;
    return 0;
}