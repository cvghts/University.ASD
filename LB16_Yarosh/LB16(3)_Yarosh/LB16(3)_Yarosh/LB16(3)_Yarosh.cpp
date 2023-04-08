/* LB16(3-4)_Yarosh.cpp : Побудувати бінарне дерево пошуку з вхідної послідовності цілих чисел.
Визначити суму значень листків з непарними значеннями.*/

#include <iostream>
#include<Windows.h>
using namespace std;

// Визначення структури вузла дерева
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

//Функція вставки нового вузла в бінарне дерево пошуку
void insertNode(Node*& root, int val) {
    if (root == nullptr) {
        root = new Node(val);
    }
    else if (val < root->value) {
        insertNode(root->left, val);
    }
    else {
        insertNode(root->right, val);
    }
}

//Функція пошуку вузла із заданим значенням у бінарному дереві пошуку
Node* findNode(Node* root, int val) {
    if (root == nullptr || root->value == val) {
        return root;
    }
    else if (val < root->value) {
        return findNode(root->left, val);
    }
    else {
        return findNode(root->right, val);
    }
}

//Функція пошуку мінімального значення в правому піддереві даного вузла
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

//Функція видалення вузла з заданим значенням із бінарного дерева пошуку
Node* removeNode(Node* root, int val) {
    if (root == nullptr) {
        return root;
    }
    else if (val < root->value) {
        root->left = removeNode(root->left, val);
    }
    else if (val > root->value) {
        root->right = removeNode(root->right, val);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* minNode = findMin(root->right);
            root->value = minNode->value;
            root->right = removeNode(root->right, minNode->value);
        }
    }
    return root;
}

//Функція для перегляду бінарного дерева пошуку та пошуку суми значень листів із непарними значеннями
int sumOfLeavesWithOddValues(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else if (root->left == nullptr && root->right == nullptr) {
        if (root->value % 2 != 0) {
            return root->value;
        }
        else {
            return 0;
        }
    }
    else {
        return sumOfLeavesWithOddValues(root->left) + sumOfLeavesWithOddValues(root->right);
    }
}

//Функція друку бінарного дерева пошуку в порядку
void printInOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->value << " ";
    printInOrder(root->right);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Node* root = nullptr;
    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;
    cout << "Введіть елементи: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(root, val);
    }
    cout << "Двійкове дерево пошуку в порядку перед видаленням: ";
    printInOrder(root);
    cout << endl;
    int sum = sumOfLeavesWithOddValues(root);
    cout << "Сума значень листків з непарними значеннями дорівнює " << sum << endl;
    int num;
    cout << "Введіть номер для пошуку та видалення: ";
    cin >> num;
    Node* foundNode = findNode(root, num);
    if (foundNode == nullptr) {
        cout << num << " немає в дереві" << endl;
    }
    else {
        root = removeNode(root, num);
        cout << num << " було видалено з дерева" << endl;
    }
    cout << "Двійкове дерево пошуку в порядку після видалення: ";
    printInOrder(root);
    return 0;
}

