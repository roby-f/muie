#include <bits/stdc++.h>
using namespace std;

const char ord[] = "\0ACGT";

int frecv[10];
char c[1000005];

int main()
{
    cin >> c;
    for(int i=0; c[i]; i++)
    {
        char x = c[i];
        for(int i=1; i<=4; i++)
        {
            if(ord[i]==x)
            {
                frecv[i]++;
                break;
            }
        }

        int ok = 1;
        for(int i=1; i<=4; i++)
        {
            if(!frecv[i])
            {
                ok=0;
                break;
            }
        }

        if(ok)
        {
            cout << x;
            for(int i=1; i<=4; i++)
            {
                frecv[i] = 0;
            }
        }
    }

    for(int i=1; i<=4; i++)
    {
        if(!frecv[i])
        {
            cout << ord[i];
            break;
        }
    }

    return 0;
}