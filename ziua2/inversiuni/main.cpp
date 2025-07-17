#include <bits/stdc++.h>
using namespace std;

#define cin fin
#define cout fout
ifstream fin("inversiuni.in");
ofstream fout("inversiuni.out");

int n;
vector<int> aib;

int lsb(int x)
{
    return (x & -x);
}

void update(int x, int adg)
{
    for(int p = x; p < aib.size(); p += lsb(p))
    {
        aib[p] += adg;
    }
}
int query(int x)
{
    int s = 0;
    for(int p = x; p > 0; p -= lsb(p))
    {
        s += aib[p];
    }
    return s;
}

int main()
{
    cin >> n;
    aib.resize(n+5);

    long long nrInv = 0;

    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;

        int invSt = query(x-1);
        int invDr = query(n)-query(x);

        nrInv += (long long)(min(invSt, invDr));
        update(x, 1);
    }

    cout << nrInv;

    return 0;
}