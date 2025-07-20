#include<bits/stdc++.h>
using namespace std;

int m, k;

int v[1000005], v2[1000005];
int nrzero = 0;

int md(int vc[])
{
    int r = 0;
    for(int i=1; i<=m; i++)
    {
        r = (r*10+vc[i])%k;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> k;

    for(int i=1; i<=m; i++)
    {
        char c;
        cin >> c;
        v[i] = (c-'0');
        if(c=='0') nrzero++;
    }
    sort(v+1, v+m+1);
    swap(v[1], v[nrzero+1]);

    copy(v+1, v+m+1, v2+1);

    int initk = md(v);
    for(int i=1; i<=k; i++)
    {
        next_permutation(v2+1, v2+m+1);
        if(md(v2)==initk)
        {
            int df = 0;
            for(int j=1; j<=m; j++)
            {
                if(v[j]!=v2[j]) {df=1; break;}
            }
            
            if(!df)
            {
                cout << "-1";
                exit(0);
            }

            for(int j=1; j<=m; j++)
            {
                cout << v[j];
            }
            cout << '\n';
            for(int j=1; j<=m; j++)
            {
                cout << v2[j];
            }

            exit(0);
        }
    }

    cout << "-1";

    return 0;
}