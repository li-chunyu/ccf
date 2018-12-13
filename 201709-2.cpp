#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include <cstdlib>

using namespace std;


typedef struct key {
    int id;
    int time;
    int flag;
    key(int _id, int _time, int _flag=0):id(_id), time(_time), flag(_flag){}
} key;

bool compare(key *k1, key *k2) {
    if (k1->time != k2->time) {
        return k1->time < k2->time;
    } 
    else if (k1->flag != k2->flag) {
        return k1->flag > k2->flag;
    }
    else {
        return k1->id < k2->id;
    }
}

int main() {
    int n, k;
    vector<key*> v;
    cin >> n >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<int> hook(n, -1);
    for (int i=0; i<n; ++i) {
        hook[i] = i + 1;
    }
    for (int i=0; i<k; i++){
        int id, s, d;
        cin >> id >> s >> d;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        key *tmp = new key(id, s, 0);
        v.push_back(tmp);
        key * tmp = new key(id, s+d, 1);
        v.push_back(tmp);
    }
    sort()



    
}