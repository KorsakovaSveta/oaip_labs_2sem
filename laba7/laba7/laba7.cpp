#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
using namespace std;
struct Tree
{
    string FIO;
    long long int Pasport;
    Tree* left, * right;
} *root;


Tree* Create(string, long long int);
void Add_List(Tree*, string, long long int);
void View_Tree(Tree*, int);
Tree* search(Tree*, long long int);
Tree* Del_Info(Tree*, long long int);
void Delete(Tree*);
Tree* Make_Blns(Tree*&, vector<Tree*>&, int, int);
void GetElems(Tree*, vector<Tree*>&);
void BubbleSort(vector<Tree*>&);
void Print(Tree*, bool);

Tree* Create(string fio, long long int pasport)
{
    Tree* elem = new Tree;
    elem->FIO = fio;
    elem->Pasport = pasport;
    elem->left = elem->right = NULL;
    return elem;
}
void Add_List(Tree* root, string fio, long long int pasport)
{
    Tree* prev=NULL, * elem;
    bool find = true;
    elem = root;
    while (elem && find)
    {
        prev = elem;
        if (pasport == elem->Pasport)
        {
            find = false;
            cout << "Не уникальная информация!";
        }
        else
        {
            if (pasport < elem->Pasport)
                elem = elem->left;
            else
                elem = elem->right;
        }
    }
    if (find)
    {
        elem = Create(fio, pasport);
        if (pasport < prev->Pasport)
            prev->left = elem;
        else
            prev->right = elem;
    }
}
void View_Tree(Tree *subtree, int level)
{
    string str1, str2, str3;
    if (subtree)
    {
        View_Tree(subtree->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            cout << "                       ";
        }
        cout << subtree->FIO << "  " << subtree->Pasport << endl;
        View_Tree(subtree->left, level + 1);
    }
}

Tree *search(Tree *root, long long int key)
{
    Tree *elem = root;
    while (elem)
    {
        if (elem->Pasport > key)
            elem = elem->left;
        else
            if (elem->Pasport < key)
                elem = elem->right;
            else
                return elem;
    }
    return elem;
}

Tree* Del_Info(Tree* root, long long int key)
{
    Tree *Del, *Prev_Del, *ReplaceElem, *Prev_Replace;
    Del = root;
    Prev_Del = NULL;
    while (Del != NULL && Del->Pasport != key) 
    {
        Prev_Del = Del;
        if (Del->Pasport > key)  Del = Del->left;
        else Del = Del->right;
    }
    if (Del == NULL) 
    {				// Элемент не найден
        cout << "NOT Key!";
        return root;
    }
    if (Del->right == NULL) ReplaceElem = Del->left;
    else
        if (Del->left == NULL) ReplaceElem = Del->right;
        else {
            Prev_Replace = Del;
            ReplaceElem = Del->left;
            while (ReplaceElem->right != NULL)
            {
                Prev_Replace = ReplaceElem;
                ReplaceElem= ReplaceElem->right;
            }
            if (Prev_Replace == Del)  ReplaceElem->right = Del->right;
            else {
                ReplaceElem->right = Del->right;
                Prev_Replace->right = ReplaceElem->left;
                ReplaceElem->left = Prev_Replace;
            }
        }
    if (Del == root) root = ReplaceElem;			
        if (Del->Pasport < Prev_Del->Pasport)
            Prev_Del->left = ReplaceElem;			
        else	Prev_Del->right = ReplaceElem;			
    delete Del;
    return root;
}

void Delete(Tree *elem)
{
    if (elem != NULL)
    {
        Delete(elem->left);
        Delete(elem->right);
        delete elem;
    }
}
Tree* Make_Blns(Tree*& elem, vector<Tree*>& elems, int k, int n)
{
    if(k == -1) k = elems.size(), elem = elems[k/2];
    if (n == k) 
        return NULL;
    int m = (n + k) / 2;
    elems[m]->left = Make_Blns(elem, elems, m ,n);
    elems[m]->right = Make_Blns(elem, elems, k, m+1);
    return elems[m];
}
void GetElems(Tree *elem, vector<Tree*> &elems)
{
    if (!elem)
        return;
    elems.push_back(elem);
    GetElems(elem->left, elems);
    GetElems(elem->right, elems);
}
void BubbleSort(vector<Tree*>& elems)
{
    int size = elems.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (elems[i]->Pasport > elems[j]->Pasport)
            {
                Tree* temp = elems[i];
                elems[i] = elems[j];
                elems[j] = temp;
            }
        }
    }
}
void Print(Tree *elem, bool p)
{
    if (!elem) return;
    if (!p) cout << elem->FIO << " " << elem->Pasport << ", ";
    Print(elem->left, p);
    Print(elem->right, p);
    if (p) cout << elem->FIO << " " << elem->Pasport << ", ";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string FIO;
    Tree* keypasport;
    long long int Pasport;
    int kod;
    vector<Tree*>elems;
    setlocale(LC_ALL, "rus");
    do
    {
        cout << "\nМеню\n Создание-1\n Добавление-2\n Посмотр-3\n Поиск-4\n Удаление по ключу-5\n Удаление дерева-6\n Балансировка-7\n Распечатать информацию прямым обходм-8\n Распечатать информацию обратным обходом-9\n Распечатать информацию в порядке возрастания ключа-10\n Задание-11\n Выход - 0\n";
        cin >> kod;
        switch (kod)
        {
        case 1:
        {
            if (root != NULL)
            {
                cout << "Очистите память\n";
                break;
            }
            cout << "Введите корень\n";
            cin.get();
            getline(cin, FIO);
            cin >> Pasport;
            root = Create(FIO, Pasport);
            cout << "Создан корень дерева" << endl;
            break;
        }
        case 2:
        {
            cout << "Введите запись:\n";
            cin.get();
            getline(cin, FIO);
            cin >> Pasport;
            Add_List(root, FIO, Pasport);
            cout << "Запись добавлена\n";
            break;
        }
        case 3:
        {
            View_Tree(root, 0);
            break;
        }
        case 4:
        {
            
            cout << "Введите искомый узел" << endl;
            cin >> Pasport;
            keypasport = search(root, Pasport);
            if (keypasport)
                cout << keypasport->FIO;
            else 
                cout << "Элемент не найден\n";
            break;
        }
        case 5:
        {
            cout << "Введите искомый узел" << endl;
            cin >> Pasport;
            root = Del_Info(root, Pasport);
            break;
        }
        case 6:
        {
            Delete(root);
            root = NULL;
            cout << "Дерево очищено\n";
            break;
        }
        case 7:
        {
            GetElems(root, elems);
            BubbleSort(elems);
            Make_Blns(root, elems, -1, 0);
            break;
        }
        case 8:
        {
            Print(root, false);
            break;
        }
        case 9:
        {
            Print(root, true);
            break;
        }
        case 10:
        {
            GetElems(root, elems);
            BubbleSort(elems);
            for (auto item : elems)
            {
                cout << item->FIO << " " << item->Pasport << ", ";
            }
            break;
        }
        case 11:
        {
            int count = 0;
            GetElems(root, elems);
            for (auto item : elems)
                if (item->Pasport > root->Pasport)
                    count++;
            cout << "Количество записей в правой части дерева" << count << endl;
            break;
        }
        }
    } while (kod >= 1 && kod <= 11);
}
