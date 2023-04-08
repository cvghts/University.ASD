/* LB20_Yarosh.cpp : Для кожного алгоритму (злиттям і швидке) розробити програму сортування масивів
випадкових чисел не менше 1000 елементів, де визначити кількість
ітерацій, кількість порівнянь і кількість присвоювань та визначити час
виконання кожним з алгоритмів та їх варіантів*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

void merge(int* arr, int l, int m, int r, int& comparisons, int& assignments) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        assignments++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        assignments++;
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
        assignments++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        assignments++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        assignments++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int* arr, int l, int r, int& comparisons, int& assignments) {
    if (l >= r) {
        return;
    }
    int m = (l + r - 1) / 2;
    mergeSort(arr, l, m, comparisons, assignments);
    mergeSort(arr, m + 1, r, comparisons, assignments);
    merge(arr, l, m, r, comparisons, assignments);
}

int partition(int* arr, int low, int high, int& comparisons, int& assignments) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            assignments += 3;
        }
    }

    swap(arr[i + 1], arr[high]);
    assignments += 3;
    return (i + 1);
}

void quickSort(int* arr, int low, int high, int& comparisons, int& assignments) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, assignments);
        quickSort(arr, low, pi - 1, comparisons, assignments);
        quickSort(arr, pi + 1, high, comparisons, assignments);
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(nullptr));
    const int n = 1000;
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 1000;
        arr2[i] = arr1[i];
    }

    int comparisons = 0;
    int assignments = 0;
    clock_t start = clock();
    mergeSort(arr1, 0, n - 1, comparisons, assignments);
    clock_t end = clock();
    double time1 = (double)(end - start) / CLOCKS_PER_SEC;

    comparisons = 0;
    assignments = 0;
    start = clock();
    quickSort(arr2, 0, n - 1, comparisons, assignments);
    end = clock();
    double time2 = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Сортування злиттям:" << endl;
    cout << "Час: " << time1 << endl;
    cout << "Порівняння: " << comparisons << endl;
    cout << "Присвоювання: " << assignments << endl;

    cout << endl;

    cout << "Швидке сортування:" << endl;
    cout << "Час: " << time2 << endl;
    cout << "Порівняння: " << comparisons << endl;
    cout << "Присвоювання: " << assignments << endl;

    return 0;
}
