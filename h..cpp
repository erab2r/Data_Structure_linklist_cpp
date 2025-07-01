#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int count_ones = 0;
        int left = n, right = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count_ones++;
                left = min(left, i);
                right = max(right, i);
            }
        }

        if (count_ones == 0) {
            cout << "Alice\n";
            continue;
        }

        // prefix sums for counting ones in substrings
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (s[i] == '1' ? 1 : 0);
        }

        bool substring_all_ones = false;
        for (int i = 0; i + k <= n; i++) {
            int ones_in_substring = prefix[i + k] - prefix[i];
            if (ones_in_substring == k) {
                substring_all_ones = true;
                break;
            }
        }

        if (substring_all_ones) {
            cout << "Bob\n";
            continue;
        }

        if ((right - left + 1) <= k) {
            cout << "Alice\n";
            continue;
        }

        if (count_ones <= k) {
            cout << "Alice\n";
            continue;
        }

        cout << "Bob\n";
    }

    return 0;
}
