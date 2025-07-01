#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; 
        cin >> n >> k;
        string s; 
        cin >> s;
        vector<int> ones_pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones_pos.push_back(i);
        }
        if (ones_pos.empty()) {
            cout << "Alice\n";
            continue;
        }

        int total_ones = (int)ones_pos.size();
        int min_pos = ones_pos.front();
        int max_pos = ones_pos.back();

        if (total_ones <= k) {
            cout << "Alice\n";
        }
        else if (max_pos - min_pos + 1 <= k) {
            cout << "Alice\n";
        }
        else {
            int left_substring_end = min_pos + k - 1;
            int right_substring_start = max_pos - k + 1;

            if (right_substring_start > left_substring_end) {
                cout << "Bob\n";
            } else {
                cout << "Alice\n";
            }
        }
    }

    return 0;
}
