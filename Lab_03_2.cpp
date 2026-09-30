// Джамалов Олександр Олегович, РІ-11
// Лабораторна робота 3.2, варіант 7
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double a, b, c, x;
    cout << "a b c x = ";
    if (!(cin >> a >> b >> c >> x) || !isfinite(a)
        || !isfinite(b) || !isfinite(c) || !isfinite(x))
    {
        cerr << "Invalid input\n";
        return 1;
    }

    // При c = 0 друга гілка існує лише для x > 5.
    if (c == 0.0 && x <= 5.0)
    {
        cerr << "Function is undefined: division by zero\n";
        return 1;
    }

    const bool p = x < 5.0 && c != 0.0;
    const bool q = x > 5.0 && c == 0.0;
    double f1 = 0.0, f2 = 0.0;

    // Спосіб 1: лише скорочена форма розгалуження.
    if (p)
        f1 = -a * x * x - b;
    if (q)
        f1 = (x - a) / x;
    if (!p && !q)
        f1 = -x / c;

    // Спосіб 2: лише повна форма розгалуження.
    if (p)
        f2 = -a * x * x - b;
    else
    {
        if (q)
            f2 = (x - a) / x;
        else
            f2 = -x / c;
    }

    if (!isfinite(f1) || !isfinite(f2))
    {
        cerr << "Numerical overflow\n";
        return 1;
    }
    cout << fixed << setprecision(10);
    cout << "F1 = " << f1 << "\nF2 = " << f2 << '\n';
    cout << "difference = " << abs(f1 - f2) << '\n';
    return 0;
}
