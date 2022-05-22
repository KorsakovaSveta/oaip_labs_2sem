#include <iostream>
#include <ctime>
using namespace std;
struct stack {
	stack* next;
	int data;
}*head, * a, * p;
stack* add(stack**, int);
void view(stack*);
void Delete(stack*&);
void deleteStack(stack*&);
void sort_1(stack**);
void sort_info(stack*);

stack* add(stack** head, int value)
{
	stack* node = new stack;
	node->data = value;
	node->next = (*head);
	(*head) = node;
	return node;
}

void view(stack* head)
{
	a = head;
	cout << "Элементы списка: " << endl;
	do
	{
		cout << a->data << " ";
		a = a->next;
	} while (a != NULL);
}
void Delete(stack*& head)
{
	
	stack* curr = head->next;
	delete head;
	head = curr;
	
}
void deleteStack(stack*& head)
{
	string result = "";
	while (head)
		Delete(head);
}
void sort_1(stack** head)
{
	add(head, 1);
	stack *elem0 = NULL, *elem1, *elem2;
	if ((*head)->next->next == NULL)
		return;
	do
	{
		for (elem1 = *head;  elem1->next->next != elem0; elem1 = elem1->next)
			if (elem1->next->data > elem1->next->next->data)
			{
				elem2 = elem1->next->next;
				elem1->next->next = elem2->next;
				elem2->next = elem1->next;
				elem1->next = elem2;
			}
			elem0 = elem1->next;
		
	} while ((*head)->next->next != elem0);
	Delete(*head);
}

void sort_info(stack* head)
{
	
	stack *elem0 = NULL, *elem1;
	int data;
	do
	{
		for (elem1 = head; elem1->next != elem0; elem1 = elem1->next)
			if (elem1->data > elem1->next->data)
			{
				data = elem1->data;
				elem1->data = elem1->next->data;
				elem1->next->data = data;
			}
		elem0 = elem1;

	} while (head->next != elem0);
}

int main()
{
	stack* head = NULL;
	int kod, numberOfelements, data;
	setlocale(LC_ALL, "rus");
	do
	{
		cout << "\nМеню\n Создание-1\n Добавление-2\n Посмотр-3\n Индивидуальное задание-4\n Удалить список-5\n Сортировка 1 методом-6\n Сортировка 2 методом-7\n";
		cin >> kod;
		switch (kod)
		{
		case 1: case 2:
		{
			if (kod == 1 && head != NULL)
			{
				cout << "Очистите память\n";
				break;
			}
			srand(time(NULL));
			if (kod == 1)
				cout << "Количество элементов в списке\n";
			if (kod == 2)
				cout << "Количество добавляемых в список элементов\n";
			cin >> numberOfelements;
			for (int i = 0; i < numberOfelements; i++)
			{
				data = rand() % 41 - 20;
				head = add(&head, data);
			}
			if (kod == 1)
				cout << "Создан список из " << numberOfelements << " элементов\n";
			else
				cout << "В спиок добавлено " << numberOfelements << " элементов\n";
			break;
		}

		case 3:
		{
			if (!head)
			{
				cout << "Список пуст\n";
				break;
			}
			view(head);
			break;
		}

		case 4:
		{
			stack** curr = &head;
			while (*curr)
			{
				if ((*curr)->data % 2 != 0)
					Delete(*curr);
				else
					curr = &(*curr)->next;
			}
			cout << "\nНечётные элементы удалены\n";
			break;
		}

		case 5:
		{
			deleteStack(head);
			cout << "\nСписок удалён\n";
			break;
		}
		case 6:
		{
			
			sort_1(&head);
			cout << "\nСписок отсортирован\n";
			break;
		}

		case 7:
		{
			sort_info(head);
			cout << "\nСписок отсортирован\n";
			break;
		}
		}
	} while (kod >= 1 && kod <= 7);

}