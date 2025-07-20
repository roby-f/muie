#include <bits/stdc++.h>
using namespace std;

//*
#define cin fin
#define cout fout
ifstream fin("datorii.in");
ofstream fout("datorii.out");
//*/

int n, q;

vector<int> aib;

int lsb(int x)
{
    return (x & -x);
}
void update(int x, int adg)
{
    for(int i=x; i<aib.size(); i+=lsb(i))
    {
        aib[i] += adg;
    }
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

int main()
{
    cin >> n >> q;
    aib.resize(n+5);

    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        update(i, x);
    }

    while(q--)
    {
        int c, a, b;
        cin >> c >> a >> b;

        if(c==0)
        {
            update(a, -b);
        }
        else if(c==1)
        {
            cout << query(b)-query(a-1) << '\n';
        }
    }

    return 0;
}