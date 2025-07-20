#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1e6;

int q, n=0;
long long sp[N_MAX+5], spMin[N_MAX+5], spMax[N_MAX+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    sp[0] = 0;
    spMin[0] = 0; spMax[0] = 0;

    while(q--)
    {
        int c;
        cin >> c;
        if(c==1)
        {
            long long x;
            cin >> x;
            
            n++;
            sp[n] = sp[n-1]+x*(n%2 ? 1 : -1);
            spMin[n] = min(spMin[n-1], sp[n]);
            spMax[n] = max(spMax[n-1], sp[n]);
        }
        else
        {
            sp[n] = 0;
            spMin[n] = 0;
            spMax[n] = 0;

            n--;
        }

        cout << abs(spMax[n]-spMin[n]) << '\n';
    }

    return 0;
}