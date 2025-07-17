#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> aib;
int v[200009];

int lsb(int x)
{
    return (x & -x);
}
int query(int x)
{
    int s = 0;
    for(int i=x; i>0; i-=lsb(i))
    {
        s += aib[i];
    }

    return s;
}
void update(int x, int adg)
{
    for(int i=x; i<aib.size(); i+=lsb(i))
    {
        aib[i]+=adg;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        aib.clear();
        aib.resize(n+5);

        for(int i=1; i<=n; i++)
        {
            cin >> v[i];
        }

        long long s = 0;
        for(int i=n; i>=1; i--)
        {
            s+=query(v[i]);
            update(v[i], 1);
        }

        cout << s << '\n';
    }

    return 0;
}