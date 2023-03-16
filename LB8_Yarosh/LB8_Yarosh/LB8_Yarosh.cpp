/* LB8_Yarosh.cpp : Додати в чергу непарні цілі числа від 45 до 99. 
   Всі числа з черги витягувати по одному і ті, що менше 77, додавати в стек, інші виводити на екран. 
   Числа зі стека виймати по одному і друкувати*/

#include <iostream>
using namespace std;

struct queue
{
    int data;
    queue* next;
};

struct StackItem
{
    int data;
    StackItem* next = nullptr;
};

void pushQueue(queue*& head, queue*& tail, int x)
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

StackItem* pushStack(StackItem* head, int x)
{
    StackItem* new_top = new StackItem;
    new_top->data = x;
    new_top->next = head;
    head = new_top;
    return head;
}

void popQueue(queue*& head)
{
    head = head->next;
}

StackItem* popStack(StackItem* head)
{
    if (head == nullptr) return 0;
    StackItem* old_top = head;
    head = old_top->next;
    delete old_top;
    return head;
}

void printQueue(queue* head)
{
    queue* element = new queue;
    element = head;
    if (head == NULL)
        cout << "Queue is empty";
    else
    {
        cout << "Queue:\n";
        while (element != nullptr)
        {
            cout << element->data << ' ';
            element = element->next;
        }
        cout << '\n';
    }
}

void printStack(StackItem* head)
{
    cout << "Stack:\n";
    StackItem* element = head;
    while (element != nullptr)
    {
        cout << element->data << ' ';
        element = element->next;
    }
    cout << '\n';
}

int main()
{
    queue* first = NULL, * last = NULL;
    for (int i = 45; i <= 99; i += 2) pushQueue(first, last, i);
    printQueue(first);
    StackItem* top = nullptr;
    while (first != NULL)
    {
        if (first->data < 77)
        {
            top = pushStack(top, first->data);
            first = first->next;
            popQueue(first);
        }
        else {
            cout << first->data << endl;
            first = first->next;
        }
    }
    printStack(top);
    printQueue(first);
    return 0;
}