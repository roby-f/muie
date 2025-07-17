#include <bits/stdc++.h>
using namespace std;

int n, x;
int v[200009];

int main()
{
    cin >> n >> x;
    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
    }
    sort(v+1 , v+n+1);

    int nrgon = 0;
    int st=1, dr=n;
    
    while(st<=dr)
    {
        int lm = x-v[st];
        while(v[dr]>lm)
        {
            nrgon++;
            dr--;
        }

        if(st>dr)
        {
            st++;
            dr--;
            nrgon++;
        }   
    }

    cout << nrgon;

    return 0;
}