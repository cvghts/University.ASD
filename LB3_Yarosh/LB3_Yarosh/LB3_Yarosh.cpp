/* LB3_Yarosh.cpp : Вводити елементи, доки кількість від’ємних елементів не стане більшою за 3
Видалити зі списку всі значення, які менше 5*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void Add_Node(Node* &head, Node* &end)
{
    int kol=0;
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
        if(c->data < 0) 
        {
            kol++;
        }
    } while (kol !=3 );
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

/*Видаляє зі списку елемент, на який вказує ptr, 
повертає вказівник на елемент після видаленого*/
Node* deleteNodePtr(Node* &head, Node* &end, Node* ptr)
{
    if (ptr == NULL) return NULL;
    Node* c = head;
    if (ptr == head)
    {
        head = head->next;
        delete c; return head;
    }
    c = head;
    while (c->next != ptr && c != NULL) //Зупиняємось на елементі перед ptr або коли список закінчиться
        c = c->next;
    if (c == NULL) return NULL;
    c->next = ptr->next;  //Зв'язуємо c і ptr->next
    if (ptr == end) end = c;
    delete ptr;
    return c->next;
}

int main()
{
        Node* head = NULL, * end = NULL, * c, * ptr;
        cout << "Input the elements:" << endl;
            Add_Node(head, end);
            Print_List(head);
            cout << "\nRemove all values less than 5" << endl;
            c = head;
            while (c != NULL)
            {
                if (c->data < 5)
                {
                    c = deleteNodePtr(head, end, c);
                }
                else c = c->next;
            }
            cout << endl;
            Print_List(head);
            Free_Memory(head);
            return 0;
}