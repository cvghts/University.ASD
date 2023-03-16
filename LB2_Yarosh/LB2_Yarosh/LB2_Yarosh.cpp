/* LB2_Yarosh.cpp : Ввести 10 елементів.
   Обчислити кількість елементів, що перевищують середнє арифметичне всіх елементів */

#include <iostream>
using namespace std;

struct Node
{
    double data;
    Node* next;
};

int main()
{
    Node* head = NULL;
    Node* c;
    Node* end = NULL;
    double sum = 0, ser=0;
    int kol = 0;

    cout << "Enter 10 elements:" << endl;
    for (int i = 1; i <= 10; i++)
    {
        c = new struct Node;
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
    }
    cout << "The list:" << endl;
    c = head;
    while (c != NULL)
    {
        cout << c->data << " ";
        c = c->next;
    }
    cout << endl;
    c = head; 
    while (c != NULL)   
    {  
        sum += c->data; 
        c = c->next;
    }
    ser = sum / 10;
    c = head;
    while (c != NULL)
    {
        if (c->data > ser)   
            kol++;
        c = c->next;
    }
    cout << "Sum of elements = " << sum << endl;
    cout << "Arithmetic average of elements = " << ser << endl;
    cout << "Number of elements = " << kol << endl;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
    return 0;
}
