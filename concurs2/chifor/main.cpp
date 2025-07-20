#include<bits/stdc++.h>
using namespace std;

const int N_MAX = 1e6;

int q;

int n=0;
long long s[2][N_MAX+5][2];
long long sp[N_MAX+5];

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
            cin >> sp[n];
            

            int mo = n%2;

            s[1-mo][n][0] = s[1-mo][n-1][0];
            s[1-mo][n][1] = s[1-mo][n-1][1];

            s[mo][n][0] = (long long)(sp[n]);
            s[mo][n][1] = n;

            sp[n] = sp[n-1] + (n%2 ? -1 : 1)*sp[n];

            if(n>2)
            {
                int sf = s[mo][n-2][1];
                s[mo][n][0] = max(s[mo][n][0], s[mo][n-2][0]+(sf%2 ? -1ll : 1ll)*(sp[n]-sp[sf]));

                for(int i=n; i>=s[mo][n-2][1]; i-=2)
                {
                    s[mo][n][0] = max(s[mo][n][0], (i%2 ? -1ll : 1ll)*(sp[n]-sp[i-1]));
                }
            }
            if(s[mo][n-1][0]>s[mo][n][0])
            {
                s[mo][n][0] = s[mo][n-1][0];
                s[mo][n][1] = s[mo][n-1][1];
            }
        }
        else
        {
            sp[n] = 0;

            n--;
        }

        cout << max(s[0][n][0], s[1][n][0]) << '\n';
    }

    return 0;
}