#include <iostream>
using namespace std;

const int N_MAX = 250000, OFFSET = 200000;

int n;
int s01, s12;
int frecv01[2*N_MAX+5], frecv12[2*N_MAX+5], frecv[2*N_MAX+5], v[N_MAX+5];

int main()
{
    cin >> n;
    s01 = n;
    s12 = n;
    int s20 = n;

    frecv01[s01]++;
    frecv12[s12]++;

    frecv[s01]++;

    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> v[i];

        cout << v[i] << ' ';
    }
    cout << '\n';

    for(int i=1; i<=n; i++)
    {
        int x = v[i];

        s01 += int(x==1)-int(x==0);
        s12 += int(x==1)-int(x==2);

        if(s01==s12)
        {
            frecv[s01]++;
            cout << s01-n << ' ';
        }
        else cout << "- ";
    }
    cout << '\n';

    int rez=0;
    
    for(int i=0; i<=2*n; i++)
    {
        if(frecv[i]!=0)
        {
            cout << i-n << ": " << frecv[i] << '\n';
        }

        rez += frecv[i]*(frecv[i]-1)/2;
    }

    cout << rez;

    return 0;
}