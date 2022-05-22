#include <iostream>
using namespace std;
struct DoubleList
{
	int data;
	DoubleList* next;
	DoubleList* prev;
};
void Creat(DoubleList**, DoubleList**, int);
void AddToTheBeginOfList(DoubleList**, int);
void AddToTheEndOfList(DoubleList**, int);
void ViewingFromTheBeginingOfTheList(DoubleList*);
void ViewingFromTheEndOfTheList(DoubleList*);
void Delete(DoubleList*&);
void deleteList(DoubleList*&);
void DeleteOdd(DoubleList**, DoubleList**);
void Creat(DoubleList** b, DoubleList** e, int value)
{
	DoubleList* node = new DoubleList;
	node->data = value;
	node->next = NULL;
	node->prev = NULL;
	*b = *e = node;
}

void AddToTheBeginOfList(DoubleList** b, int value)
{
	DoubleList* node = new DoubleList;
	node->data = value;
	node->prev = NULL;
	node->next = *b;
	(*b)->prev = node;
	*b = node;
}

void AddToTheEndOfList(DoubleList** e, int value)
{
	DoubleList* node = new DoubleList;
	node->data = value;
	node->next = NULL;
	node->prev = *e;
	(*e)->next = node;
	*e = node;
}

void ViewingFromTheBeginingOfTheList(DoubleList* b)
{
	DoubleList* a = new DoubleList;
	a = b;
	cout << "�������� ������: " << endl;
	do
	{
		cout << a->data << " ";
		a = a->next;
	} while (a != NULL);
}

void ViewingFromTheEndOfTheList(DoubleList* e)
{
	DoubleList* a = new DoubleList;
	a = e;
	cout << "�������� ������: " << endl;
	do
	{
		cout << a->data << " ";
		a = a->prev;
	} while (a != NULL);
}

void Delete(DoubleList*& b)
{
	DoubleList* curr = b->next;
	delete b;
	b = curr;
}

void deleteList(DoubleList*& b)
{
	while (b)
		Delete(b);
}

void DeleteOdd(DoubleList** b, DoubleList** e)
{
	DoubleList* curr = *b;
	DoubleList* elem = *b;
	do
	{
		if (curr->data % 2 != 0)
		{
			if (curr == *b)
			{
				*b = curr->next;
				(*b)->prev = NULL;
			}
			else
			{
				curr->prev->next = curr->next;
				if (curr->next != NULL) curr->next->prev = curr->prev;

			}
			if (curr->next == NULL)
				*e = curr->prev;
			elem = curr;
			curr = curr->next;
			delete elem;
		}
		else
			curr = curr->next;
	} while (curr != NULL);
}

int main()
{
	DoubleList *elem = NULL;
	DoubleList *begin = NULL, *end = NULL;
	int kod, value;
	setlocale(LC_ALL, "rus");
	do
	{
		cout << "\n����\n ��������-1\n ���������� � ������-2\n ���������� � �����-3\n ������� � ������ ������-4\n �������� � ����� ������-5\n ������� ������-6\n �������������� �������-7\n ����� - 0\n";
		cin >> kod;
		switch (kod)
		{
		case 1:
		{
			if (begin != NULL)
			{
				cout << "�������� ������\n";
				break;
			}
			cout << "������ �������\n";
			cin >> value;
			Creat(&begin, &end, value);
			cout << "������ ������ ������� ������: " << begin->data << endl;
			break;
		}
		case 2:
		{
			cout << "������� �������� ��������:\n";
			cin >> value;
			AddToTheBeginOfList(&begin, value);
			cout << "������� �������� � ������ ������\n";
			break;
		}
		case 3:
		{
			cout << "������� �������� ��������:\n";
			cin >> value;
			AddToTheEndOfList(&end, value);
			cout << "������� �������� � ����� ������\n";
			break;
		}
		case 4:
		{
			ViewingFromTheBeginingOfTheList(begin);
			break;
		}
		case 5:
		{
			ViewingFromTheEndOfTheList(end);
			break;
		}
		case 6:
		{
			deleteList(begin);
			cout << "������ ������";
			break;
		}
		case 7:
		{
			DeleteOdd(&begin, &end);
			break;
		}
		}
	} while (kod >= 1 && kod <= 7);
}