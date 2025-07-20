#include <bits/stdc++.h>
using namespace std;

//*
#define cin fin
#define cout fout
ifstream fin("order.in");
ofstream fout("order.out");
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
        update(i, 1);
    }

    int x = 1;
    for(int i=1; i<=n; i++)
    {
        x = (x+i-1)%(n-i+1)+1;

        int idx = gaseste(x)+1;
        if(query(idx)==x)
        {
            cout << idx << ' ';
            update(idx, -1);
        }

        x--;
    }

    return 0;
}