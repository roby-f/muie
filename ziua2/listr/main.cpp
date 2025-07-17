#include <bits/stdc++.h>
using namespace std;

/*
#define cin fin
#define cout fout
ifstream fin("aib.in");
ofstream fout("aib.out");
//*/

int n, q;
vector<int> aib;
int v[200009];
int nrm[200009];
map<int, int> m; 

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
long long gaseste(long long s)
{
    int idx = 0, sidx = 0;

    for(int p=(1<<19); p; p/=2)
    {
        if(idx+p>=aib.size())
        {
            continue;
        }

        if(sidx+aib[idx+p]<s)
        {
            sidx += aib[idx+p];
            idx += p;
        }
    }

    return idx;
}

int main()
{
    cin >> n;
    aib.resize(n+5);

    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
        update(i, 1);
    }

    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;

        int idx = gaseste(x)+1;
        if(query(idx)==x)
        {
            cout << v[idx] << ' ';
            update(idx, -1);
        }
    }

    return 0;
}