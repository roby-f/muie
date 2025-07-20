#include <bits/stdc++.h>
using namespace std;

/*
#define cin fin
#define cout fout
ifstream fin("ctc.in");
ofstream fout("ctc.out");
//*/

int n, m;
int t[100005];
int s[100005];

int nrcomp;
int smax = 1;

int rad(int x)
{
    if(x==t[x])
    {
        return x;
    }

    return t[x] = rad(t[x]);
}

int main()
{
    cin >> n >> m;
    nrcomp = n;
    for(int i=1; i<=n; i++)
    {
        t[i] = i;
        s[i] = 1;
    }

    while(m--)
    {
        int x, y;
        cin >> x >> y;

        x = rad(x); y = rad(y);
        if(x!=y)
        {
            t[y] = x;
            s[x] += s[y];

            nrcomp--;
            smax = max(smax, s[x]);
        }

        cout << nrcomp << ' ' << smax << '\n';
    }

    return 0;
}