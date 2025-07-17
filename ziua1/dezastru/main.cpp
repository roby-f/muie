#include <bits/stdc++.h>
using namespace std;

ifstream fin("dezastru.in");
ofstream fout("dezastru.out");

int n, k;
float v[30];
map<int, float> dp;
map<int, int> dpnr;

double inv = 1.0, s = 0.0;

int main()
{
    ios_base::sync_with_stdio(false);

    fin >> n >> k;
    for(int i=0; i<n; i++)
    {
        fin >> v[i];
    }
    dp[0] = 1.0;
    dpnr[0] = 0;

    for(int i=1; i<(1<<n); i++)
    {
        dp[i] = dp[i - (i & -i)]*v[int(log2(i & -i))];
        dpnr[i] = dpnr[i - (i & -i)]+1;
    }

    for(int i=0; i<(1<<n); i++)
    {
        if(dpnr[i]==k)
        {
            s+=dp[i];
        }
    }

    for(int i=n-k+1; i<=n; i++)
    {
        inv *= (long double)(i);
    }
    for(int i=1; i<=k; i++)
    {
        inv /= (long double)(i);
    }

    fout << fixed << setprecision(6) << s/inv;

    return 0;
}