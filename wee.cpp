#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<bool> used(n + 1, false);
        vector<int> perm(n + 1);  // 1-indexed
        perm[1] = 1;
        used[1] = true;

        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= n; ++j) {
                if (!used[j] && __gcd(j, i) > 1) {
                    perm[i] = j;
                    used[j] = true;
                    break;
                }
            }
            // If no valid value found, assign any remaining number
            if (perm[i] == 0) {
                for (int j = 1; j <= n; ++j) {
                    if (!used[j]) {
                        perm[i] = j;
                        used[j] = true;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << perm[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
