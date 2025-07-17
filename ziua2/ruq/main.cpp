#include <bits/stdc++.h>
using namespace std;

/*
#define cin fin
#define cout fout
ifstream fin("inv.in");
ofstream fout("inv.out");
//*/

int n, q;
vector<long long> aib;
long long v[200009];

long long lsb(long long x)
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
        //update(i, v[i]);
    }

    for(int i=1; i<=q; i++)
    {
        int c;
        cin >> c;
        if(c==1)
        {
            int a,b;
            long long u;
            cin >> a >> b >> u;

            update(a, u);
            update(b+1, -u);
        }
        else if(c==2)
        {
            int k;
            cin >> k;

            cout << v[k]+query(k) << '\n';
        }
    }
    
    return 0;
}