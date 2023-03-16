/* LB5_Yarosh.cpp : Створити лінійний двозв'язний список з цілих чисел.
Видалити зі списку перший елемент, більший числа 4.
Вставити в список число 10 перед кожним числом, рівним 15*/

#include <iostream>
using namespace std;
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

Node* InitList(int x)
{
	Node* c = new Node;
	c->next = NULL;
	c->prev = NULL;
	c->data = x;
	return c;
}

void AddNodeAfter(Node* &ptr, int x)
{
	if (ptr == NULL) {
		return;
	}
	else
	{
		Node* c = new Node;
		c->data = x;
		c->next = ptr->next;
		c->prev = ptr;
		if (ptr->next != NULL)
			ptr->next->prev = c;
		ptr->next = c;
		ptr = c;
	}
}

void AddNodeBefore(Node* &ptr, int x)
{
	if (ptr == NULL) {
		return;
	}
	else
	{
		Node* c = new Node;
		c->data = x;
		c->prev = ptr->prev;
		c->next = ptr;
		if (ptr->prev != NULL)
			ptr->prev->next = c;
		ptr->prev = c;
		ptr = c;
	}
}

void Print_Right(Node* head)
{
	cout << "The list from head to end:" << endl;
	if (head == NULL)
	{
		cout << "Empty" << endl; return;
	}
	Node* c = head;
	while (c != NULL)
	{
		cout << c->data << " ";
		c = c->next;
	}
	cout << endl;
}

Node* DeleteNode(Node* ptr)
{
	if (ptr == NULL) 
		return 0;
	Node* q = ptr->prev;
	if (ptr->next != NULL)
	{
		ptr->next->prev = q;
		if (q)
		{
			q->next = ptr->next;
			delete ptr;
			return q->next;
		}
		else
		{
			q = ptr->next;
			delete ptr;
			return q;
		}
	}
	else
	{
		q->next = NULL;
		delete ptr;
		return q;
	}
}

int main()
{
	Node* head = NULL, * end = NULL, * c;
	int x;
	cout << "Input 10 elements:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		if (i == 0)
		{
			head = end = InitList(x);
		}
		else
		{
			AddNodeAfter(end, x);
		}
	}
	c = head;
	if(c->data > 4)
	{
		if (c == head)
		{
			head = c = DeleteNode(c);
		}
		else
		{
			if (c == end)
			{
				end = c = DeleteNode(c);
			}
			else
			{
				c = DeleteNode(c);
			}
		}
	}
	cout << "Delete the first element greater than 4 from the list:" << endl;
	Print_Right(head);
	c = head;
	while (c != NULL)
	{
		if (c->data == 15)
		{
			AddNodeBefore(c, 10);
			c = c->next;
			if (c->next == NULL)
				end = c;
		}
		if (c != NULL)
		{
			c = c->next;
		}
	}
	cout << "Insert the number 10 before each number equal to 15 in the list:" << endl;
	Print_Right(head);
	return 0;
}
