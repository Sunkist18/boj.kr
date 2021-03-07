#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int n;
vector<int> field;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    field.resize(n);
    for (auto &e : field) cin >> e;
    int left = 0, right = n - 1;
    int result_left = field[left];
    int result_right = field[right];
    while (left < right) {
        if (abs(field[left] + field[right]) < abs(result_left + result_right)) {
            result_left = field[left];
            result_right = field[right];
            if (abs(field[left] + field[right]) == 0) break;
        } if (field[left] + field[right] < 0) left++;
        else right--;
    }
    cout << result_left << ' ' << result_right;
    return 0;
}
