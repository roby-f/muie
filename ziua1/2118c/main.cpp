#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n, s=0, x;
long long k;
long long v[5005];

int main()
{
    int q;
    cin >> q;

    while(q--)
    {
        memset(v, 0, sizeof(v));
        s=0;

        cin >> n >> k;
        for(int i=1; i<=n; i++)
        {
            cin >> v[i];

            int x = v[i];
            while(x)
            {
                s++;
                x -= (x & (-x));
            }
        }

        for(int i=0; i<64; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if((v[j] & (1ll<<i))==0)
                {
                    if(k>=(1ll<<i))
                    {
                        s++;
                        k-=(1ll<<i);       
                    }
                    else
                    {
                        k=0;
                        break;
                    }
                }
            }

            if(k==0)
            {
                break;
            }
        }

        cout << s << '\n';
    }

    return 0;
}