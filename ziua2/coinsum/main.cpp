#include <bits/stdc++.h>
using namespace std;

int n;
long long v[200009];

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
    }
    sort(v+1, v+n+1);

    long long s=0;
    for(int i=1; i<=n; i++)
    {
        if(s+1ll<v[i])
        {
            break;
        }
        else s+=v[i];
    }

    cout << s+1ll;

    return 0;
}