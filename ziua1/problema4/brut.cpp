#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e5;
int N;
int A[MAX + 3];

bool prime(int x) {
    if(x == 0 || x == 1) return false;
    for(int i = 2; i < x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += prime(A[i]); 
    }
    cout << ans;
}