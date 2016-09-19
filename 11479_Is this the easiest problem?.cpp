#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        if (a <= 0 || b <= 0 || c <= 0) cout << "Invalid";
        else if (a + b <= c || a + c <= b || b + c <= a) cout << "Invalid";
        else if (a == b && b == c) cout << "Equilateral";
        else if (a == b || a == c || b == c) cout << "Isosceles";
        else cout << "Scalene";
        cout << "\n";
    }
}
