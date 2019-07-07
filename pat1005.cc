#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<string> m = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string num;
    getline(cin, num);
    int sum = 0;
    for (int i = 0; i < num.size(); ++i) {
        string n = num.substr(i, 1);
        sum += stoi(n);
    }
    string ssum = to_string(sum);
    printf("%s", m[stoi(ssum.substr(0, 1))].c_str());
    for (int i = 1; i < ssum.size(); ++i) {
        printf(" %s", m[stoi(ssum.substr(i, 1))].c_str());
    }
    printf("\n");
    return 0;
}