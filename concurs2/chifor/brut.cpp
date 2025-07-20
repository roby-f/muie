#include<bits/stdc++.h>
using namespace std;

const int N_MAX = 1e6;

int q;

int n=0;
long long v[N_MAX+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--)
    {
        int c;
        cin >> c;
        if(c==1)
        {
            n++;
            cin >> v[n];
        }
        else
        {
            n--;
        }

        long long smax = 0;
        for(int i=1; i<=n; i++)
        {
            long long s = 0;
            for(int j=i; j<=n; j++)
            {
                if((j-i+1)%2==0) s -= (long long)(v[j]);
                else s += (long long)(v[j]);

                smax = max(s, smax);
            }
        }

        cout << smax << '\n';
    }

    return 0;
}