#include <bits/stdc++.h>
using namespace std;

const long long MO = 1000000007;

int n;
long long s[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=1; i<=1000; i++)
    {
        for(int j=1; j<=1000; j++)
        {
            s[i][j] = (i^j)+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    
    cout << LLONG_MAX << ' ' << ULLONG_MAX << '\n';

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        long long cs, cd, ls, ld;
        cin >> cs >> ls >> cd >> ld;

        cout << (s[ld][cd]-s[ls-1][cd]-s[ld][cs-1]+s[ls-1][cs-1])%MO << '\n';
    }

    return 0;
}