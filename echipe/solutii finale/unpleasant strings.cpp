#include <bits/stdc++.h>
using namespace std;

const int LG_MAX = 1000000;

int n, nrLit, q;
vector<int> poz[30];

char lin[LG_MAX+5];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> nrLit;
    for(int i=1; i<=n; i++)
    {
        char c;
        cin >> c;

        poz[c-'a'+1].push_back(i);
    }

    cin >> q;
    cin.get();
    while(q--)
    {
        cin.getline(lin, LG_MAX+3);

        int nrDeAdg = 0;

        int ultIdx = 0;
        int idxCur = 0;

        for(int i=0; lin[i]; i++)
        {
            int ichr = lin[i]-'a'+1;

            auto lw = lower_bound(poz[ichr].begin(), poz[ichr].end(), idxCur+1);
            if(lw == poz[ichr].end())
            {
                idxCur = n+1;
                break;
            }

            idxCur = *lw;

            idxCur;
            ultIdx = idxCur;
        }

        if(idxCur<=n)
        {
            idxCur++;
            while(idxCur<=n)
            {
                int idmax = idxCur;
                for(int i=1; i<=nrLit; i++)
                {
                    auto lw = lower_bound(poz[i].begin(), poz[i].end(), idxCur);
                    if(lw == poz[i].end())
                    {
                        idmax = max(idmax, n+1);
                    }
                    else
                    {
                        idmax = max(idmax, *lw);
                    }
                }

                idxCur = idmax+1;
                nrDeAdg++;
            }
            if(idxCur==n+1) nrDeAdg++;
        }

        cout << nrDeAdg << '\n';
    }
}