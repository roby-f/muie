#include <bits/stdc++.h>
using namespace std;

int n;
long long s[250005];

int nrnorm = 0;
long long denorm[250005];
map<long long, int> idxnorm;

vector<long long> aib;

int lsb(int x)
{
    return (x & -x);
}
void update(int x, int adg)
{
    for(int i=x; i<aib.size(); i+=lsb(i))
    {
        aib[i] += (long long)(adg);
    }
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long nrscv = 0;

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> s[i];
        s[i] += s[i-1];

        if(s[i]>0) nrscv++;
        denorm[i] = s[i];
    }
    sort(denorm+1, denorm+n+1);

    for(int i=1; i<=n; i++)
    {
        while(denorm[i]==denorm[i+1] && i<n) i++;

        idxnorm[denorm[i]] = ++nrnorm;
    }

    aib.resize(nrnorm+5);

    for(int i=1; i<=n; i++)
    {
        nrscv += query(idxnorm[s[i]]-1);

        update(idxnorm[s[i]], 1);
    }

    cout << nrscv;

    return 0;
}