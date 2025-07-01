#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, j, k; cin >> n >> j >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        int player_strength = a[j-1];
        int stronger = 0;
        for (int x : a) {
            if (x > player_strength) stronger++;
        }
        cout << (stronger < k ? "YES\n" : "NO\n");
    }
    return 0;
}
