#include <bits/stdc++.h>
using namespace std;

/*
#define cin fin
#define cout fout
ifstream fin("episodul1.in");
ofstream fout("episodul1.out");
//*/

int q, n=0;

int tati[1000005];
long long s[1000005];

int rad(int x)
{
    if(x==tati[x])
    {
        return x;
    }

    tati[x] = rad(tati[x]);
    //s[tati[x]] += s[x];

    return tati[x];
}
int join(int x, int y)
{
    x = rad(x); y = rad(y);
    if(x>y) swap(x,y);

    if(x!=y)
    {
        tati[y] = tati[x];
        s[x] += s[y];
        
        return x;
    }
    return 0;
}

int main()
{
    cin >> q;
    while(q--)
    {
        int c;
        cin >> c;
        if(c==1)
        {
            n++;
            tati[n] = n;
            s[n] = 0;
        }
        else if(c==2)
        {
            int x, y, cost;

            cin >> x >> y >> cost;
            int j = join(x,y);
            if(j)
            {
                s[j] += (long long)(cost);
            }
        }
        else if(c==3)
        {
            int x;
            cin >> x;

            cout << s[rad(x)] << '\n';
        }
    }

    return 0;
}