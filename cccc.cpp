#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> freq(n + 2, 0);
        for (int x : a) freq[x]++;

        vector<int> diff(n + 2, 0);

        bool possible = true;
        long long sum_freq_less = 0;

        for (int m = 0; m <= n + 1; m++) {
            if (m > 0) {
                if (freq[m - 1] == 0) {
                    possible = false;
                }
                sum_freq_less += freq[m - 1];
            }

            if (!possible) continue;

            long long min_remove = freq[m] + (sum_freq_less - m);
            long long max_remove = n - m;

            if (min_remove > max_remove) continue;

            int start = (int)min_remove;
            int end = (int)max_remove;

            diff[start]++;
            if (end + 1 <= n) diff[end + 1]--;
        }

        for (int i = 1; i <= n; i++) {
            diff[i] += diff[i - 1];
        }

        for (int k = 0; k <= n; k++) {
            cout << diff[k] << (k == n ? '\n' : ' ');
        }
    }

    return 0;
}
