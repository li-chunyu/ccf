#include <iostream>
#include <limits>
using namespace std;

int main() {
    int cur, n;
    int t = -1;
    int cnt = 0;
    cin >> n;
    for (int i=0; i<n; ++i) {
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> cur;
        if (cur != t) {
            cnt += 1;
            t = cur;
        }
    }
    cout << cnt << endl;
}