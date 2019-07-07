#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    int N = 0, time = 0;
    vector<int> f;
    f.push_back(0);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int input;
        scanf("%d", &input);
        f.push_back(input);
    }
    int move_time = 0, distance = 0;
    for (int i = 1; i < f.size(); ++i) {
        distance = f[i] - f[i-1];
        if (distance > 0)
            move_time = 6;
        else
            move_time = 4;
        time += (5 + abs(distance)*move_time);
    }
    printf("%d\n", time);
    return 0;
}