#include <iostream>
using namespace std;

const int N_MAX = 250000, OFFSET = 200000;

int n;
int s;
int frecv[N_MAX+5];

int main()
{
    cin >> n;
    s = n;

    frecv[s]++;

    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;

        s += (x==1 ? 1 : -1);

        frecv[s]++;
    }

    int rez=0;
    
    for(int i=0; i<=2*n; i++)
    {
        rez += frecv[i]*(frecv[i]-1)/2;
    }

    cout << rez;

    return 0;
}