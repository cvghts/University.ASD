/* LB15_Yarosh.cpp : Написати програму для реалізації алгоритму Дейкстри та протестувати її
для графа, заданого в індивідуальному варіанті.*/

#include <iostream>
#include <vector>
#include <limits.h>
#include<Windows.h>
#define V 7
using namespace std;

// Функція для знаходження вершини з найменшою відстанню серед вершин, які ще не оброблялися
int minDistance(int dist[], vector<bool> visited) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    vector<bool> visited(V, false);
    // ініціалізуємо масив відстаней INT_MAX, крім джерела, відстань до якого = 0
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    // виконуємо алгоритм Дейкстри для знаходження найкоротшого шляху до кожної вершини
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);// вибираємо вершину з найменшою відстанню серед непройдених
        visited[u] = true; // позначаємо вершину як відвідану
        // перебираємо всі сусідні вершини вибраної вершини
        for (int v = 0; v < V; v++)
            // якщо вершина ще не відвідана, є ребро між u і v, та шлях від джерела до u і з u до v є короткішим за поточний найкоротший шлях до v
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v]; // оновлюємо відстань до вершини v
    }

    cout << "Вершина \t Відстань від джерела\n";
    for (int i = 0; i < V; i++)
        cout << i+1 << " \t->\t" << dist[i] << "\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int graph[V][V];

    cout << "Введіть матрицю суміжності:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    dijkstra(graph, 0);

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

