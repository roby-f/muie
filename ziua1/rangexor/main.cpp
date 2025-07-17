#include <bits/stdc++.h>
using namespace std;

int n, q;
int xs[200005];

int main()
{
    cin >> n >> q;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        xs[i] = xs[i-1] ^ x;
    }

    for(int i=1; i<=q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (xs[b] ^ xs[a-1]) << '\n';
    }

    return 0;
}