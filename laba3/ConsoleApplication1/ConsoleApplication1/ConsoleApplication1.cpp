
#include <iostream>
using namespace std;
float Recursion(int);
float NoRecursion(int);

int main()
{
    setlocale(LC_ALL, "RUs");
    int n, kod;
    float result = 0;
    while (true)
    {
        cout << "\n����\n 1- � ���������\n 2 - ��� ��������\n 0 - �����  \n";
        cin >> kod;
        if (kod <= 0 || kod > 2)
            return 0;
        cout << "������� ����� �������� n= \n";
        cin >> n;
        switch (kod)
        {
        case 1:
        {
            result = Recursion(n);
            cout << "���������: " << result;
            result = 0;
            break;
        }
        case 2:
        {

            cout << "���������: " << NoRecursion(n);
            break;
        }
        }
    }
}
    float Recursion(int n)
    {
        if (n == 0) return 0;
        return 1 / (1 + Recursion(n - 1));
    }
    float NoRecursion(int n)
    {
       float result = 0;
        for (int i = n; i > 0; i--)
         result = 1 / (1 + result);
        return result;
    }
