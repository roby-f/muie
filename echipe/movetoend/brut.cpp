#include <bits/stdc++.h>

using namespace std;
int n, q;
vector<long long> v;

int main() {
    cin >> q;
    while(q--)
    {
        cin >> n;
        v.clear();
        for(int i=1; i<=n; i++)
        {
            long long x;
            cin >> x;
            v.push_back(x);
        }

        for(int k=0; k<n; k++)
        {
            long long smax = -1;

            for(int j=0; j<=n-k-1; j++)
            {
                long long s = 0;

                long long x = v[j];
                v.erase(v.begin()+j);
                v.push_back(x);
            
                for(int l=n-1; l>=n-k-1; l--)
                {
                    s += v[l];
                }

                v.pop_back();
                v.insert(v.begin()+j, x);

                smax = max(smax, s);
            }

            cout << smax << ' ';
        }

        cout << '\n';
    }

    return 0;
}
