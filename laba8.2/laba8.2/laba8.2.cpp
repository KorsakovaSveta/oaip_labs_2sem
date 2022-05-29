#include <Windows.h>
#include <iostream>
using namespace std;
double fun1(double);
double fun2(double, int);
double fun1(double x)
{
    return -log(sqrt(1 + pow(x, 2))) + x * atan(x);
}
double fun2(double x, int n)
{
    double Sum, t, s;
    Sum = 0;
    for (int k = 1; k <= n; k++)
    {
        t = pow(-1, (k + 1)) * pow(x, 2 * k);
        s = t / (2 * k * (2 * k - 1));
        Sum += s;
    }
    return Sum;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    double y_min, y_max;
    int kod;
    float a, b, h, x, n;

    cout << "Выберите функцию\n";
    cin >> kod;
    switch (kod)
    {
    case 1: fun1; break;
    case 2: fun2; break;
    }

    if (kod == 1)
    {
        cout << "Введите a, b, h\n";
        cin >> a >> b >> h;
    }
    else
    {
        cout << "Введите a, b, h, n\n";
        cin >> a >> b >> h >> n;
    }
    HDC hDC = GetDC(GetConsoleWindow());
    HPEN Pen = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
    SelectObject(hDC, Pen);
    MoveToEx(hDC, 50, 335, NULL);
    LineTo(hDC, 250, 335);
    MoveToEx(hDC, 155, 250, NULL);
    LineTo(hDC, 155, 420);
    HPEN Pen1 = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));
    SelectObject(hDC, Pen1);
    MoveToEx(hDC, 50, 335, NULL);
    LineTo(hDC, 155, 250);
    MoveToEx(hDC, 155, 250, NULL);
    LineTo(hDC, 250, 335);
    MoveToEx(hDC, 250, 335, NULL);
    LineTo(hDC, 155, 420);
    MoveToEx(hDC, 155, 420, NULL);
    LineTo(hDC, 50, 335);
    HPEN Pen3 = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
    SelectObject(hDC, Pen3);
    if (kod == 1)
    {
        for (x = a; x <= b; x += h)  // O(155,335) - center
        {
            MoveToEx(hDC, 10 * x + 155, -10 * fun1(x) + 335, NULL);//10 - scale
            LineTo(hDC, 10 * x + 155, -10 * fun1(x) + 335);
        }
    }
    else
    {
        for (x = a; x <= b; x += h)  // O(155,335) - center
        {
            MoveToEx(hDC, 30 * x + 155, -30 * fun2(x, n) + 335, NULL);//30 - scale
            LineTo(hDC, 30 * x + 155, -30 * fun2(x, n) + 335);
        }
    }
    return 0;
}