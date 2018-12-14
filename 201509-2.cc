/*
 * @Description: 201509-2
 * @Author: lichunyu
 * @Date: 2018-12-13 19:04:22
 * @LastEditTime: 2018-12-13 20:17:42
 * @LastEditors: Please set LastEditors
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int days[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, d;
    int flag = 0;
    cin >> year;
    cin >> d;

    if ((year % 100) == 0 && (year % 400) == 0) {
        flag = 1;
    } else if ((year % 4) == 0) {
        flag = 1;
    }

    if (flag)
        days[2-1] = 29;
    else
        days[2-1] = 28;
    
    int back_up = 0;
    int m = 0;
    for (int i=0; i<12; ++i) {
        back_up = d;
        d -= days[i];
        if (d <= 0) {
            m = i;
            break;
        }
    }
    if (d == 0) {
        cout << m << endl;
        cout << days[m] << endl;
    }

    if (d < 0) {
        cout << m+1 << endl;
        cout << back_up << endl;
    }
    return 0;
}
