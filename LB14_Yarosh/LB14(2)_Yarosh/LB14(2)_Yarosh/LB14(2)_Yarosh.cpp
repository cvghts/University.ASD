/* LB14(2)_Yarosh.cpp : Виконати ручний розрахунок алгоритмів обходу заданого графа вшир та
вглиб.Написати програму обходу графа в ширину і глибину та протестувати її
для графа, заданого в індивідуальному варіанті.*/

#include <iostream>
#include <queue>
#include <stack>
#include<Windows.h>
using namespace std;

const int MAX_SIZE = 100;

int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int n;

// обхід в ширину
void breadthFirstSearch(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

// обхід в глибину
void depthFirstSearch(int start) {
    stack<int> s;
    s.push(start);
    visited[start] = 1;
    cout << start << " ";
    while (!s.empty()) {
        int v = s.top();
        int i;
        for (i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                s.push(i);
                visited[i] = 1;
                cout << i << " ";
                break;
            }
        }
        if (i == n) {
            s.pop();
        }
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Введіть кількість вершин: ";
    cin >> n;
    cout << "Введіть матрицю суміжності:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Введіть початкову вершину для пошуку вшир: ";
    int start;
    cin >> start;
    cout << "Пошук у ширину, починаючи з вершини " << start << ": ";
    breadthFirstSearch(start);
    for (int i = 0; i < n; i++) { // очищення масиву відвіданих вершин
        visited[i] = 0;
    }
    cout << "Введіть початкову вершину для пошуку в глибину: ";
    cin >> start;
    cout << "Пошук у глибину, починаючи з вершини " << start << ": ";
    depthFirstSearch(start);
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
*/