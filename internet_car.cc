#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int ndriver, npassenger;
    scanf("%d%d", &npassenger, &ndriver);
    vector<int> position(ndriver+npassenger, 0);
    vector<int> isdriver(ndriver+npassenger, 0);
    vector<int> driver(ndriver, 0);
    vector<int> processed(ndriver+npassenger, 0);
    int tmp;
    for (int i = 0; i < ndriver+npassenger; ++i) {
        scanf("%d", &tmp);
        position[i] = tmp;
    }
    for (int i = 0; i < ndriver+npassenger; ++i) {
        scanf("%d", &tmp);
        isdriver[i] = tmp;
        processed[i] = 1;
    }
    int nprocessed = 0;
    while (nprocessed != npassenger) {
        
    }

}