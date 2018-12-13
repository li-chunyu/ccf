#include <iostream>
using namespace std;

int main() {
    int mony;
    int a, b, c;
    cin >> mony;
    a = mony / 10;
    b = (a / 5) * 2;
    c = a % 5 / 3;
    cout << a + b + c;
    return 0;
}