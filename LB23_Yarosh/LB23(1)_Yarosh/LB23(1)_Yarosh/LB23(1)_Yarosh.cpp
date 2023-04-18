/* LB23(1)_Yarosh.cpp : 1.	Створити алгоритм пошуку елементів у масиві А, які більше 30, 
використовуючи методи лінійного, лінійного з бар'єром та бінарного пошуку. 
Обчислити часову складність алгоритмів та зробити їх порівняльну оцінку*/

#include <iostream>
#include <vector>
#include <chrono>
#include <Windows.h>
using namespace std::chrono;

//лінійний пошук
std::vector<int> linear_search(std::vector<int> array) {
    std::vector<int> result;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > 30) {
            result.push_back(array[i]);
        }
    }
    return result;
}

//лінійний з бар'єром пошук
std::vector<int> linear_with_barrier_search(std::vector<int> array) {
    std::vector<int> result;
    int last = array[array.size() - 1];
    array[array.size() - 1] = 30;
    int i = 0;
    while (array[i] <= 30) {
        i++;
    }
    array[array.size() - 1] = last;
    for (int j = i; j < array.size(); j++) {
        if (array[j] > 30) {
            result.push_back(array[j]);
        }
    }
    return result;
}

//бінарний пошук
std::vector<int> binary_search(std::vector<int> array) {
    std::vector<int> result;
    int low = 0, high = array.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] > 30) {
            for (int i = mid; i < array.size(); i++) {
                result.push_back(array[i]);
            }
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::vector<int> array = { 1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };

    auto start = high_resolution_clock::now();
    std::vector<int> linear_result = linear_search(array);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Лінійний пошук: ";
    for (int i = 0; i < linear_result.size(); i++) {
        std::cout << linear_result[i] << " ";
    }
    std::cout << "(" << duration.count() << " мікросекунд)" << std::endl;

    start = high_resolution_clock::now();
    std::vector<int> linear_with_barrier_result = linear_with_barrier_search(array);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Лінійний пошук з бар'єром: ";
    for (int i = 0; i < linear_with_barrier_result.size(); i++) {
        std::cout << linear_with_barrier_result[i] << " ";
    }
    std::cout << "(" << duration.count() << " мікросекунд)" << std::endl;

    start = high_resolution_clock::now();
    std::vector<int> binary_result = binary_search(array);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Бінарний пошук: ";
    for (int i = 0; i < binary_result.size(); i++) {
        std::cout << binary_result[i] << " ";
    }
    std::cout << "(" << duration.count() << " мікросекунд)" << std::endl;

    return 0;
}