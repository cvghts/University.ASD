// SW25-Yarosh.cpp : Генерація сюжетів фантастичних оповідань

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <random>
#include <ctime>
#include <Windows.h>
using namespace std;

class Graph {
private:
    int size;
    unordered_map<int, string> vertexMap;
    unordered_map<int, vector<int>> adjacencyList;

public:
    Graph(int n) {
        size = n;
    }

    void addVertex(int v, string label) {
        vertexMap[v] = label;
    }

    void addEdge(int v1, int v2) {
        adjacencyList[v1].push_back(v2);
    }

    void printGraph() {
        for (int i = 1; i <= size; i++) {
            cout << vertexMap[i];
            std::cout << std::endl;
        }
    }
    void randomWalk() {
        srand(time(NULL));
        int start = 1; // начинаем с первой вершины
        int end = size; // заканчиваем на последней вершине
        int current = start;
        cout << vertexMap[current];
        bool shouldExit = false;
        while (current != end && !shouldExit) {
            vector<int> neighbors = adjacencyList[current];
            int n = neighbors.size();
            if (n == 0) { // если нет соседей, то завершаем цикл
                shouldExit = true;
                break;
            }
            int next = neighbors[rand() % n];
            current = next;
            cout << vertexMap[current];
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Graph g(61);

    // добавляем ребра
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);

    g.addEdge(2, 6);
    g.addEdge(2, 7);

    g.addEdge(3, 8);
    g.addEdge(3, 9);

    g.addEdge(4, 10);
    g.addEdge(4, 10);

    g.addEdge(5, 12);
    g.addEdge(5, 13);
    g.addEdge(5, 14);

    g.addEdge(8, 15);
    g.addEdge(8, 16);
    g.addEdge(9, 15);
    g.addEdge(9, 16);
    g.addEdge(10, 17);
    g.addEdge(11, 17);
    g.addEdge(14, 18);
    g.addEdge(14, 19);

    g.addEdge(15, 20);
    g.addEdge(15, 21);
    g.addEdge(15, 22);
    g.addEdge(15, 23);
    g.addEdge(15, 24);

    g.addEdge(16, 20);
    g.addEdge(16, 21);
    g.addEdge(16, 22);
    g.addEdge(16, 23);
    g.addEdge(16, 24);

    g.addEdge(17, 20);
    g.addEdge(17, 21);
    g.addEdge(17, 22);
    g.addEdge(17, 23);
    g.addEdge(17, 24);

    g.addEdge(20, 25);
    g.addEdge(21, 25);
    g.addEdge(22, 25);
    g.addEdge(23, 25);
    g.addEdge(24, 25);

    g.addEdge(25, 26);
    g.addEdge(25, 27);
    g.addEdge(25, 28);
    g.addEdge(25, 29);
    g.addEdge(25, 30);
    g.addEdge(25, 31);

    g.addEdge(26, 32);
    g.addEdge(26, 34);
    g.addEdge(27, 34);
    g.addEdge(28, 34);
    g.addEdge(29, 34);
    g.addEdge(30, 34);
    g.addEdge(31, 34);
    g.addEdge(31, 36);

    g.addEdge(34, 33);
    g.addEdge(34, 35);

    g.addEdge(33, 38);
    g.addEdge(35, 38);

    g.addEdge(38, 37);
    g.addEdge(38, 39);

    g.addEdge(37, 40);
    g.addEdge(37, 41);
    g.addEdge(37, 42);
    g.addEdge(39, 43);
    g.addEdge(39, 44);
    g.addEdge(39, 45);

    g.addEdge(43, 46);
    g.addEdge(43, 47);
    g.addEdge(44, 46);
    g.addEdge(44, 47);
    g.addEdge(45, 46);
    g.addEdge(45, 47);

    g.addEdge(46, 48);
    g.addEdge(46, 49);
    g.addEdge(46, 50);
    g.addEdge(47, 51);
    g.addEdge(47, 52);
    g.addEdge(47, 53);

    g.addEdge(48, 54);
    g.addEdge(48, 55);
    g.addEdge(48, 56);
    g.addEdge(48, 57);
    g.addEdge(51, 58);
    g.addEdge(51, 59);
    g.addEdge(51, 60);
    g.addEdge(52, 58);
    g.addEdge(52, 59);
    g.addEdge(52, 60);
    g.addEdge(53, 58);
    g.addEdge(53, 59);
    g.addEdge(53, 60);
    g.addEdge(53, 61);

    g.addEdge(43, 54);
    g.addEdge(43, 55);
    g.addEdge(43, 56);
    g.addEdge(43, 57);
    g.addEdge(44, 54);
    g.addEdge(44, 55);
    g.addEdge(44, 56);
    g.addEdge(44, 57);
    g.addEdge(45, 54);
    g.addEdge(45, 55);
    g.addEdge(45, 56);
    g.addEdge(45, 57);

    string texts[] = { "Земля ", "сгорает, или замерзает, или падает на Солнце ", 
        "- учёные ", "подвергается нашествию ", "сталкивается с огромной кометой ", 
        "и все гибнут (конец)", "и почти все гибнут (конец)", "создают ", "открывают ", 
        "маленьких ", "огромных ", "и разрушается (конец)", "и остаётся невредимой (конец)", 
        "и не разрушается, но ", "маленьких ", "огромных ", "марсиан, селенитов, межгалактических чудовищ - ", 
        "все гибнут (конец)", "почти все гибнут (конец)", "насекомых, ", "пресмыкающихся, ", "роботов, ", 
        "внеземных существ, ", "различных странных предметов, ", "которые ", "желают наших женщин ", "ведут себя дружелюбно ", 
        "ведут себя дружелюбно, но их никто не понимает, ", "не понимают нас ", "отлично понимают нас ", 
        "воспринимают нас только как пищу ", "похищают их и исчезают (конец)", "радиоактивными ", "и являются ", 
        "нерадиоактивными ", "и съедают нас (конец)", "могут быть уничтожены ", "и ", "не могут быть уничтожены ", 
        "толпой парней с факелами (конец)", "сухопутной армией, морским флотом, авиацией, морской пехотой и (или) войсками береговой охраны (конец)", 
        "атомной бомбой (конец)", "атомной бомбой ", "сухопутной армией, морским флотом, авиацией, морской пехотой и (или) войсками береговой охраны ", 
        "толпой парней с факелами ", "но учёные изобретают новое оружие ", "но ", "которое отказывает ", "которое их убивает (конец)", 
        "которое превращает их в мерзкие глыбы (конец)", "один хитрый парень убеждает их, что люди ОК ", "священник рассказывает им о Боге ", 
        "влюбляются в красивую девушку ", "но они умирают от чёрной оспы (конец)", "и поэтому они убивают нас (конец)", 
        "и поэтому они устанавливают систему доброжелательной диктатуры (конец)", "и поэтому они съедают нас (конец)", 
        "и они умирают (конец)", "и они улетают (конец)", "и они превращаются в мерзкие глыбы (конец)", "женятся и живут долго и счастливо (конец)" };
    for (int i = 1; i <= 61; i++) {
        g.addVertex(i, texts[i - 1]);
    }
    g.randomWalk();
    //g.printGraph();
    return 0;
}
