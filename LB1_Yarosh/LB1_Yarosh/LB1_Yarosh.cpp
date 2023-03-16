/* LB1_Yarosh.cpp : Вводити числа до списку, доки не введено число 999.
   Обчислити кількість додатних елементів, значення яких  менше 20-ти */

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
    int kol = 0;

    cout << "Enter the numbers:" << endl;
    do {
        c = new struct Node;
        c->next = NULL;
        cin >> c->data;
        if (head == NULL)
        {
            head = c;   end = c;
        }
        else                //Якщо список уже є
        {
            end->next = c; //записати його адресу до адресного поля останнього елемента
            end = c;      //перемістити вказівник end на новий елемент, бо він тепер останній
        }
    } while (c->data != 999);

    cout << "The list:" << endl;
    c = head;
    while (c != NULL)
    {
        cout << c->data << " ";
        c = c->next;
    }
    cout << endl;
    //Обчислення кількості
    c = head;
    while (c != NULL)
    {
        if (c->data > 0 && c->data < 20)
            kol++;
        c = c->next;
    }
    cout << "Quantity of positive elements less than twenty = " << kol << endl;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
    return 0;
}