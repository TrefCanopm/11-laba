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
		cout << "Enter the action number" << endl;
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
			cout << "Select the action number that is in the menu" << endl;
		}
	}
	delete list;
}

void Menu()
{
	cout << "\t Menu" << endl;
	cout << "1) Add an item to the top of the list" << endl;
	cout << "2) Add an item to the end of the list" << endl;
	cout << "3) Remove K items from the beginning of the list" << endl;
	cout << "4) Remove K items from the end of the list" << endl;
	cout << "5) Add to the elements from the entered number" << endl;
	cout << "6) Delete K elements from the entered number" << endl;
	cout << "7) Display the list on the screen" << endl;
	cout << "8) Finish working with the list" << endl;
}

void push_buck(List* list)
{
	list->size++;
	Node* node = new Node;
	cout << "Enter the data" << endl;
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
	cout << "Enter how many elements you need to delete" << endl;
	cin >> i;
	if (i >= list->size)
	{
		cout << "In the list, the number of items is less than or equal to the number of items to be deleted, so the entire list is deleted." << endl;
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
		cout << "Elements removed" << endl;
	}
}

void push_front(List* list)
{
	list->size++;
	Node* node = new Node;
	string str;
	cout << "Enter the data" << endl;
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
	cout << "Enter the number of items to delete" << endl;
	cin >> i;
	if (i >= list->size)
	{
		cout << "In the list, the number of items is less than or equal to the number of items to be deleted, so the entire list is deleted." << endl;
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
		cout << "Elements removed" << endl;
	}
}

void PushK(List* list)
{
	int i, n;
	string str;
	int k = 1;
	cout << "Enter the element from which to start adding elements to start adding" << endl;
	cin >> n;
	cout << "Enter the number of items to be entered" << endl;
	cin >> i;
	if ((n > list->size) && (n < 1))
	{
		cout << "There is no such item in the list" << endl;
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
			cout << "Enter the data" << endl;
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
	cout << "Enter the element from which to start deleting elements start adding" << endl;
	cin >> n;
	cout << "Enter the number of items to be entered" << endl;
	cin >> i;
	if ((n > list->size) && (n < 1))
	{
		cout << "There is no such item in the list" << endl;
	}
	else
	{
		if (i >= list->size)
		{
			cout << "In the list, the number of items is less than or equal to the number of items to be deleted, so the entire list is deleted." << endl;
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
			cout << "The list has been deleted" << endl;
		}
	}
	list->size = 0;
}