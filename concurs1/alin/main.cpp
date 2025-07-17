#include <bits/stdc++.h>
using namespace std;

struct pct{int l, c;};
bool cmp(pct a, pct b)
{
    if(a.l<b.l) return 1;
    else if(a.l==b.l)
    {
        return a.c<b.c;
    }
    return 0;
}

int n, m, k, p;
pct q[100005];

int stersN = 0;
int desters[100005];

int frecv[100005];

int main()
{
    cin >> n >> m >> k >> p;
    for(int i=1; i<=p; i++)
    {
        cin >> q[i].l >> q[i].c;
    }
    sort(q+1, q+p+1, cmp);

    int st = 1, dr = p;

    while(st<=dr)
    {
        int mx = (st+dr)/2;

        int creste = 0;
        int nrpoze = 1;

        int stIdx = 1, sfIdx = 0;
        for(int i=1; i<=p; i++)
        {
            if(q[i].l != q[i-1].l)
            {
                sfIdx = i-1;
            }

            //cout << "A " << i << ' ' << mx << ' ' << sfIdx << '\n';

            if(frecv[q[i].c]==0)
            {
                desters[++stersN] = q[i].c;
            }
            frecv[q[i].c]++;

            if(frecv[q[i].c]>mx)
            {
                //cout << "B " << i << ' ' << mx << ' ' << q[i].l << '\n';
                //cout << "B " << stIdx << ' ' << sfIdx << '\n';
                
                while(stersN)
                {
                    frecv[desters[stersN]] = 0;
                    stersN--;
                }
                i = sfIdx;

                if(nrpoze<k)
                {
                    nrpoze++;
                }
                else
                {
                    creste = 1;
                    break;
                }
            }
        }

        while(stersN)
        {
            //cout << "A " << desters[stersN] << ' ' << frecv[desters[stersN]] << '\n';

            frecv[desters[stersN]] = 0;
            stersN--;
        }

        if(creste)
        {
            st = mx+1;
        }
        else
        {
            dr = mx-1;
        }
    }

    cout << st;
    

    return 0;
}