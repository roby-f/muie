#include <bits/stdc++.h>

using namespace std;
int n, q, k;
string s, z;
int main() {
    cin >> n >> k;
    cin >> s;
    cin >> q;
    int indx = 0, i = 0;
    while (q--) {
        string a;
        indx = 0, i = 0;
        cin >> z;
        int m = z.size();
        
        for (i = 0; i < m; i++) {
            while (s[indx] != z[i] && indx < n) {
                indx++;
            }
            if (indx < n) {
                a.push_back(s[indx++]);
            }
            else {
                break;
            }
        }
        //cout << indx << ' ';
        //cout << a << ' ' << z << '\n';
        int asd = 0;
        if (a.size() != z.size()) cout << "0\n";
        else {
            vector<bool> fr(k);
            int cnt = 0;
            for (int i = indx; i < n; i++) {
                if (fr[s[i] - 'a'] == 0) {
                    fr[s[i] - 'a'] = 1;
                    cnt++;
                }
                if (cnt == k) {
                    asd++;
                    a.push_back(s[i]);
                    cnt = 0;
                    for (int i = 0; i < k; i++) {
                        fr[i] = 0;
                    }
                }
            }

            cout << asd+1 << '\n';
        }
    }

    return 0;
}
