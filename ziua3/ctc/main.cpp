#include <bits/stdc++.h>
using namespace std;

//*
#define cin fin
#define cout fout
ifstream fin("ctc.in");
ofstream fout("ctc.out");
//*/

const int N_MAX = 1e5;

int n, m;
bool viz[N_MAX+5];
int comp[N_MAX+5];
vector<int> g[N_MAX+5], gt[N_MAX+5];
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

int main()
{
    cin >> n >> m;
    while(m--)
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
        }
    }

    vector<vector<int>> compcon(nrComp+5);

    for(int i=1; i<=n; i++)
    {
        compcon[comp[i]].push_back(i);
    }

    cout << nrComp << '\n';
    for(int i=1; i<=nrComp; i++)
    {
        for(auto x:compcon[i])
        {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}