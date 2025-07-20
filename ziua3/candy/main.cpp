#include <bits/stdc++.h>
using namespace std;

const int KMAX = 1000, LMAX = 10;

struct muchie{int l, c, cost;};
bool cmp(muchie a, muchie b)
{
    if(a.cost<b.cost) return 1;
    else if(a.cost==b.cost)
    {
        if(a.l<b.l) return 1;
        else if(a.l==b.l)
        {
            return a.c<b.c;
        }
    }
    return 0;
}
bool cmp2(muchie a, muchie b)
{
    if(a.c<b.c)
    {
        return 1;
    }
    else if(a.c==b.c)
    {
        return a.l<b.l;
    }
    return 0;
}

int n, m, k, w;
char nivele[KMAX+5][LMAX+2][LMAX+2];

int nrmuchii = 0;
muchie v[(KMAX+1)*(KMAX+1)+357];

int t[KMAX+5];
int graf[KMAX+5][KMAX+5];

int s = 0;

vector<int> adj[KMAX+5];

int rad(int x)
{
    if(x==t[x])
    {
        return x;
    }

    return t[x] = rad(t[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k >> w;

    for(int i=1; i<=k; i++)
    {
        t[i] = i;

        for(int l=1; l<=n; l++)
        {
            for(int c=1; c<=m; c++)
            {
                cin >> nivele[i][l][c];
            }
        }
    }


    for(int i=0; i<=k; i++)
    {
        for(int j=0; j<=k; j++)
        {
            int dst = 0;
            if(i*j==0) dst = n*m;
            else
            {
                for(int l=1; l<=n; l++)
                {   
                    for(int c=1; c<=m; c++)
                    {
                        dst = dst+(nivele[i][l][c]!=nivele[j][l][c]);
                    }
                }
                dst *= w;
            }
            ++nrmuchii;
            v[nrmuchii].l = i;
            v[nrmuchii].c = j;
            v[nrmuchii].cost = dst;
        }
    }
    sort(v+1, v+nrmuchii+1, cmp);

    for(int i=1; i<=nrmuchii; i++)
    {
        int rl = rad(v[i].l), rc = rad(v[i].c);

        if(rl != rc)
        {
            t[min(rl,rc)] = t[max(rl,rc)];
            s += v[i].cost;

            adj[v[i].l].push_back(v[i].c);
            adj[v[i].c].push_back(v[i].l);
        }
    }

    cout << s << '\n';

    bitset<KMAX+5> viz = 0;
    queue<int> bfs;
    bfs.push(0);
    while(!bfs.empty())
    {
        int x = bfs.front(); bfs.pop();
        viz[x] = 1;
        
        for(auto i:adj[x])
        {
            if(!viz[i])
            {
                viz[i] = 1;
                bfs.push(i);

                cout << i << ' ' << x << '\n';
            }
        }
    }

    return 0;
}