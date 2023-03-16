/* LB4_Yarosh.cpp : Вводити елементи, доки сума від’ємних не стане менша за -23
Вставити введене число перед кожним елементом, більшим за 10*/

#include <iostream>
using namespace std;

struct Node
{
    double data;
    Node* next;
};

void Add_Node(Node* &head, Node* &end)
{
    double sum = 0;
    do {
        Node* c = new struct Node;
        c->next = NULL;
        cin >> c->data;
        if (head == NULL)
        {
            head = c; end = c;
        }
        else
        {
            end->next = c;
            end = c;
        }
        if (c->data < 0)
        {
            sum+=c->data;
        }
    } while (sum > -23);
}

void Print_List(Node* head)
{
    cout << "The list:" << endl;
    Node* c = head;
    while (c != NULL)
    {
        cout << c->data << " ";
        c = c->next;
    }
    cout << endl;
}

void Free_Memory(Node* head)
{
    Node* c = head;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
}

void Insert_Beg(Node* &head, double x)
{
    Node* c = new Node;
    c->data = x;
    c->next = head;
    head = c;
}

void Insert_After(Node* &prev, double x)
{
    if (prev == NULL)
    {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }
    Node* c = new Node;
    c->data = x;
    c->next = prev->next;
    prev->next = c;
}

void Insert_Num(Node* &head, double x)
{
    Node* c = head;
    if (head->data > 10)
        Insert_Beg(head, x);
    while (c->next != NULL)
    {
        if (c->next->data > 10)
        {
            Insert_After(c, x);
            c = c->next;
        }
        c = c->next;
    }
}

int main()
{
    double x;
    Node* head = NULL, * end = NULL, * c;
    cout << "Input the elements:" << endl;
    Add_Node(head, end);
    Print_List(head);
    cout << "Enter the number:" << endl;
    cin >> x;
    Insert_Num(head,x);
    cout << "Insert the entered number before each element greater than 10" << endl;
    Print_List(head);
    Free_Memory(head);
    return 0;
}
