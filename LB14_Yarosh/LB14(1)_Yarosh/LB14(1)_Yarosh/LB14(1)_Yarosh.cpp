/* LB14(1)_Yarosh.cpp : Виконати ручний розрахунок алгоритму пошуку найкоротшого шляху в
заданому графі.Написати програму пошуку найкоротшого шляху і протестувати
її для графа, заданого в індивідуальному варіанті.*/

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include<Windows.h>

#define V 7

using namespace std;

//Структура для зберігання інформації про кожну вершину графа
struct Node {
    int vertex;
    int weight;

    Node(int v, int w) : vertex(v), weight(w) {}
};

//Функція для порівняння двох вершин за їх вагою
struct compareNodes {
    bool operator()(const Node& node1, const Node& node2) {
        return node1.weight > node2.weight;
    }
};

//Функція для пошуку найкоротшого шляху у навантаженому графі
void dijkstra(int graph[V][V], int src) {
    // Масив відстаней, де dist[i] - найкоротший шлях з початкової вершини до i
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    // Черга з вершинами, які потрібно обробити
    priority_queue<Node, vector<Node>, compareNodes> pq;

    // Початкова вершина з відстанню 0
    pq.push(Node(src, 0));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0) {
                int weight = graph[u][v]; // вага ребра
                int newDist = dist[u] + weight; // нова відстань

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push(Node(v, dist[v]));
                }
            }
        }
    }
    cout << "Вершина\t Найкоротша відстань від джерела\n";
    for (int i = 0; i < V; i++) {
        cout << i+1 << "   ->\t " << dist[i] << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int graph[V][V] = {
        {0, 2, 13, 25, 17, 0, 0},
        {0, 0, 0, 3, 6, 0, 0},
        {0, 0, 0, 1, 0, 7, 0},
        {0, 0, 0, 0, 1, 4, 35},
        {0, 0, 0, 0, 0, 0, 20},
        {0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0}
    };

    int src = 0; // Початкова вершина
    dijkstra(graph, src);
    return 0;
}