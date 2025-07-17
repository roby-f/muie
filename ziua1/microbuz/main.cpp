#include <bits/stdc++.h>
using namespace std;

//#define cin fin
//#define cout fout
//ifstream fin("microbuz.in");
//ofstream fout("microbuz.out");

int c, n;
int pret[12];

int pminEx=100000;
int pmin=100000, stmin;
int pmax=-1, stmax1, stmax2;

int main()
{
    cin >> c;
    for(int i=1; i<=10; i++)
    {
        cin >> pret[i];
    }
    cin >> n;
    
    for(int st=1; st<(1<<20); st++)
    {
        int p1 = 0, p2 = 0;
        int st1 = 0, st2 = 0;

        int p = 0, d = 0;
        for(int b=1; b<=10; b++)
        {
            int sh = (b-1)*2;
            int lm = ((st & (3<<sh))>>sh);

            if(st & (3<<sh))
            {
                p+=pret[b]*lm;
                d+=b*lm;

                if(lm & 1)
                {
                    p1 += pret[b];
                    st1 = st1 | (1<<(b-1));
                }
                if(lm & 2)
                {
                    p2 += pret[b];
                    st2 = st2 | (1<<(b-1));
                }
            }
        }

        if(d==n && p<pminEx)
        {
            pminEx = p;
        }
        if(d>=n && p<pmin)
        {
            pmin = p;
            stmin = st;
        }
        if(p1 == p2 && p1>pmax)
        {
            if((st1 & st2) == 0)
            {
                pmax = p1;
                stmax1 = st1;
                stmax2 = st2;
            }
        }
    }

    if(c==1)
    {
        cout << pminEx;
    }
    else if(c==2)
    {
        for(int b=1; b<=10; b++)
        {
            int sh = (b-1)*2;
            int lm = (stmin & (3<<sh))>>sh;

            for(int i=1; i<=lm; i++)
            {
                cout << b << ' ' << pret[b] << '\n';
            }
        }
    }
    else if(c==3)
    {
        cout << pmax << '\n';
        for(int b=1; b<=10; b++)
        {
            if(stmax1 & 1<<(b-1))
            {
                cout << b << ' ';
            }
        }
        cout << '\n';
        for(int b=1; b<=10; b++)
        {
            if(stmax2 & 1<<(b-1))
            {
                cout << b << ' ';
            }
        }
    }

    return 0;
}