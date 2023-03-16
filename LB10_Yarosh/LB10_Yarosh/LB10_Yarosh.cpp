/* Yarosh.cpp:
1. Створити шаблон класу бінарного дерева пошуку з такими операціями.
1.1. долучення (вставлення) елемента в дерево;
1.2. видалення елемента з дерева;
1.3. пошук елемента в дереві. Створити два варіанти функції: перша функція
повертає значення true, якщо елемент є в дереві, false – якщо його немає;
друга функція повертає вказівник на елемент, якщо він є в дереві, і nullptr
якщо його там немає.
1.4. пошук мінімального і максимального елементів дерева;
1.5. визначення кількості елементів у дереві;
1.8. прямий, зворотний, центрований обхід дерева;
1.9. обхід дерева в ширину;
1.6. визначення висоти дерева;
1.7. пошук батька елемента;
1.10. формування лінійного дужкового запису дерева;
1.11. видалення дерева.
3. На основі класу бінарного дерева реалізувати клас збалансованого дерева.
Для балансування використовувати додатковий відсортований масив і бінарний пошук.
4. На основі класу бінарного дерева реалізувати клас
збалансованого дерева. Для балансування використовувати алгоритм DSW.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

template <typename T>
class Tree {
public:
    Tree() {
        root = nullptr;
    }

    struct Node {
        Node() {}
        T data;
        Node* l = nullptr;
        Node* r = nullptr;
        Node(T value) { data = value; }
    };

    void Add_Node(T value) {
        add_node(value, root);
    }

    void PrintTree() {
        int q = 30;
        print_tree(root, q);
    }

    void printTreeLNR() {
        printTreeLNR_(root);
    }

    void printTreeNLR() {
        printTreeNLR_(root);
    }

    void printTreeLRN() {
        printTreeLRN_(root);
    }

    void Insert(T value) {
        root = doInsert(root, value);
        size++;
        vector_.push_back(value);
    }

    void Destroy(T value) {
        Delete(root, value);
        size--;
    }

    Node* Find(T value) {
        return search(root, value);
    }

    bool IsContain(T value) {
        return SearchBool(root, value);
    }

    T Min() {
        return FindMin(root);
    }

    T Max() {
        return FindMax(root);
    }

    int Height() {
        return getHeight(root);
    }

    void FindParent(T value) {
        findParent_(root, value, -1);
    };

    int TreeElemCounter() {
        return TreeCounter(root);
    }

    void treeToString()
    {
        string str = "";
        treeToString_(root, str);
        cout << str;
    }

    void BalancedTree() {
        sort(vector_.begin(), vector_.end());
        root = Convert(vector_);
        PrintTree();
    }

    void BalancedDSWTree() {
        root = BalanceDSW(root);
        PrintTree();
    }

    void FreeTheTree() {
        FreeTree(root);
        size = 0;
    }

private:
    Node* root;
    int size = 0;
    vector<T> vector_;

    Node* doInsert(Node*& node_, T value) {
        if (node_ == nullptr) {
            return new Node(value);
        }
        if (value < node_->data) {
            node_->l = doInsert(node_->l, value);
        }
        else if (value > node_->data) {
            node_->r = doInsert(node_->r, value);
        }
        return node_;
    }

    void Delete(Node*& node_, T value)
    {
        if (value < node_->data)
            Delete(node_->l, value);
        else
            if (value > node_->data)
                Delete(node_->r, value);
            else
                DeleteNode(node_);
    }

    void getPredecessor(Node* node_, T& value)
    {
        while (node_->r != nullptr)
            node_ = node_->r;
        value = node_->data;
    }

    void DeleteNode(Node*& node_)
    {
        int key;
        Node* ptr = node_;
        if (node_->l == NULL) {
            node_ = node_->r;
            delete ptr;
        }
        else if (node_->r == NULL) {
            node_ = node_->l;
            delete ptr;
        }
        else if (node_->r == NULL && node_->l == NULL) {

        }
        else {
            getPredecessor(node_->l, key);
            node_->data = key;
            Delete(node_->l, key);
        }
    }

    Node* search(Node* node_, T value)
    {
        while (node_ != nullptr)
        {
            if (value == node_->data) return node_;
            else
                if (value < node_->data) node_ = node_->l;
                else node_ = node_->r;
        }
        return nullptr;
    }

    bool SearchBool(Node* node_, T value)
    {
        while (node_ != nullptr)
        {
            if (value == node_->data) return true;
            else
                if (value < node_->data) node_ = node_->l;
                else node_ = node_->r;
        }
        return false;
    }

    T FindMax(Node* node_)
    {
        T max = node_->data;
        while (node_ != nullptr)
        {
            max = node_->data;
            node_ = node_->r;
        }
        return max;
    }

    T FindMin(Node* node_){
        T min = node_->data;
        while (node_ != nullptr)
        {
            min = node_->data;
            node_ = node_->l;
        }
        return min;
    }

    int getHeight(Node* node_) {
        if (node_ == nullptr) {
            return 0;
        }
        else {
            int lheight = getHeight(node_->l);
            int rheight = getHeight(node_->r);
            if (lheight > rheight) {
                return (lheight + 1);
            }
            else {
                return (rheight + 1);
            }
        }
    }

    T TreeCounter(Node* node_) {
        int c = 1;
        if (node_ == NULL)
            return 0;

        else
        {
            c += TreeCounter(node_->l);
            c += TreeCounter(node_->r);
            return c;
        }
    };

    void print_tree(Node* node_, int& q)
    {
        if (node_ != NULL)
        {
            q++;
            print_tree(node_->l, q);
            for (int i = 1; i <= q; i++) cout << "    ";
            cout << node_->data << endl;
            print_tree(node_->r, q);
            q--;
        };
    };

    void findParent_(Node* node_, T value, T parent)
    {
        if (node_ == NULL) return;
        if (node_->data == value) {
            if (parent == -1) { cout << "Немає батька"; }
            else { cout << "Батько: " << parent; };
        }
        else {
            findParent_(node_->l, value, node_->data);
            findParent_(node_->r, value, node_->data);
        }
    }

    void printTreeLNR_(Node* node_) {
        if (node_ != NULL) {
            printTreeLNR_(node_->l);
            cout << node_->data << " ";
            printTreeLNR_(node_->r);
        }
    }

    void printTreeNLR_(Node* node_) {
        if (node_ != NULL) {
            cout << node_->data << " ";
            printTreeNLR_(node_->l);
            printTreeNLR_(node_->r);
        }
    }

    void printTreeLRN_(Node* node_) {
        if (node_ != NULL) {
            printTreeLRN_(node_->l);
            printTreeLRN_(node_->r);
            cout << node_->data << " ";
        }
    }

    void treeToString_(Node* node_, string& str)
    {
        if (node_ == NULL)
            return;
        str.append(to_string(node_->data));
        if (!node_->l && !node_->r)
            return;
        str.push_back('(');
        treeToString_(node_->l, str);
        str.push_back(')');
        if (node_->r) {
            str.push_back('(');
            treeToString_(node_->r, str);
            str.push_back(')');
        }
    }

    void Convert2(vector<T> vector_, int low, int high, Node*& node_)
    {
        if (low > high) {
            return;
        }
        int mid = (low + high) / 2;
        node_ = new Node(vector_[mid]);
        Convert2(vector_, low, mid - 1, node_->l);
        Convert2(vector_, mid + 1, high, node_->r);
    }

    Node* Convert(vector<T> vector_)
    {
        Node* node_ = nullptr;
        Convert2(vector_, 0, vector_.size() - 1, node_);
        return node_;
    }

        int BST_To_Vine(Node* grand){
        int count = 0;
        Node* tmp = grand->r;
        while (tmp) {
            if (tmp->l) {
                Node* oldTmp = tmp;
                tmp = tmp->l;
                oldTmp->l = tmp->r;
                tmp->r = oldTmp;
                grand->r = tmp;
            }
            else {
                count++;
                grand = tmp;
                tmp = tmp->r;
            }
        }
        return count;
    }

    void Compress(Node* node_, int m)
    {
        Node* tmp = node_->r;
        for (int i = 0; i < m; i++) {
            Node* oldTmp = tmp;
            tmp = tmp->r;
            node_->r = tmp;
            oldTmp->r = tmp->l;
            tmp->l = oldTmp;
            node_ = tmp;
            tmp = tmp->r;
        }
    }

    Node* BalanceDSW(Node* node_)
    {
        Node* grand = new Node(0);
        grand->r = node_;
        int count = BST_To_Vine(grand);
        int h = log2(count + 1);
        int m = pow(2, h) - 1;
        Compress(grand, count - m);
        for (m = m / 2; m > 0; m /= 2) {
            Compress(grand, m);
        }
        return grand->r;
    }

    void FreeTree(Node*& node_) {

        if (node_ != nullptr)
        {
            FreeTree(node_->l);
            FreeTree(node_->r);
            delete node_;
            node_ = nullptr;
        }
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Tree <int> tree;
    int a, b, c, d, e;
    cout << "Введіть розмір дерева: ";
    cin >> a;
    cout << "Введіть елементи:" << endl;
    for (int i = 0; i < a; i++)
    {
        cin >> e;
        tree.Insert(e);
    }
    cout << "Дерево:" << endl;
    tree.PrintTree();
    cout << "\n\n\n\n\n\n" << "Збалансоване дерево за масивом:" << endl;
    tree.BalancedTree();
    cout << "\n\n" << "Вхідне значення для батьківського елемента: ";
    cin >> c;
    tree.FindParent(c);
    cout << "\n\n\n\n\n\n" << "Збалансоване дерево алгоритму DSW:" << endl;
    tree.BalancedDSWTree();
    cout << "\n\n" << "Вхідне значення для батьківського елемента: ";
    cin >> c;
    tree.FindParent(c);
    cout << "\n\n" << "Дерево з використанням LNR:" << endl;
    tree.printTreeLNR();
    cout << "\n\n" << "Дерево з використаннням LRN:" << endl;
    tree.printTreeLRN();
    cout << "\n\n" << "Дерево з використанням NLR:" << endl;
    tree.printTreeNLR();
    cout << "\n\n" << "Дерево в рядок:" << endl;
    tree.treeToString();
    cout << "\n\n" << "Висота: " << tree.Height();
    cout << "\n\n" << "Введіть значення для пошуку: ";
    cin >> b;
    cout << "\n" << "Чи містить воно число? (nullptr, якщо ні, покажчик елемента, якщо так): " << tree.Find(b);
    cout << "\n" << "Чи містить воно число? (0 якщо ні, 1 якщо так): " << tree.IsContain(b);
    cout << "\n\n" << "Мінімальне значення: " << tree.Min();
    cout << "\n" << "Максимальне значення: " << tree.Max();
    cout << "\n\n" << "Кількість елементів: " << tree.TreeElemCounter();
    cout << "\n\n\n" << "Вхідне значення для стирання: ";
    cin >> d;
    if (tree.IsContain(d)) {
        tree.Destroy(d);
        cout << "\n" << "Дерево:" << endl;
        tree.PrintTree();
    }
    else { cout << "Такого елемента в дереві немає!"; }
    cout << "\n\n" << "Кількість елементів: " << tree.TreeElemCounter();
    cout << "\n\n" << "Звільнення дерева:";
    tree.FreeTheTree();
    tree.PrintTree();
    cout << "\n\n\n";
}