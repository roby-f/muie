#include <bits/stdc++.h>
using namespace std;

struct film{int st, dr;};
bool cmp(film a, film b)
{
    return a.st>b.st;
}

int n, x;
film v[200009];

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> v[i].st >> v[i].dr;
    }
    sort(v+1, v+n+1, cmp);

    int st=v[1].st, dr=v[1].dr;
    int nrfilme = 1;
    for(int i=1; i<=n; i++)
    {
        st = max(st, v[i].st);
        dr = min(dr, v[i].dr);

        if(st>=dr)
        {
            nrfilme++;
            st = v[i].st;
            dr = v[i].dr;
        }
    }

    cout << nrfilme;

    return 0;
}