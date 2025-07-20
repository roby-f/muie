#include <bits/stdc++.h>

using namespace std;
const int NMAX = 2e5;
int n;
set<int> e[NMAX + 2];
vector<bool> fr;

struct edge{
    int a, b;
};

vector<edge> v;

void dfs(int x) {
    fr[x] = 1;
    for (auto i : e[x]) {
        if (fr[i] == 0) {
            fr[i] = 1;
            dfs(i);
        }
    }
}

void solve() {
    cin >> n;
    int ans = 0;
    v.resize(n + 1);
    fr.resize(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> v[i].a >> v[i].b;
        e[v[i].a].insert(v[i].b);
        e[v[i].b].insert(v[i].a);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for(auto k:e[i])
            {
                e[k].erase(i);
            }
            for(auto k:e[j])
            {
                e[k].erase(j);
            }

            e[i].clear();
            e[j].clear();

            int ctr = 0;
            
            for (int k = 0; k <= n; k++) fr[k] = 0;

            for (int k = 1; k <= n; k++) {
                if (!fr[k] && i!=k && j!=k) {
                    ctr++;
                    dfs(k);
                }
            }
            ans = max(ans, ctr);
            
            for (int k = 1; k < n; k++) {
                e[v[k].a].insert(v[k].b);
                e[v[k].b].insert(v[k].a);
            }
        }
    }
    cout << ans << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}

