#include <iostream>
using namespace std;

const int N_MAX = 250000;

int n;
int v[N_MAX+5];
int frecv[2];
int rez = 0;

int main()
{
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
    }

    for(int i=1; i<=n; i++)
    {
        frecv[0] = frecv[1] = 0;
        for(int j=i; j<=n; j++)
        {
            frecv[v[j]]++;

            if(frecv[0]==frecv[1])
            {
                rez++;
            }
        }
    }

    cout << rez;

    return 0;
}