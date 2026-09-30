// Джамалов Олександр Олегович, РІ-11
// Лабораторна робота 3.3, варіант 7
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double x, r;
    cout << "x R = ";
    if (!(cin >> x >> r) || !isfinite(x) || !isfinite(r))
    {
        cerr << "Invalid input\n";
        return 1;
    }
    if (r <= 0.0 || r >= 6.0)
    {
        cerr << "R must satisfy 0 < R < 6\n";
        return 1;
    }

    double y;
    if (x < -r)
        y = r;
    else if (x <= r)
    {
        // Стійкий запис R - sqrt(R*R - x*x).
        const double t = x / r;
        double radicand = 1.0 - t * t;
        if (radicand < 0.0)
            radicand = 0.0;
        y = r * (1.0 - sqrt(radicand));
    }
    else if (x <= 6.0)
        y = r - (r + 3.0) * (x - r) / (6.0 - r);
    else
        y = x - 9.0;

    if (!isfinite(y))
    {
        cerr << "Numerical overflow\n";
        return 1;
    }
    cout << fixed << setprecision(10) << "y = " << y << '\n';
    return 0;
}
