#include <bits/stdc++.h>
using namespace std;

const int MO = 1000000007;

int n;

long long nrBiti(long long x, int b, bool z=false)
{
    if(x < 0) return 0ll;

    long long sh = (1ll << b), sh2 = (2ll << b);

    return (z ? x : 0ll) + (z ? -1ll : 1ll) * (x / sh2) * sh + max((x % sh2) - sh + 1ll, 0ll);
}

long long suma(long long xs, long long ys, long long xd, long long yd)
{
    long long s = 0ll;

    for(int i=0; i<63; i++)
    {
        long long sh = (1ll<<i)%MO;
        long long xBiti1 = nrBiti(xd, i)-nrBiti(xs-1ll, i), yBiti1 = nrBiti(yd, i)-nrBiti(ys-1ll, i);
        long long xBiti0 = (xd-xs+1ll)-xBiti1, yBiti0 = (yd-ys+1ll)-yBiti1;

        s = (s + (((xBiti0 % MO) * (yBiti1 % MO)) % MO * sh) % MO) % MO;
        s = (s + (((xBiti1 % MO) * (yBiti0 % MO)) % MO * sh) % MO) % MO;
    }

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        long long ls, cs, ld, cd;
        cin >> cs >> ls >> cd >> ld;

        cout << suma(cs, ls, cd, ld) << '\n';
    }

    return 0;
}