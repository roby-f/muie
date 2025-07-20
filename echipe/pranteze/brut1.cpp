#include <bits/stdc++.h>
using namespace std;

int smax = 0;
int n;
char v[1000005];

char parantezaopus(char c)
{
    if(c=='(') return ')';
    if(c=='[') return ']';
    if(c=='{') return '}';
    return 0;
}

int evalparanteze(int st, int dr)
{
    //cout << "INTERVAL: " << st << ' ' << dr << '\n';
    if(st>=dr) return 2;

    int pGas = v[st], pCaut = parantezaopus(v[st]);
    if(!pCaut) return -1;

    int s = 0;

    int gas = 0;

    for(int i=st; i<=dr; i++)
    {
        if(v[i]==pCaut)
        {
            int rez = evalparanteze(st+1, i-1);
            if(rez==-1)
            {
                return -1;
            }

            s += 2+rez;

            st = i+1;
            gas = i;
            if(st<=dr)
            {

                pGas = v[st];
                pCaut = parantezaopus(v[st]);

                if(!pCaut)
                {
                    return -1;
                }
            }   
        }
    }

    if(gas != dr) return -1;

    return s;
}

int main() {
    cin >> n;

    
    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
    }

    int s = 0;
    for(int i=1; i<=n; i++)
    {
        char op = parantezaopus(v[i]);

        if(op)
        {
            int gas = 0;

            for(int j=i+1; j<=n; j++)
            {
                if(v[j]==op)
                {
                    int ev = evalparanteze(i+1, j-1);
                    //cout << "REZ:  " << ev << '\n';

                    if(ev==-1)
                    {
                        s=0;
                        break;
                    }
                    else
                    {
                        gas = 1;

                        s += ev;
                        smax = max(smax, s);

                        i = j+1;
                    }
                }
            }
            if(!gas) s = 0;
        }
        else s = 0;
    }

    cout << smax;

    return 0;
}
