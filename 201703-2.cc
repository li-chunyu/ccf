#include <iostream>
#include <limits>
#include <list>

using namespace std;

int main() {
    int n, m;
    list<int> queue;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i=0; i<n; ++i) {
        queue.push_back(i+1);
    }

    for (int i=0; i<m; ++i) {
        int p, q;
        cin >> p >> q;
        if (q == 0)
            continue;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        list<int>::iterator it;
        for (it = queue.begin(); it!=queue.end(); ++it) {
            if (*it == p)
                break;
        }
        if (q > 0) {
            list<int>::iterator tmp = it;
            for(int j=0; j<=q; ++j)
                ++tmp;
            queue.insert(tmp, *it);
            //queue.erase(it);
        } else {
            q = -q;
            list<int>::iterator tmp = it;
            for (int j=0; j<q; ++j)
                --tmp;
            queue.insert(tmp, *it);
        }
        queue.erase(it);
    }

    for (list<int>::iterator i=queue.begin(); i!=queue.end(); ++i) {
        cout << *i << " ";
    }

}