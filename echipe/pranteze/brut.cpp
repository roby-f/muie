#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1e6;
bitset<NMAX + 2> fr;
int n;
string s;
vector<int> v;
bool ok = 1;

void pula(int a, int b) {
    fr[v[a]] = 1;
    fr[v[b]] = 1;
    s.erase(s.begin() + a, s.begin() + b + 1);
    v.erase(v.begin() + a, v.begin() + b + 1);
    ok = 1;
}

int main () {
    cin >> n >> s;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) v[i] = i;
    while (ok) {
        ok = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' && s[i + 1] == ')') {
                pula(i, i + 1);
            }
            else if (s[i] == '[' && s[i + 1] == ']') {
                pula(i, i + 1);
            }
            else if (s[i] == '{' && s[i + 1] == '}') {
                pula(i, i + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (fr[i] == 1) {
            int ctr = 0, j;
            for (j = i; j < n; j++) {
                if (fr[j] == 0) {
                    break;
                }
                else {
                    ctr++;
                }
            }
            ans = max(ans, ctr);
            i = j - 1;
        }
    }
    cout << ans;

    return 0;
}
