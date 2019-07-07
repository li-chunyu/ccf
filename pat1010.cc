#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int MAP[256];

void reversestr(char* s) {
    int len = strlen(s);
    int l = 0, r = len - 1;
    while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

/*TODO: 整数为 long long 类型
 *      二分搜索进制
 */

int main() {
    char N1[10], N2[10];
    vector<char*> nums;
    int tag, radix;
    scanf("%s", N1);
    scanf("%s", N2);
    scanf("%d", &tag);
    scanf("%d", &radix);

    reversestr(N1);
    reversestr(N2);
    nums.push_back(N1);
    nums.push_back(N2);

    for (int c = '1', i = 1; i <=9; ++i, ++c) {
        MAP[c] = i;
    }
    for (int c = 'a', i = 10; i <=35; ++i, ++c) {
        MAP[c] = i;
    }

    char *tag_num = nums[tag-1];
    long long ntag = 0;
    int len_tag = strlen(tag_num);
    for (int i = 0; i < len_tag; ++i) {
        ntag += pow(radix, i) * MAP[tag_num[i]];
    }
    long long nother = 0;
    char *other_num = nums[2-tag];
    int min_radix = 0;
    for (int i = 0; i < strlen(other_num); ++i) {
        min_radix = min(MAP[other_num[i]], min_radix);
    }
   int l_radix = min_radix + 1;
   int r_radix = 35;
   while (l_radix <= r_radix) {
     int cur = (l_radix+r_radix) / 2;
     nother = 0;
     for (int i = 0; i < strlen(other_num); ++i) {
       nother += pow(cur, i) * MAP[other_num[i]];
     }
     // printf("cur: %d, nother: %lld\n", cur, nother);
     if (nother == ntag) {
       printf("%d\n", cur);
       return 0;
     } else if (nother > ntag) {
       r_radix = cur - 1;
     } else {
       l_radix = cur + 1;
     }

   }
    printf("Impossible\n");
    return 0;
}