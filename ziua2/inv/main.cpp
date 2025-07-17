#include <bits/stdc++.h>
using namespace std;

//*
#define cin fin
#define cout fout
ifstream fin("inv.in");
ofstream fout("inv.out");
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

int main()
{
    cin >> n;
    aib.resize(n+5);

    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
        nrm[i] = v[i];
        //update(i, v[i]);
    }

    sort(nrm+1, nrm+n+1);

    int idx=0;
    for(int i=1; i<=n; i++)
    {
        while(nrm[i]==nrm[i+1]) i++;
        m[nrm[i]] = ++idx;
    }

    for(int i=1; i<=n; i++)
    {
        v[i] = m[v[i]];
    }

    long long s = 0;
    for(int i=n; i>=1; i--)
    {
        s = (s+query(v[i]))%9917;
        update(v[i], 1);
    }

    cout << (s%9917);

    return 0;
}