#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, q; cin >> n >> m >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        while (q--) {
            int type; cin >> type;
            if (type == 1) {
                int i, x; cin >> i >> x; i--;
                a[i] = x;
            } else {
                int k; cin >> k;
                int g = gcd(m,k);
                long long prev =-1;

                bool ok = true;
                for (int i=0;i<n;i++) {
                    int r = a[i]%g;
                    long long candidate;
                    if (prev < r) {
                        candidate = r;
                    } else {
                        long long diff = prev - r;
                        long long t = (diff + g - 1) / g; // ceil
                        candidate = r + t * (long long)g;
                    }
                    if (candidate >= m) {
                        ok = false;
                        break;
                    }
                    prev = candidate;
                }
                cout << (ok ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}
