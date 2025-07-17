#include <bits/stdc++.h>
using namespace std;

#define cin fin
#define cout fout
ifstream fin("and.in");
ofstream fout("and.out");

int n;
int v[120000];
int lgmax = 0;

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
    }

    for(int i=0; i<32; i++)
    {
        int lg = 0;
        for(int j=1; j<=n; j++)
        {
            if(v[j] & (1<<i))
            {
                lg++;
            }
            else lg = 0;

            lgmax = max(lg, lgmax);
        }
    }

    cout << lgmax;

    return 0;
}