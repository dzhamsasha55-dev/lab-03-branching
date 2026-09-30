// Джамалов Олександр Олегович, РІ-11
// Лабораторна робота 3.1, варіант 7
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double x;
    cout << "x = ";
    if (!(cin >> x) || !isfinite(x))
    {
        cerr << "Invalid input\n";
        return 1;
    }

    const double base = x * x * sin(x / 2.0);
    double y1 = 0.0, y2 = 0.0;

    // Спосіб 1: лише скорочена форма розгалуження.
    if (x <= -5.0)
        y1 = base + atan(exp(x));
    if (x > -5.0 && x <= 0.0)
        y1 = base + 1.0 + x * x * x / 4.0;
    if (x > 0.0)
        y1 = base + log(abs(x)) - x / 5.0;

    // Спосіб 2: лише повна форма розгалуження.
    if (x <= -5.0)
        y2 = base + atan(exp(x));
    else
    {
        if (x <= 0.0)
            y2 = base + 1.0 + x * x * x / 4.0;
        else
            y2 = base + log(abs(x)) - x / 5.0;
    }

    if (!isfinite(y1) || !isfinite(y2))
    {
        cerr << "Numerical overflow\n";
        return 1;
    }
    cout << fixed << setprecision(10);
    cout << "y1 = " << y1 << "\ny2 = " << y2 << '\n';
    cout << "difference = " << abs(y1 - y2) << '\n';
    return 0;
}
