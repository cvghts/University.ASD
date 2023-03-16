/* LB7_Yarosh.cpp : Створити циклічний двозв'язний список із дійсних чисел.
Визначити добуток негативних елементів списку.Видалити зі списку елемент після
першого додатного елементу.Створити циклічний однозв'язний список з
елементів вихідного списку, менших, ніж середнє арифметичне*/

#include <iostream>
using namespace std;

struct Node
{
    double Num;
    Node* next;
    Node* prev;
};

struct Node2
{
    double Num2;
    Node2* next2;
};

Node* InitList(double n)
{
    Node* c = new Node;
    c->next = c;
    c->prev = c;
    c->Num = n;
    return c;
};

Node2* InitList2(double n)
{
    Node2* c2 = new Node2;
    c2->next2 = c2;
    c2->Num2 = n;
    return c2;
};

Node* AddNodeAfter(Node*& ptr, double n)
{
    Node* c = new Node;
    c->next = c;
    c->Num = n;
    if (ptr == NULL) return NULL;
    else
    {
        c->next = ptr->next;
        c->prev = ptr;
        ptr->next = c;
        ptr = c;
        return c->next;
    };
};

Node2* AddNodeAfter2(Node2*& ptr, double n)
{
    Node2* c2 = new Node2;
    c2->next2 = c2;
    c2->Num2 = n;
    if (ptr == NULL) return NULL;
    else
    {
        c2->next2 = ptr->next2;
        ptr->next2 = c2;
        ptr = c2;
        return c2->next2;
    };
};

void Print_List(Node* head)
{
    cout << "The list:" << endl;
    Node* c = head;
    do {
        if (c) {
            cout << c->Num << " ";
            c = c->next;
        };
    } while (c != head);
    cout << endl;
};

void Print_List2(Node2* head)
{
    cout << "The new list:" << endl;
    Node2* c2 = head;
    do {
        if (c2) {
            cout << c2->Num2 << " ";
            c2 = c2->next2;
        };
    } while (c2 != head);
    cout << endl;
};

Node* Del(Node*& ptr, Node*& head, Node*& end)
{
    if (ptr == NULL) return NULL;
    if (ptr == head) {
        if (head == end) {
            delete ptr;
            head = end = NULL;
            return NULL;
        }
        else {
            head = head->next;
            end->next = head;
            delete ptr;
            return head;
        };
    };
    Node* prev = ptr->next;
    while (prev && prev->next != ptr)
        prev = prev->next;
    if (prev != ptr)
    {
        prev->next = ptr->next;
        if (ptr == end)    end = prev;
        delete ptr;
        return prev->next;
    }
    return NULL;
};

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
    };
};

void Free_Memory2(Node2* head2, Node2* end2)
{
    if (head2 == NULL) return;
    Node2* c2 = head2;
    end2->next2 = NULL;
    while (c2 != NULL)
    {
        head2 = head2->next2;
        delete c2;
        Node2* c2 = head2;
    };
};

int main()
{
    Node* head = NULL, * end = NULL, * c;
    Node2* head2 = NULL, * end2 = NULL, * c2;
    int a;
    cout << "How many numbers do you want to enter?";
    cout << endl;
    cin >> a;
    cout << "Input your numbers: " << endl;
    for (int i = 0; i < a; i++)
    {
        int n;
        cin >> n;
        if (head == NULL) head = end = InitList(n);
        else head = AddNodeAfter(end, n);
    };
    Print_List(head);
    double prod=1, ser=0, sum=0;
    int kol = 0;
    c = head;
    do {
        kol++;
        sum += c->Num;
        if (c->Num < 0) {
            prod*= c->Num;
            c = c->next;
        }
        else c = c->next;
    } while (c != head);
    cout << "Sum:" << sum << endl;
    ser = sum / kol;
    cout << "Arithmetic average of elements:" << ser << endl;
    cout << "Product of negative elements: " << prod;
    cout << endl;
    c = head;
    do {
        if ((c->Num) < ser)
        {
            if (head2 == NULL) head2 = end2 = InitList2(c->Num);
            else head2 = AddNodeAfter2(end2, c->Num);
        };
        c = c->next;
    } while (c != head);
    c = head;
    do {
        if ((c->Num) > 0)
        {
            c = c->next;
            c = Del(c, head, end);
            break;
        }
        else { c = c->next; };
    } while (c != head);
    c = head;
    cout << "Delete the element after the first positive:" << endl;
    Print_List(head);
    c2 = head2;
    cout << "Elements are less than the arithmetic mean:" << endl;
    Print_List2(head2);
    Free_Memory(head, end);
    Free_Memory2(head2, end2);
    return 0;
}