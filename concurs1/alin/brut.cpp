#include <bits/stdc++.h>
using namespace std;

int n, m, k, p;
int mat[1005][1005];

int mn = INT_MAX;

void bk(int idx=1, int ult=0, int mx=-1)
{
    if(ult==n)
    {
        mn = min(mn, mx);
    }
    else if(idx <= k)
    {
        vector<int> frecv(n+2, 0);
        for(int i=ult+1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(mat[i][j])
                {
                    frecv[j]++;
                    mx = max(mx, frecv[j]);
                }
            }

            bk(idx+1, i, mx);
        }
    }
}

int main()
{
    cin >> n >> m >> k >> p;
    for(int i=1; i<=p; i++)
    {
        int l, c;
        cin >> l >> c;
        mat[l][c] = 1;
    }
 
    bk();

    cout << mn;

    return 0;
}