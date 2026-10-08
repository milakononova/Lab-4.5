
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    double x, y, R, a, b;
    double M;
    bool A, B;

    cout << "Enter R: ";
    cin >> R;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    if (R <= 0 || a <= 0 || b <= 0)
    {
        cout << "Invalid parameters!" << endl;
    }
    else
    {
        srand((unsigned)time(0));
        M = max(R, max(a, b));

        cout << fixed << setprecision(3);

        // Method 1: 10 manually entered points
        cout << "METHOD 1" << endl;

        for (int i = 1; i <= 10; i++)
        {
            cout << "Point " << i << endl;

            cout << "Enter x: ";
            cin >> x;
            cout << "Enter y: ";
            cin >> y;

            A = (x >= 0 && x <= a &&
                y >= 0 && y <= b &&
                x * x + y * y >= R * R);

            B = (x <= 0 && y <= 0 &&
                x * x + y * y <= R * R);

            if (A || B)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }

        // Method 2: 10 random points
        cout << "METHOD 2" << endl;

        for (int i = 1; i <= 10; i++)
        {
            x = -M + 2 * M * rand() / RAND_MAX;
            y = -M + 2 * M * rand() / RAND_MAX;

            A = (x >= 0 && x <= a &&
                y >= 0 && y <= b &&
                x * x + y * y >= R * R);

            B = (x <= 0 && y <= 0 &&
                x * x + y * y <= R * R);

            cout << "Point " << i
                << ": x=" << x
                << ", y=" << y;

            if (A || B)
            {
                cout << " YES" << endl;
            }
            else
            {
                cout << " NO" << endl;
            }
        }
    }

    return 0;
}
