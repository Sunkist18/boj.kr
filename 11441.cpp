#include <bits/stdc++.h>

using namespace std;

int n, m;
int a, b;
vector<int> field;

int main(void) {
    cin >> n;
    field.resize(n);
    cin >> field[0];
    for (int i = 1; i < n; i++) {
        cin >> field[i];
        field[i] += field[i - 1];
    }
    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << field[--b] - field[--a - 1] << '\n';
    }
    return 0;
}