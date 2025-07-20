#include <bits/stdc++.h>
using namespace std;

//*
#define cin fin
#define cout fout
ifstream fin("schi.in");
ofstream fout("schi.out");
// */

int n;
int ranking[30005], v[30005];
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
int gaseste(int s)
{
    int idx = 0, sidx = 0;

    for(int p=(1<<19); p; p/=2)
    {
        if(idx+p>=aib.size())
        {
            continue;
        }

        if(sidx+aib[idx+p]<s)
        {
            sidx += aib[idx+p];
            idx += p;
        }
    }

    return idx;
}

int main()
{
    cin >> n;
    aib.resize(n+5);

    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
        update(i, 1);
    }

    for(int i=n; i>=1; i--)
    {
        int x = gaseste(v[i]);

        if(query(x)+1==v[i])
        {
            ranking[x+1] = i;
            update(x+1, -1);
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout << ranking[i] << '\n';
    }

    return 0;
}