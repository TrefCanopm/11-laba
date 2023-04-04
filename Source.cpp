#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Node
{
	string a;
	Node* next = nullptr;
};
struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
	size_t size = 0;
};

void Menu();

bool Chek(List* list);

void push_buck(List* list);
void del_buck(List* list);

void push_front(List* list);
void del_front(List* list);

void PushK(List* list);
void DelK(List* list);

void DelList(List* list);
void CoutList(List* list);

int main()
{
	setlocale(0, "RUS");
	SetConsoleCP(1251);
	List* list = new List;
	int i;
	bool F = 1;
	while (F)
	{
		Menu();
		cout << "Введите номер действия" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			system("cls");
			push_front(list);
			break;
		}
		case 2:
		{
			system("cls");
			push_buck(list);
			break;
		}
		case 3:
		{
			system("cls");
			del_front(list);
			break;
		}
		case 4:
		{
			system("cls");
			del_buck(list);
			break;
		}
		case 5:
			system("cls");
			PushK(list);
			break;
		case 6:
			system("cls");
			DelK(list);
			break;
		case 7:
		{
			system("cls");
			CoutList(list);
			break;
		}
		case 8:
			F = 0;
		default:
			cout << "Выберете номер действия который есть в меню" << endl;
		}
	}
	delete list;
}

void Menu()
{
	cout << "\t Меню" << endl;
	cout << "1) Добавить элемент в начло списка" << endl;
	cout << "2) Добавить элемент в конец списка" << endl;
	cout << "3) Удалить К элементов из начала списка" << endl;
	cout << "4) Удалить К элементов из конца списка" << endl;
	cout << "5) Добавить К элементов с введёного номера" << endl;
	cout << "6) Удолить К элементов с введёного номера" << endl;
	cout << "7) Вывести список на экран" << endl;
	cout << "8) Законьчить работу со списком" << endl;
}

void push_buck(List* list)
{
	list->size++;
	Node* node = new Node;
	cout << "Введите данные" << endl;
	getline(cin>>ws, node->a);
	if (Chek(list))
	{
		list->tail->next = node;
		list->tail = node;
	}
	else
	{
		list->head = node;
		list->tail = node;
	}
}
void del_buck(List* list) 
{
	int i;
	int n;
	cout << "Введите сколько элементов нужно удолить" << endl;
	cin >> i;
	if (i >= list->size)
	{
		cout << "В списке количество элементов меньше или равно, количеству элементов которые надо удолить, поэтому удоляется весь список." << endl;
		DelList(list);
	}
	else
	{
		n = 1;
		Node* temp = list->head;
		while (n < list->size - i)
		{
			n++;
			temp = temp->next;
		}
		list->size = list->size - i;
		list->tail = temp;
		temp = temp->next;
		while (i > 0)
		{
			Node* temp1 = temp;
			temp = temp->next;
			delete temp1;
			i--;
		}
		delete temp;
		cout << "Элементы удалены" << endl;
	}
}

void push_front(List* list)
{
	list->size++;
	Node* node = new Node;
	string str;
	cout << "Введите данные" << endl;
	getline(cin>>ws, str);
	node->a = str;
	if (Chek(list))
	{
		node->next = list -> head;
		list->head = node;
	}
	else
	{
		list->head = node;
		list->tail = node;
	}
}
void del_front(List* list)
{
	int i;
	cout << "" << endl;
	cin >> i;
	if (i >= list->size)
	{
		cout << "В списке количество элементов меньше или равно, количеству элементов которые надо удолить, поэтому удоляется весь список." << endl;
		DelList(list);
	}
	else
	{
		list->size = list->size - i;
		while (i > 0)
		{
			Node* temp;
			temp = list->head;
			list->head = list->head->next;
			delete temp;
			i--;
		}
		cout << "Элементы удолены" << endl;
	}
}

void PushK(List* list)
{
	int i, n;
	string str;
	int k = 1;
	cout << "Введите элемент с которого начнётся добавление элементов начать добавление" << endl;
	cin >> n;
	cout << "Введите количество вводимых элементов" << endl;
	cin >> i;
	if ((n > list->size) && (n < 1))
	{
		cout << "Такого элемента нет в списке" << endl;
	}
	else
	{
		Node* temp;
		Node* temp1;
		temp = list->head;
		while (k < n)
		{
			temp = temp->next;
			k++;
		}
		temp1 = temp->next;
		list->size = list->size + i;
		while (i > 0)
		{
			Node* node = new Node;
			cout << "Введите данные" << endl;
			getline(cin >> ws, str);
			node->a = str;
			temp->next = node;
			temp = node;
			i--;
		}
		temp->next = temp1;
	}
}
void DelK(List* list)
{
	int i, n;
	int k = 1;
	cout << "Введите элемент с которого начнётся удоление элементов начать добавление" << endl;
	cin >> n;
	cout << "Введите количество вводимых элементов" << endl;
	cin >> i;
	if ((n > list->size) && (n < 1))
	{
		cout << "Такого элемента нет в списке" << endl;
	}
	else
	{
		if (i >= list->size)
		{
			cout << "В списке количество элементов меньше или равно, количеству элементов которые надо удолить, поэтому удоляется весь список." << endl;
			DelList(list);
		}
		else
		{
			Node* temp;
			Node* temp1;
			temp = list->head;
			while (k < n-1)
			{
				temp = temp->next;
				k++;
			}
			temp1 = temp->next;
			list->size = list->size - i;
			i--;
			while (i > 0)
			{
				Node* temp2;
				temp2 = temp1;
				temp1 = temp1->next;
				i--;
				delete temp2;
			}
			temp->next = temp1;
		}
	}
}

bool Chek(List* list)
{
	if (list->head == nullptr)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void CoutList(List* list)
{
	int i = 1;
	int n = list->size;
	Node* temp = list->head;
	if (Chek(list))
	{
		while (n > 0)
		{
			cout <<i << ") "<< temp->a << endl;
			temp = temp->next;
			i++;
			n--;
		}
	}
}
void DelList(List* list)
{
	bool F = 1;
	while (F)
	{
		Node* temp;
		if (list->head != NULL)
		{
			temp = list->head;
			list->head = list->head->next;
			delete temp;
		}
		else
		{
			F = 0;
			cout << "Список удалён" << endl;
		}
	}
	list->size = 0;
}