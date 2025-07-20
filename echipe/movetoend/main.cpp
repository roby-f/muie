#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, mx = -2e9, x;
    cin >> n;
    vector<ll> nrmax(n + 5), prefics(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mx = max(mx, x);
        nrmax[i] = mx;
        prefics[i] = x;
        prefics[i] += prefics[i - 1];
    }
    prefics[n + 1] = prefics[n];
    for (int i = 1; i <= n; i++) {
        cout << prefics[n] - prefics[n - i + 1] + nrmax[n - i + 1] << ' ';
    }
    cout << '\n';
}

int main () {
    int tt; cin >> tt;
    while (tt--) solve();

    return 0;
}