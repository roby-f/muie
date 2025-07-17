#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

long long int n;
long long s=0;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=54; i>=0; i--)
    {
        long long ss1 = 1ll<<(i+1), ss = 1ll<<i;

        s += (n/ss1)*ss;
        s += max(0ll, n%ss1-ss+1ll);
    }

    cout << s << '\n';

    return 0;
}