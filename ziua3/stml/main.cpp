#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1e5;

int n, m;
bool viz[N_MAX+5];
int comp[N_MAX+5];
int grad[N_MAX+5];
vector<int> g[N_MAX+5];
priority_queue<int, vector<int>, greater<int>> c; 

void sort_top(int x)
{
    viz[x] = true;
    for(auto i:g[x])
    {
        if(!viz[i])
        {
            viz[i] = true;
            c.push(i);
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
        grad[y]++;
    }

    for(int i=1; i<=n; i++)
    {
        if(grad[i]==0)
        {
            c.push(i);
        }
    }

    while(!c.empty())
    {
        int t = c.top();
        c.pop();

        cout << t << ' ';
        for(auto x:g[t])
        {
            grad[x]--;
            if(grad[x]==0)
            {
                c.push(x);
            }
        }
    }

    return 0;
}