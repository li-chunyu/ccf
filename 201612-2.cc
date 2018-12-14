#include <iostream>
#include <vector>

using namespace std;

float func(float a, float b, float T) {
    return (T-3500-b)/(1-a);
}

int main() {
    int T;
    vector<float> r;
    cin >> T;
    if (T < 3500) {
        cout << T;
        return 0;
    }

    // block 1
    r.push_back(3500 + func(0.03, 0, T));
    
    // block 2
    r.push_back(3500 + func(0.1, 105, T));

    // block 3
    r.push_back(3500 + func(0.2, 555, T));

    // block 4
    r.push_back(3500 + func(0.25, 1005, T));

    // block 5
    r.push_back(3500 + func(0.3, 2755, T));

    // block 6
    r.push_back(3500 + func(0.35, 5505, T));

    // block 7
    r.push_back(3500 + func(0.45, 13505, T));

    for (int i=0; i<r.size(); ++i) {
        if (int(r[i]) == r[i]){
            if ((int(r[i]) % 100) == 0 && r[i] >= T)
                cout << r[i] << endl;
        }
    }
}