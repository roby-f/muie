#include <bits/stdc++.h>
using namespace std;

const unsigned long long MO = 1000000007;

int n;

/*
int msb(unsigned long long x)
{
    int i = 0;
    while(x>1ull)
    {
        x >>= 1ull ;
        i++;
    }
    return i;
}
unsigned long long suma(unsigned long long l, unsigned long long c)
{
    if(l==0 || c==0) return 0;

    unsigned long long lBiti0=0, lBiti1=0, cBiti0=0, cBiti1=0;
    unsigned long long lMSB = (1ull<<msb(l)), cMSB = (1ull<<msb(c));

    lMSB = max(lMSB, 2ull); cMSB = max(cMSB, 2ull);

    lBiti0 = (l/(lMSB<<1ull))*lMSB+min(l%(lMSB<<1ull), lMSB-1ull);
    lBiti1 = (l/(lMSB<<1ull))*lMSB+max(l%(lMSB<<1ull)-lMSB+1ull, 0ull);
    cBiti0 = (c/(cMSB<<1ull))*cMSB+min(c%(cMSB<<1ull), cMSB-1ull);
    cBiti1 = (c/(cMSB<<1ull))*cMSB+max(c%(cMSB<<1ull)-cMSB+1ull, 0ull);

    unsigned long long lAdj = l-abs(lBiti0-lBiti1), cAdj = c-abs(cBiti0-cBiti1);

    unsigned long long s = 0;
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
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        unsigned long long cs, cd, ls, ld;
        cin >> cs >> ls >> cd >> ld;

        if(cs==cd && cs==1ull)
        {
            unsigned long long s = 0;
            s = (s%MO+((ld%MO)*((ld+1ull)%MO)/2ull)%MO)%MO;
            s = (s%MO-(((ls-1ull)%MO)*(ls%MO)/2ull)%MO+MO)%MO;

            if((ld-ls+1ull) & 1ull) s++;

            cout << (s%MO+MO)%MO << '\n';
        }
    }

    return 0;
}