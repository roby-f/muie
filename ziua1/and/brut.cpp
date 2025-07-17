#include <bits/stdc++.h>
using namespace std;

//#define cin fin
//#define cout fout
//ifstream fin("and.in");
//ofstream fout("and.out");

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

    int idxmax = 0;
    for(int i=1; i<=n; i++)
    {
        int andcur = v[i];
        int lg = 0;
        for(int j=i; j<=n; j++)
        {
            andcur = andcur & v[j];
            if(andcur)
            {
                lg++;
                if(lg>lgmax)
                {
                    idxmax = j;
                    lgmax = lg;
                }
            }
            else
            {
                break;
            }
        }
    }
    cout << lgmax;

    return 0;
}