/* LB9(2)_Yarosh.cpp :  Створити словник – текстовий файл, кожний рядок якого містить слово та його переклад.
Заповнити бінарне дерево словами із словника. Ввести рядок.
За допомогою дерева знайти переклад кожного слова і вивести переклад рядка на екран.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct BSTNode {
    string words;
    BSTNode* l, * r;
};

void InsertInTree(string theseWords, BSTNode*& Tree)
{
    if (Tree == NULL)
    {
        Tree = new BSTNode;
        Tree->words = theseWords;
        Tree->l = Tree->r = NULL;
    }
    else {
        if (theseWords < Tree->words)
        {
            if (Tree->l != NULL) InsertInTree(theseWords, Tree->l);
            else
            {
                Tree->l = new BSTNode;
                Tree->l->l = Tree->l->r = NULL;
                Tree->l->words = theseWords;
            }
        }
        if (theseWords >= Tree->words)
        {
            if (Tree->r != NULL) InsertInTree(theseWords, Tree->r);
            else
            {
                Tree->r = new BSTNode;
                Tree->r->l = Tree->r->r = NULL;
                Tree->r->words = theseWords;
            }
        }
    }
}

string search(BSTNode*& Tree, string& key) 
{
    if (Tree == NULL) return "Eroor: No translation found";
    int size = Tree->words.find(" ");
    string firstword = Tree->words.substr(0, size);
    if (key == firstword) return Tree->words;
    else
        if (key < firstword) return search(Tree->l, key);
        else return search(Tree->r, key);
}

struct queue
{
    string data;
    queue* next;
};

void pushQUEUE(queue*& head, queue*& tail, string x)
{
    queue* element = new queue;
    element->data = x;
    element->next = NULL;
    if (head == NULL)
        head = element;
    else
        tail->next = element;
    tail = element;
}

void printQUEUE(queue* head)
{
    queue* element = new queue;
    element = head;
    if (head == NULL)
        cout << "Nothing has been translated!";
    else
    {
        cout << "Translation:\n";
        while (element != nullptr)
        {
            int size = element->data.find(" ");
            string secondword = element->data.substr(size + 1, element->data.length());
            cout << secondword << ' ';
            element = element->next;
        }
        cout << '\n';
    }
}

int main()
{
    cout << "Downloading words...\n";
    BSTNode* Tree = NULL;
    queue* first = NULL, * last = NULL;
    fstream newfile;
    newfile.open("vocabulary.txt", ios::in);
    if (newfile.is_open()) {
        string helper;
        while (getline(newfile, helper)) InsertInTree(helper, Tree);
        newfile.close();
    }
    cout << "Welcome to binary-tree vocalubaly!\n";
    cout << "Enter your words:\n";
    string a;
    do {
        cin >> a;
        pushQUEUE(first, last, search(Tree, a));
    } while (cin.get() != '\n');
    printQUEUE(first);
}
