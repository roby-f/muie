#include <bits/stdc++.h>
using namespace std;

int q;
int n, m;
long long vec[200005];
long long frum[200005];

int main()
{
    cin >> q;
    while(q--)
    {
        long long s=0;

        cin >> n >> m;
        for(int i=1; i<=n; i++)
        {
            vec[i] = 0;
            frum[i] = 0;
            for(int j=1; j<=m; j++)
            {
                long long x;
                cin >> x;
                frum[i] += x*(m-j+1);
                vec[i] += x;
            }

            s += frum[i];
        }

        sort(vec+1, vec+n+1, greater<int>());

        for(int i=1; i<=n; i++)
        {
            s += vec[i]*1ll*(n-i)*m;
        }

        cout << s << '\n';
    }

    return 0;
}