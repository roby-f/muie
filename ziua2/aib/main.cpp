#include <bits/stdc++.h>
using namespace std;

//*
#define cin fin
#define cout fout
ifstream fin("aib.in");
ofstream fout("aib.out");
//*/

int n, q;
vector<int> aib;
int v[100009];
int nrm[100009];
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
long long gas(long long s)
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
    cin >> n >> q;
    aib.resize(n+5);

    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
        update(i, v[i]);
    }

    for(int i=1; i<=q; i++)
    {
        int c;
        cin >> c;
        if(c==0)
        {
            int a, b;
            cin >> a >> b;
            update(a,b);
        }
        else if(c==1)
        {
            int a, b;
            cin >> a >> b;
            cout << query(b) - query(a-1) << '\n';
        }
        else if(c==2)
        {
            int a;
            cin >> a;
            int s = gas(a)+1;
            if(query(s)==a)
            {
                cout << s << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
    }

    return 0;
}