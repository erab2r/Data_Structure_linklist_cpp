#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), freq(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= n)
            freq[a[i]]++;
    }
    multiset<int> extras;
    vector<int> answer(n + 1, 0);
    long long deletions = 0;

    for (int mex = 0; mex <= n; ++mex) {
        // If we can't form MEX = mex because some number < mex is missing
        if ((mex > 0 && freq[mex - 1] == 0)) break;

        // Add extra occurrences of this number to deletions
        if (freq[mex] > 0) {
            for (int i = 1; i < freq[mex]; ++i) {
                extras.insert(mex);
            }
        }
        int max_k = deletions + (int)extras.size();

        for (int k = deletions; k <= n; ++k) {
            answer[k]++;
        }

        deletions += freq[mex] - 1; 

    for (int k = 0; k <= n; ++k) {
        cout << answer[k] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
