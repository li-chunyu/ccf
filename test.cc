#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<vector<int> > v(10, vector<int>(10, 0));
    cout << v.at(100).at(9) << endl;

}