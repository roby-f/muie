#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1e5;

int n, m;
bool viz[N_MAX+5];
int comp[N_MAX+5];
long long s[N_MAX+5], ccsuma[N_MAX+5];
vector<int> g[N_MAX+5], gt[N_MAX+5], gc[N_MAX+5];
vector<int> st;

void sort_top(int x)
{
    viz[x] = true;
    for(auto i:g[x])
    {
        if(!viz[i])
        {
            sort_top(i);
        }
    }
    st.push_back(x);
}
void dfs(int x, vector<int> graf[], int idxComp)
{
    //viz[x] = true;
    comp[x] = idxComp;
    for(auto i:graf[x])
    {
        if(!comp[i])
        {
            dfs(i, graf, idxComp);
        }
    }   
}
void dfsC(int x)
{
    viz[x] = true;
    for(auto i:gc[x])
    {
        if(!viz[i])
        {
            dfsC(i);
            ccsuma[x] = ccsuma[x]+ccsuma[i];
        }
        
    }   
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> s[i];
    }
    for(int i=1; i<=m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        gt[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
    {
        if(!viz[i])
        {
            sort_top(i);
        }
    }
    reverse(st.begin(), st.end());
    memset(viz, 0, sizeof(viz));

    int nrComp = 0;
    for(auto x:st)
    {
        if(!comp[x])
        {
            dfs(x, gt, ++nrComp);
            ccsuma[comp[x]] = ccsuma[comp[x]]+s[x];
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(auto x:g[i])
        {
            gc[comp[i]].push_back(comp[x]);
        }
    }

    memset(viz, 0, sizeof(viz));
    for(int i=1; i<=nrComp; i++)
    {
        if(!viz[i])
        {
            dfsC(i);
        }
    }

    long long smax = -1;
    for(int i=1; i<=nrComp; i++)
    {
        smax = max(smax, ccsuma[i]);
    }
    cout << smax;

    return 0;
}