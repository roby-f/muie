#include<bits/stdc++.h>
using namespace std;

const int N_MAX = 2e5;

int n;
long long v[N_MAX+5], h[N_MAX+5], sS[N_MAX+5], sP[N_MAX+5];

long long smax = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
    }

    for(int i=1; i<=n; i++)
    {
        h[i] = max(h[i-1]+1, v[i]);
        sP[i] = sP[i-1]+(h[i]-v[i]);
    }
    for(int i=n; i>=1; i--)
    {
        h[i] = max(h[i+1]+1, v[i]);
        sS[i] = sS[i+1]+(h[i]-v[i]);
    }

    for(int i=1; i<=n; i++)
    {
        smax = min(smax, max(sP[i]+sS[i+1], sP[i-1]+sS[i]));
    }
    cout << smax;

    return 0;
}