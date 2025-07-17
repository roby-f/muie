#include <bits/stdc++.h>
using namespace std;

int n, q;
int v[200005], s[200005], xs[200005];
int celmaiapr[200005];
unordered_map<int, int> ultap[2];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
        s[i] = s[i-1] + v[i];
        xs[i] = xs[i-1] ^ v[i]; 
    }
    
    for(int i=n; i>=0; i--)
    {
        if(!ultap[i%2][xs[i]])
        {
            celmaiapr[i] = n+1;
        }
        else
        {
            celmaiapr[i] = ultap[i%2][xs[i]];
        }
        ultap[(i+1)%2][xs[i]] = i;
    }

    while(q--)
    {   
        int l, r;
        cin >> l >> r;    

        if((xs[r] ^ xs[l-1])==0)
        {
            if(s[r] - s[l-1] == 0)
            {
                cout << "0\n";
            }
            else
            {
                if((r-l+1)%2!=0)
                {
                    cout << "1\n";
                }
                else if(v[l] == 0 || v[r] == 0)
                {
                    cout << "1\n";
                }
                else
                {
                    int sepoate = (celmaiapr[l-1]<=r && celmaiapr[l-1]>0);

                    if(sepoate)
                    {
                        cout << "2\n";
                    }
                    else
                    {
                        cout << "-1\n";
                    }
                }
            }
        }
        else
        {
            cout << "-1\n";
        }
    }

    return 0;
}