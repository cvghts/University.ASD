/* LB9_Yarosh.cpp : 1. Побудувати бінарне дерево пошуку з вхідної послідовності дійсних чисел.
Вивести значення вузлів, що лежать на шляху від кореня до вузла з максимальним елементом.
2. Ввести число. Визначити, чи присутнє це число в дереві, створеному в Завданні 1. 
Видалити знайдений елемент. 
Продемонструвати для листка, вузла з одним піддеревом, вузла з двома піддеревами. */

#include <iostream>
using namespace std;

struct Node
{
    double x;
    Node* l, * r;
};

void add_node(double x, Node*& Tree) //Фукція долучення елемента у дерево
{
    if (Tree == NULL)
    {
        Tree = new Node;
        Tree->x = x;
        Tree->l = Tree->r = NULL;
    }
    else {
        if (x < Tree->x)
        {
            if (Tree->l != NULL) add_node(x, Tree->l);
            else
            {
                Tree->l = new Node;
                Tree->l->l = Tree->l->r = NULL;
                Tree->l->x = x;
            }
        }
        if (x >= Tree->x)
        {
            if (Tree->r != NULL) add_node(x, Tree->r);
            else
            {
                Tree->r = new Node;
                Tree->r->l = Tree->r->r = NULL;
                Tree->r->x = x;
            }
        }
    }
}

void PrintTree(Node* leaf, int& n) //Вивід на екран
{
    if (leaf != NULL)
    {
        n++;
        PrintTree(leaf->l, n);
        for (int i = 1; i <= n; i++)      cout << " ";
        cout << leaf->x << endl;
        PrintTree(leaf->r, n);
        n--;
    }
}

double Max(Node* tree) //Пошук максимального елемента
{
    double rez = tree->x;
    while (tree != NULL)
    {
        rez = tree->x;
        tree = tree->r;
    }
    return rez;
}

void PrintMax(Node* leaf)
{
    while (leaf != NULL)
    {
        cout << leaf->x << ',';
        leaf = leaf->r;
    }
}

Node* Search(Node*& Tree, double& num) //Пошук елемента з певним значення засобами рекурсії
{
    if (Tree == NULL) return NULL;
    if (num == Tree->x) return Tree;
    else
        if (num < Tree->x) return Search(Tree->l, num);
        else return Search(Tree->r, num);
}

void Delete(Node*& node, double num); //Прототип

void GetPredecessor(Node* node, double& num) //Функція пошуку значення
{                                               // попереднього елемента
    while (node->r != NULL)
        node = node->r;
    num = node->x;
}

void DeleteNode(Node*& node) //Функція видалення елемента
{
    double num;
    Node* ptr = node;
    if (node->l == NULL) { //Права гілка
        node = node->r;
        delete ptr;
    }
    else if (node->r == NULL) { //Ліва гілка
        node = node->l;
        delete ptr;
    }
    else {
        GetPredecessor(node->l, num);
        node->x = num;
        Delete(node->l, num);
    }
}

void Delete(Node*& node, double num) //Пошук вузла node, який треба видалити
{
    if (num < node->x)
        Delete(node->l, num);
    else
        if (num > node->x)
            Delete(node->r, num);
        else
            DeleteNode(node);
}

void free(Node*& Tree) //Звільнення пам'яті
{
    if (Tree != NULL)
    {
        free(Tree->l);
        free(Tree->r);
        delete Tree;
        Tree = NULL;
    }
}

int main()
{
    int number;
    cout << "Enter the number: \n";
    cin >> number;
    cout << "Enter " << number <<  " numbers for a tree:" << endl;
    double x;
    Node* Tree = NULL;
    for (int i = 1; i <= number; i++) {
        cin >> x;
        add_node(x, Tree);
    }
    cout << "Tree: \n";
    PrintTree(Tree, number);
    cout << "Max = " << Max(Tree) << '\n';
    cout << "Nodes from root to max: ";
    PrintMax(Tree);
    cout << "\nEnter a search value: \n";
    double Num;
    cin >> Num;
    Node* s = Search(Tree, Num);
    if (s) cout << "Your value founded = " << s->x << endl;
    else cout << "Your value hasn't been founded! \n";
    Delete(Tree, Num);
    PrintTree(Tree, number);
    free(Tree);
}