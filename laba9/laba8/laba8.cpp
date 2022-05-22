#include <iostream>
#include <cmath>
using namespace std;
double f(double);
double findRoot(double, double, double);
double f(double x)
{
	return pow(x, 2) - 10 * pow(sin(x), 2) + 2;
}
double findRoot(double x0, double eps, double q)
{
	double x1 = x0 - f(x0) * q / (f(x0) - f(x0 - q));
	while (fabs(x1 - x0) > eps)
	{
		x0 = x1;
		x1 = x1 - f(x1) * q / (f(x1) - f(x1 - q));
	} 
	return x0;
}
int main()
{
	double a = -1, b = 3, y, eps=0.000000001, x, h=0.1;
	for (x = a; x <= b; x += h)
	{
		if (f(x) * f(x + h) < 0)
		{
			cout << findRoot(x+h, eps, h) << "    " << f(findRoot(x + h, eps, h)) <<endl ;
		}
	}
	return 0;
}