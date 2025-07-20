#include <bits/stdc++.h>
using namespace std;

int q;
int n;

int grd[200005];
vector<int> adj[200005];

int main()
{
    cin >> q;
    while(q--)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            grd[i] = 0;
            adj[i].clear();
        }
       
        for(int i=1; i<n; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);

            grd[x]++;
            grd[y]++;
        }

        for(int i=1; i<=n; i++)
        {
            sort(adj[i].begin(), adj[i].end());
        }

        int cc = 1;
        for(int rp=1; rp<=2; rp++)
        {
            int mx=-1, imx = 0, cntmax = 0;

            for(int i=1; i<=n; i++)
            {
                if(grd[i]>mx)
                {
                    mx = grd[i];
                    imx = i;
                    cntmax = 0;
                }
                
                if(grd[i]==mx && find(adj[i].begin(), adj[i].end(), imx)!=adj[i].end())
                {
                    cntmax++;

                    if(cntmax>=2)
                    {
                        imx = i;
                    }
                }
            }

            cc += mx-1;
            for(auto i:adj[imx])
            {
                grd[i]--;
                grd[imx]--;
            }
        }

        cout << cc << '\n';
    }

    return 0;
}