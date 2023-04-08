/* LB18(1)_Yarosh.cpp : Для кожного алгоритму розробити програму сортування масивів
випадкових чисел не менше 1000 елементів, де визначити кількість
ітерацій, кількість порівнянь і кількість присвоювань та визначити час
виконання кожним з алгоритмів та їх варіантів. (Вибору та бульбашки (3 варіанти))*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <Windows.h>
using namespace std;

//Функція для сортування масиву методом вибору
void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    int comparisons = 0, assignments = 0, iterations = 0;
    for (i = 0; i < n - 1; i++) { //проходить по масиву від початку до передостаннього елемента.
        minIndex = i; //встановлюється на поточну позицію
        for (j = i + 1; j < n; j++) { //проходиться по масиву починаючи з наступної позиції
            iterations++;
            if (arr[j] < arr[minIndex]) {
                comparisons++;
                minIndex = j;
            }
        }
        //чи позиція мінімального елемента не дорівнює поточній позиції
        if (minIndex != i) {
            assignments += 3;
            swap(arr[i], arr[minIndex]);
        }
    }
    cout << "Сортування вибору:" << endl;
    cout << "Відсортований масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Ітерації: " << iterations << endl;
    cout << "Порівняння: " << comparisons << endl;
    cout << "Присвоювання: " << assignments << endl;
}

//Функція сортування бульбашкою з додатковою оптимізацією, яка полягає в перевірці, чи відбувалося обмін значень під час ітерації зовнішнього циклу
void bubbleSort1(int arr[], int n) {
    /*Замість того, щоб проходити по всій невідсортованій частині масиву в кожній ітерації зовнішнього циклу,
    цей алгоритм преривається, якщо в даній ітерації не відбулося жодного обміну,
    оскільки це означає, що масив вже відсортований.*/
    int i, j;
    int comparisons = 0, assignments = 0, iterations = 0;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            iterations++;
            if (arr[j] > arr[j + 1]) {
                comparisons++;
                assignments += 3;
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    cout << "Сортування бульбашкою варіант 1:" << endl;
    cout << "Відсортований масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Ітерації: " << iterations << endl;
    cout << "Порівняння: " << comparisons << endl;
    cout << "Присвоювання: " << assignments << endl;
}

//Функція сортування бульбашкою з оптимізацією "розмежовування останнього обміну"
void bubbleSort2(int arr[], int n) {
/*На кожній ітерації зовнішнього циклу внутрішній цикл проходить від початку до lastSwapIndex,
переставляючи місцями сусідні елементи якщо потрібно.
Після завершення внутрішнього циклу, останній індекс обміну зберігається в змінній swapIndex.
У наступній ітерації зовнішнього циклу, внутрішній цикл проходить від початку до swapIndex,
тобто до останнього місця де стався обмін на попередній ітерації.
Таким чином, зайві порівняння та обміни зменшуються, оскільки відсортовані елементи залишаються 
на своїх місцях, але маємо додаткове присвоєння для swapIndex.
*/
    int i, j;
    int comparisons = 0, assignments = 0, iterations = 0;
    int lastSwapIndex = n - 1; //зберігає індекс останнього обміну  який стався в попередній ітерації зовнішнього циклу
    while (lastSwapIndex > 0) {
        int swapIndex = 0;
        for (j = 0; j < lastSwapIndex; j++) {
            iterations++;
            if (arr[j] > arr[j + 1]) {
                comparisons++;
                assignments += 3;
                swap(arr[j], arr[j + 1]);
                swapIndex = j;
            }
        }
        lastSwapIndex = swapIndex;
    }
    cout << "Сортування бульбашкою варіант 2:" << endl;
    cout << "Відсортований масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Ітерації: " << iterations << endl;
    cout << "Порівняння: " << comparisons << endl;
    cout << "Присвоювання: " << assignments << endl;
}

//Функція сортування бульбашкою, яка має оптимізації, щоб зменшити кількість порівнянь та ітерацій
void bubbleSort3(int arr[], int n) {
    int i, j;
    int comparisons = 0, assignments = 0, iterations = 0;
    bool swapped;
    int start = 0, end = n - 1;
    while (start < end) {
        swapped = false;
        for (j = start; j < end; j++) {
            iterations++;
            if (arr[j] > arr[j + 1]) {
                comparisons++;
                assignments += 3;
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        end--;
        if (!swapped) {
            break;
        }
        swapped = false;
        for (j = end; j > start; j--) {
            iterations++;
            if (arr[j] < arr[j - 1]) {
                comparisons++;
                assignments += 3;
                swap(arr[j], arr[j - 1]);
                swapped = true;
            }
        }
        start++;
        if (!swapped) {
            break;
        }
    }
    cout << "Сортування бульбашкою варіант 3:" << endl;
    cout << "Відсортований масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Ітерації: " << iterations << endl;
    cout << "Порівняння: " << comparisons << endl;
    cout << "Присвоювання: " << assignments << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int n = 1000;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    auto start = chrono::high_resolution_clock::now();
    selectionSort(arr, n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Час, витрачений на сортування вибору: " << duration.count() << " мікросекунди" << endl << endl;

    start = chrono::high_resolution_clock::now();
    bubbleSort1(arr, n);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Час, витрачений на варіант бульбашкового сортування 1: " << duration.count() << " мікросекунди" << endl << endl;

    start = chrono::high_resolution_clock::now();
    bubbleSort2(arr, n);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Час, витрачений на варіант бульбашкового сортування 2: " << duration.count() << " мікросекунди" << endl << endl;

    start = chrono::high_resolution_clock::now();
    bubbleSort3(arr, n);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Час, витрачений на варіант бульбашкового сортування 3: " << duration.count() << " мікросекунди" << endl << endl;
    return 0;
}
