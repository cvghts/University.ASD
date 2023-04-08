/* LB13_Yarosh.cpp : Написати програму, яка для заданого графа завдання 1 та 2
створює список суміжності по матриці суміжності та навпаки*/

#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

//функція для перетворення зваженої матриці суміжності до списку суміжності
vector<vector<pair<int, int>>>MatrixToList(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<pair<int, int>>> list(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //якщо є ребро між i та j, додаємо пару (j, вага ребра) до списку i
            if (matrix[i][j] != 0) {
                list[i].push_back(make_pair(j, matrix[i][j]));
            }
        }
    }
    return list;
}

//функція для перетворення списку суміжності до зваженої матриці суміжності
vector<vector<int>>ListToMatrix(const vector<vector<pair<int, int>>>& list) {
    int n = list.size();
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < list[i].size(); j++) {
            //Додаємо ребро з вагою в матрицю
            matrix[i][list[i][j].first] = list[i][j].second;
        }
    }
    return matrix;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while (true) {
        cout << "Введіть розмір матриці (0 для виходу): ";
        int n;
        cin >> n;
        if (n == 0) break;

        //ініціалізуємо матрицю суміжності через вектор
        vector<vector<int>> matrix(n, vector<int>(n));
        cout << "Введіть матрицу суміжності:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        //перетворимо матрицю на список суміжності
        vector<vector<pair<int, int>>> list = MatrixToList(matrix);

        cout << "Список суміжності:" << endl;
        for (int i = 0; i < list.size(); i++) {
            cout << i << " -> ";
            for (int j = 0; j < list[i].size(); j++) {
                cout << "(" << list[i][j].first << ", " << list[i][j].second << ") ";
            }
            cout << endl;
        }

        //перетворимо список суміжності на матрицю суміжності
        vector<vector<int>> newMatrix = ListToMatrix(list);

        cout << "Нова матриця суміжності:" << endl;
        for (int i = 0; i < newMatrix.size(); i++) {
            for (int j = 0; j < newMatrix[i].size(); j++) {
                cout << newMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

/* 
0 2 13 25 17 0 0
0 0 0 3 6 0 0
0 0 0 1 0 7 0
0 0 0 0 1 4 35
0 0 0 0 0 0 20
0 0 0 0 0 0 5
0 0 0 0 0 0 0


0 4 3 0 0 0
0 0 0 1 0 0
6 0 0 0 0 5
5 0 2 0 0 0
0 0 1 0 1 0
0 6 0 1 0 3
*/