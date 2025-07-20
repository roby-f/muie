#include <bits/stdc++.h>
using namespace std;

ifstream fin("paranteze.in");
ofstream fout("paranteze.out");

const int NMAX = 1e6;

bitset<NMAX + 2> fr;
int n, ans;
char c;
bool ok = 0;

struct stract {
    int i;
    char c;
};

stack<stract> s;

void notare(int a, int b) {
    s.pop();
    fr[a] = 1;
    fr[b] = 1;
}

int main() {
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> c;

        int psh = 1;
        if (!s.empty()) {
            if (c == ')') {
                if (s.top().c == '(') {
                    psh = 0;
                    notare(s.top().i, i);
                }
            }
            else if (c == ']') {
                if (s.top().c == '[') {
                    psh = 0;
                    notare(s.top().i, i);
                }
            }
            else if (c == '}') {
                if (s.top().c == '{') {
                    psh = 0;
                    notare(s.top().i, i);
                }
            }
        }
        
        if (psh) {
            stract x;
            x.i = i;
            x.c = c;
            s.push(x);
        }
        
    }
    for (int i = 1; i <= n; i++) {
        int j = i+1;
        int ctr = 0;
        if (fr[i] == 1) {
            for (j = i; j <= n; j++) {
                if (fr[j] == 0) {
                    break;
                }
                else {
                    ctr++;
                }
            }
        }
        ans = max(ans, ctr);
        i = j - 1;
    }

    fout << ans;

    return 0;
}
