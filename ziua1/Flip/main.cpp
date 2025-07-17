#include <bits/stdc++.h>
using namespace std;

ifstream fin("flip.in");
ofstream fout("flip.out");

int n, m, smax=INT_MIN, s=0;
int mat[20][20];

int liniineg[20];
int oloaneneg[20];

int main()
{
    fin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            fin >> mat[i][j];
        }
    }

    for(int mul=0; mul<=(1<<n); mul++)
    {
        s=0;
        for(int j=1; j<=m; j++)
        {
            int scol = 0;
            for(int i=1; i<=n; i++)
            {
                scol += mat[i][j]*((mul & 1<<i)!=0 ? -1 : 1);
            }
            
            for(int i=1; i<=n; i++)
            {
                int ml = ((mul & 1<<i)!=0 ? -1 : 1) * (scol<0 ? -1 : 1);
                s += mat[i][j]*ml;
            }
        }

        smax = max(smax, s);
    }

    fout << smax << '\n';

    return 0;
}