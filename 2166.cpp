#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int n;
// Init, Pre, Crt
int ix, iy, px, py, cx, cy;
int sum;

int solve(int a, int b, int i, int j) {
    return a * j - b * i;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    cin >> ix >> iy >> px >> py;
    px -= ix; py -= iy;
    for (int i = 0; i < n - 2; i++) {
        cin >> cx >> cy;
        cx -= ix; cy -= iy;
        sum += solve(cx, cy, px, py);
        px = cx; py = cy;
    }
    sum = abs(sum);
    if (sum % 2 == 0) cout << sum / 2 << ".0";
    else cout << sum / 2 << ".5";

    return 0;
}