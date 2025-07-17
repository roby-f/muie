#include <bits/stdc++.h>
using namespace std;

const int MO = 1000000007;

int n;

int msb(long long x)
{
    int i = 0;
    while(x>1ll)
    {
        x >>= 1ll ;
        i++;
    }
    return i;
}
long long suma(long long l, long long c)
{
    if(l==0 || c==0) return 0;

    long long lBiti0=0, lBiti1=0, cBiti0=0, cBiti1=0;
    long long lMSB = (1ll<<msb(l)), cMSB = (1ll<<msb(c));

    lMSB = max(lMSB, 2ll); cMSB = max(cMSB, 2ll);

    lBiti0 = (l/(lMSB<<1ll))*lMSB+min(l%(lMSB<<1ll), lMSB-1ll);
    lBiti1 = (l/(lMSB<<1ll))*lMSB+max(l%(lMSB<<1ll)-lMSB+1ll, 0ll);
    cBiti0 = (c/(cMSB<<1ll))*cMSB+min(c%(cMSB<<1ll), cMSB-1ll);
    cBiti1 = (c/(cMSB<<1ll))*cMSB+max(c%(cMSB<<1ll)-cMSB+1ll, 0ll);

    long long lAdj = l-abs(lBiti0-lBiti1), cAdj = c-abs(cBiti0-cBiti1);

    long long s = 0;
    s += lAdj%MO*(lAdj+1)%MO/2%MO*c%MO;
    s += cAdj%MO*(cAdj+1)%MO/2%MO*l%MO;
    s -= lAdj%MO*(lAdj+1)%MO/2%MO*cAdj%MO;

    s %= MO;

    for(int i=lAdj+1; i<=l; i++)
    {
        for(int j=cAdj+1; j<=c; j++)
        {
            s = (s+(i^j))%MO;
        }
    }

    cout << "- " << s << '\n';
    cout << "    * " << cBiti0 << ' ' << cBiti1 << ' ' << lBiti0 << ' ' << lBiti1 << '\n';
    cout << "    * " << cAdj << ' ' << lAdj << '\n';

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        long long ls, cs, ld, cd;
        cin >> cs >> ls >> cd >> ld;

        long long s = 0;

        s = (suma(ld, cd)-suma(ld, cs-1)+MO)%MO-suma(ls-1, cd)+suma(ls-1, cs-1);

        cout << s%MO << '\n';
    }

    cout << "\n\n\n";

    n=10;
    int m = 30;
    for(int i=1; i<=n; i++)
    {
        long long s1 = 0, s2 = 0;
        for(int j=1; j<=m; j++)
        {
            s1 += (i^j);
            s2 += j; 

            cout << s1 << "|" << s2 << "|";

            for(int k=6-1; k>=0; k--)
            {
                cout << ((j & (1<<k))!=0);
            }
            cout << "   ";
        }
        cout << '\n';
    }

    return 0;
}