#include <bits/stdc++.h>
using namespace std;

int n, x;
long long k;
long long v[200005];
int bitsnr[40];

int main()
{
    int q;
    cin >> q;

    while(q--)
    {
        memset(v, 0, sizeof(v));
        memset(bitsnr, 0, sizeof(bitsnr));

        long long smax=LLONG_MIN, s, smvec=0;

        cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin >> v[i];
            smvec += 1ll*v[i];

            for(int j=0; j<32; j++)
            {
                if(v[i] & (1<<j)) bitsnr[j]--;
                else bitsnr[j]++;
            }
        }

        for(int i=1; i<=n; i++)
        {
            s=0;
            for(int j=0; j<32; j++)
            {
                if(v[i] & (1<<j))
                {
                    s += 1ll*(1<<j)*bitsnr[j];
                }
            }

            smax = max(smax, s);
        }
        
        cout << smax+smvec << '\n';
    }

    return 0;
}