#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<int> prefix_min(n);
        vector<int> suffix_max(n);
        prefix_min[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix_min[i] = min(prefix_min[i-1], a[i]);
        }
        suffix_max[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i+1], a[i]);
        }
        string result(n, '0');
        for (int i = 0; i < n; i++) {
            if (a[i]==prefix_min[i] ||a[i]==suffix_max[i]) {
                result[i] = '1';
            }
        }

        cout << result << "\n";
    }

    return 0;
}
