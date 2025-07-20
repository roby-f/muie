#include <bits/stdc++.h>

using namespace std;
ifstream fin ("flip.in");
ofstream fout ("flip.out");

int n, c;
int ans;
bool v[1002][1002];
int main() {
    fin >> c >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> v[i][j];
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (v[i][j]) {
                ans++;
                for (int k = 1; k <= i; k++) {
                    for (int m = 1; m <= j; m++) {
                        v[k][m] = !v[k][m];
                    }
                }
            }
        }
    }
    if (c == 1) {
        if (ans == 1) fout << "DA";
        else fout << "NU";
    }
    else {
        fout << ans;
    }


    return 0;
}
