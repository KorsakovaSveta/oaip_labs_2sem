
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
        cout << "\nМеню\n 1- С рекурсией\n 2 - Без рекурсии\n 0 - Выход  \n";
        cin >> kod;
        if (kod <= 0 || kod > 2)
            return 0;
        cout << "Введите число ступеней n= \n";
        cin >> n;
        switch (kod)
        {
        case 1:
        {
            result = Recursion(n);
            cout << "Результат: " << result;
            result = 0;
            break;
        }
        case 2:
        {

            cout << "Результат: " << NoRecursion(n);
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
