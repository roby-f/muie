#include <bits/stdc++.h>
using namespace std;

//int aib[100000];

int n, q;
vector<long long> aib;
long long v[200009];

int lsb(int x)
{
    return (x & -x);
}
long long query(int x)
{
    long long s = 0;
    for(int i=x; i>0; i-=lsb(i))
    {
        s += aib[i];
    }

    return s;
}
void update(int x, long long adg)
{
    for(int i=x; i<aib.size(); i+=lsb(i))
    {
        aib[i]+=adg;
    }
}

int main()
{
    cin >> n >> q;
    aib.resize(n+5);

    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
        update(i, v[i]);
    }

    for(int i=1; i<=q; i++)
    {
        long long c, a, b;
        cin >> c >> a >> b;
        if(c==1)
        {
            update(a, b-v[a]);
            v[a] = b;
        }
        else if(c==2)
        {
            cout << query(b)-query(a-1) << '\n';
        }
    }

    return 0;
}