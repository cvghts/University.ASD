/* LB6_Yarosh.cpp : Створити циклічний список із чисел.
Вставити перед кожним додатним елементом новий елемент, який дорівнює сумі всіх елементів*/

#include <iostream>
using namespace std;

struct Node {
    double data;
    Node* next;
};

Node* InitList(double x)
{
    Node* c = new Node;
    c->next = c;
    c->data = x;
    return c;
}

Node* AddNodeAfter(Node*& ptr, double x)
{
    Node* c = new Node;
    c->data = x;
    if (ptr == NULL) return NULL;
    else
    {
        c->next = ptr->next;
        ptr->next = c;
        ptr = c;
        return c->next;
    }
}

void AddNodeBeforeHead(Node*& head, Node*& end, double data)
{
    Node* node = new Node;
    node->data = data;
    node->next = head;
    head = node;
    end->next = head;
}

void Print_List(Node* head)
{
    cout << "The list:" << endl;
    Node* c = head;
    do {
        if (c) {
            cout << c->data << " ";
            c = c->next;
        }
    } while (c != head);
    cout << endl;
}

void Free_Memory(Node* head, Node* end)
{
    if (head == NULL) return;
    Node* c = head;
    end->next = NULL;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
}

int main()
{
    Node* head = NULL, * end = NULL, * c;
    double x, sum=0;
    cout << "Input 10 elements:" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cin >> x;
        if (head == NULL) head = end = InitList(x);
        else c = AddNodeAfter(end, x);
    }
    Print_List(head);
    cout << end->next->data << endl;
    c = head;
    while (c->next != head)
    {
        sum += c->data;
        c = c->next;
    }
    cout << "Sum = " << sum << endl;
    c = head;
    while (c->next != head)
    {
        if (c == head)
        {
            if (c->data > 0)
            {
                AddNodeBeforeHead(head, end, sum);
                end->next = head;
            }
        }
        if (c->next->data > 0)
        {
            AddNodeAfter(c, sum);
            c = c->next;
        }
        else c = c->next;
    }
    cout << "New list:" << endl;
    Print_List(head);
    if (c) Free_Memory(head, end);
    return 0;
}
