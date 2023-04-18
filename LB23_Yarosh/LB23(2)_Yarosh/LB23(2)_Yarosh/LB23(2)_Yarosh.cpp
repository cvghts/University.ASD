/* LB23(2)_Yarosh.cpp : 2.	Використовуючи алгоритм пошуку даних у масиві зі змінним фактором
зменшення, провести аналіз часової складності алгоритмів для різних значень фактору зменшення*/

#include <iostream>
#include <vector>
#include <chrono>
#include <Windows.h>
using namespace std;
using namespace std::chrono;

int search_array(vector<int> a, int x, int factor) {
    int n = a.size();
    int step = n;
    int i = 0;
    while (step > 1) {
        step = max(step / factor, 1);
        while (i + step < n && a[i + step] <= x) {
            i += step;
        }
    }
    while (i < n && a[i] <= x) {
        if (a[i] > 30) {
            return i;
        }
        i++;
    }
    return -1;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n = 1000000;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    int x = 30;
    int factor = 2;
    while (factor <= n) {
        auto start = high_resolution_clock::now();
        int index = search_array(a, x, factor);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Фактор: " << factor << ", Час: " << duration.count() << " мікросекунди" << endl;
        factor *= 2;
    }
    return 0;
}
