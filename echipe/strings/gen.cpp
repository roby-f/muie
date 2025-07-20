
#include <bits/stdc++.h>

using namespace std;

mt19937 get_rng() {
	seed_seq seq {
		(uint64_t) chrono::duration_cast<chrono::nanoseconds>(
			chrono::high_resolution_clock::now().time_since_epoch()).count(),
		(uint64_t) __builtin_ia32_rdtsc(),
		(uint64_t) (uintptr_t) unique_ptr<char>(new char).get()
	};
	return mt19937(seq);
}

auto rng = get_rng();

int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	int Q = atoi(argv[2]);
	int KMAX = atoi(argv[3]);

	uniform_int_distribution<int> genk(1,(KMAX==0)?(26):(KMAX));
	int K = genk(rng);

	uniform_int_distribution<char> genlit('a', 'a'+K-1);
	uniform_int_distribution<int> genlgsir(1, 2*N+1);

	cout << N << ' ' << K << '\n';
	for(int i=1; i<=N; i++)
	{
		cout << genlit(rng);
	}

	cout << '\n' << Q << '\n';
	for(int i=1; i<=Q; i++)
	{
		int m = genlgsir(rng);
		for(int j=1; j<=m; j++)
		{
			cout << genlit(rng);
		}
		cout << '\n';
	}
    
    return 0;
}