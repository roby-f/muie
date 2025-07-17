#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[250005], fara[250005];
map<int,int> ap;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
        ap[v[i]]++;
    }

    for(int i=1; i<=m; i++)
    {
        int k;
        cin >> k;
        for(int j=1; j<=k; j++)
        {
            cin >> fara[j];
            ap[v[fara[j]]]--;
        }

        for(auto p:ap)
        {
            if(p.second>0)
            {
                cout << p.first << '\n';
                break;
            }
        }

        for(int j=1; j<=k; j++)
        {
            ap[v[fara[j]]]++;
        }
    }

    return 0;
}