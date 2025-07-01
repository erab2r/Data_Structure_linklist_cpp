#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n+1, 0);
        vector<bool> assigned(n+1, false);

        p[1] = 1;
        assigned[1] = true;

        for (int i = 2; i <= n; i++) {
            if (!assigned[i]) {
                vector<int> group;
                for (int j = i; j <= n; j += i) {
                    if (!assigned[j]) {
                        group.push_back(j);
                    }
                }
                int sz = (int)group.size();
                for (int k = 0; k < sz; k++) {
                    int cur = group[k];
                    int nxt = group[(k + 1) % sz];
                    p[cur] = nxt;
                    assigned[cur] = true;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << p[i] << (i == n ? '\n' : ' ');
        }
    }
}
