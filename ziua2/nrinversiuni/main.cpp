#include <bits/stdc++.h>
using namespace std;

int n, s=0;
vector<int> aib;
int v[100009];

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
    cin >> n;
    aib.resize(n+5);

    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
    }

    for(int i=n; i>=1; i--)
    {
        s+=query(v[i]);
        update(v[i], 1);
    }

    cout << s;

    return 0;
}