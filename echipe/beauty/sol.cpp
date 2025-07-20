#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2e5;

int t;

int n, v[NMAX+5], g[NMAX+5];
vector<int> adj[NMAX+5];
bitset<NMAX+5> viz = 0;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while(t--)
    {
        cin >> n;

        long nrmuchii = 0, nrnoduri = n;
        viz = 0;

        for(int i=1; i<=n; i++)
        {
            cin >> v[i];

            g[i] = 0;
            adj[i].clear();
            for(int j=1; j<i; j++)
            {
                if(v[i]%v[j]==0 || v[j]%v[i]==0)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);

                    g[i]++;
                    g[j]++;

                    nrmuchii++;
                }
            }
        }

        while(nrmuchii != (nrnoduri * (nrnoduri - 1ll) / 2ll))
        {
            int mingrad = 10000000, mngridx=-1;
            for(int i=1; i<=n; i++)
            {
                if(g[i]<mingrad)
                {
                    mingrad = g[i];
                    mngridx = i;
                }
            }

            viz[mngridx] = 1;
            nrnoduri--;
            for(auto x:adj[mngridx])
            {
                if(!viz[x])
                {
                    nrmuchii--;
                    g[x]--;
                    g[mngridx]--;
                }
            }
        }

        cout << n-nrnoduri << '\n';
    }

    return 0;
}

