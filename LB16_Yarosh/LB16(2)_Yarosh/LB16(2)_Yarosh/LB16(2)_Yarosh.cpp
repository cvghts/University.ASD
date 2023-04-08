// LB16(2)_Yarosh.cpp : Дан масив цілих чисел A розміру N. Напишіть рекурсивну функцію, яка знаходить мінімум в масиві.

#include <iostream>
using namespace std;

int findMin(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int min = findMin(arr, n - 1);
    if (arr[n - 1] < min) {
        min = arr[n - 1];
    }
    return min;
}

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    int* arr = new int[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int min = findMin(arr, N);
    cout << "Minimum element in array is: " << min << endl;
    delete[] arr;
    return 0;
}

//-1 2 0 22 -5 1