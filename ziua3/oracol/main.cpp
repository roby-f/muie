#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1e5;

struct muchie{int x, y, cost;};
bool operator<(muchie a, muchie b)
{
    return a.cost<b.cost;
}

int n;

int nrmuchii = 0;
muchie m[1000005];
int t[1005];

int rad(int x)
{
    if(t[x]==x)
    {
        return x;
    }
    return t[x] = rad(t[x]);
}
int join(int x, int y)
{
    x = rad(x);
    y = rad(y);

    if(x==y) return false;

    t[y] = t[x];

    return true;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        t[i+1] = i+1;

        for(int j=i+1; j<=n; j++)
        {
            int x;
            cin >> x;

            nrmuchii++;
            m[nrmuchii].x = i;
            m[nrmuchii].y = j;
            m[nrmuchii].cost = x;
        }
    }
    sort(m+1, m+nrmuchii+1);

    long long s = 0;
    for(int i=1; i<=nrmuchii; i++)
    {
        if(join(m[i].x, m[i].y))
        {
            s += (long long)(m[i].cost);
        }
    }
    cout << s;

    return 0;
}