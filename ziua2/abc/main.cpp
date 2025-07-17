#include <bits/stdc++.h>
using namespace std;

#define cin fin
#define cout fout
ifstream fin("abc.in");
ofstream fout("abc.out");

int n, b, c, s;
int v[30005];
int d[30005];

int nrb=0;

int sign(int x)
{
    if(x>0) return 1;
    else if(x<0) return -1;
    return 0;
}

int main()
{
    cin >> n >> b >> c;
    nrb = n;

    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
        s += v[i];

        d[i] = v[i];

        if(v[i]==b) nrb--;
    }
    sort(d+1, d+n+1);

    c -= s;
    int iter = 0;

    if(c<0) nrb = n;

    while(c)
    {
        int sgC = sign(c);

        if(sgC*c>=nrb)
        {
            iter += sgC;
            c = sgC*abs(c-nrb);

            if(c>0 && d[nrb]+iter>=b)
            {
                nrb--;
            }
        }
        else
        {
            for(int i=1; i<=nrb; i++)
            {
                d[i]+=iter;
                if(i<=sgC*c)
                {
                    d[i]+=sgC;
                }
            }
            sort(d+1, d+nrb+1);

            if(c>0 && d[nrb]>=b)
            {
                nrb--;
            }

            c=0;
            iter = 0;
        }
    }

    int difmx = 0;
    for(int i=1; i<=n; i++)
    {
        difmx = max(difmx, abs(d[i]+iter-v[i]));
    }

    cout << difmx;

    return 0;
}