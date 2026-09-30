// Джамалов Олександр Олегович, РІ-11
// Лабораторна робота 3.4, варіант 7
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    double x, y, r;
    cout << "x y R = ";
    if (!(cin >> x >> y >> r) || !isfinite(x)
        || !isfinite(y) || !isfinite(r))
    {
        cerr << "Invalid input\n";
        return 1;
    }
    if (r <= 0.0)
    {
        cerr << "R must be positive\n";
        return 1;
    }

    // Нормовані координати; центр круга (-R, R).
    const double u = x / r;
    const double v = y / r;
    const bool inCircle = hypot(u + 1.0, v - 1.0) <= 1.0;
    const bool inRectangle = u >= 0.0 && u <= 2.0
                             && v >= -1.0 && v <= 0.0;

    // Межі круга та прямокутника входять до області.
    if (inCircle || inRectangle)
        cout << "Point belongs to the region\n";
    else
        cout << "Point does not belong to the region\n";
    return 0;
}
