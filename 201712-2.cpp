#include <iostream>
#include <list>
#include <vector>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i=1; i<=n; ++i) {
        v.push_back(i);
    }

    int call = 1;
    int index = 0;
    while(n != 1) {
        while (v[index] == -1) {
           index = (index+1) % v.size(); 
        }
        if ((call%k) == 0 || (call%10) == k) {
            v[index] = -1;
            n -= 1;
        }
        index = (index+1) % v.size();
        call++;
    }
    int re;
    for (int i=0; i<v.size(); ++i) {
        if (v[i] != -1) {
            re = i+1;
        }
    }
    cout << re << endl;
}