/* LB16(2)_Yarosh.cpp : Скласти програму визначення часу виконання процедури сортування
при різній вимірності масиву (n=100, 300, 500, 1000, 1500, 2000, 3000, 4000, 5000,
6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 50000,
60000, 70000, 80000, 90000, 100000). Передбачити заповнення масиву
випадковими числами у діапазоні від 1 до n включно. Вимірювання часу для
одного масиву проводити п’ять разів (передбачити, щоб масив не змінювався!).
Остаточний час визначати як середній.*/

#include <iostream>
#include <ctime> //бібліотека часу
#include <random>
#include <algorithm>
using namespace std;

//Функція створення масиву
void createArray(int* arr, int n) {
    random_device rd; //об'єкт для отримання випадкового числа з апаратного джерела
    mt19937 gen(rd()); //генератор псевдовипадкових чисел
    uniform_int_distribution<int> distrib(0, n); // рівномірний розподіл на інтервалі [0, n]
    generate(arr, arr + n, [&]() { return distrib(gen); }); //генеруємо n випадкових чисел і зберігаємо в масиві arr
}

//Функція для сортування методом бульбашки
void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//Функція визначення часу сортування
double measureOnce(int* arr, int n) {
    clock_t start = clock();
    bubble_sort(arr, n);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC; //повертаємо час виконання сортування в секундах
}

//Вивід результату після сортування
void measureAndPrint(int n) {
    int* arr = new int[n];
    createArray(arr, n);
    double mean = 0;
    for (int i = 0; i < 5; i++) {
        mean += measureOnce(arr, n);
    }
    mean /= 5;
    cout << "Mean time of sorting array of " << n << " elements = " << mean << endl;
    delete[] arr;
}

int main() {
    int ns[] = { 100, 300, 500, 1000, 1500, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000,
                15000, 20000, 25000, 30000, 35000, 40000, 50000, 60000, 70000, 80000, 90000, 100000 };
    int num_ns = sizeof(ns) / sizeof(ns[0]);
    for (int i = 0; i < num_ns; i++) {
        measureAndPrint(ns[i]);
    }
    return 0;
}

//Мінімальний час сортування масиву на 100000 рандомних елемениів методом bubble sort: 28.1052 секунди, максимальний 32.1055 секунди
