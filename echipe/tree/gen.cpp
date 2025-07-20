
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
	int Q = atoi(argv[1]);
	int NMAX = atoi(argv[2]);
	uniform_int_distribution<int> genn(2, NMAX);

	cout << Q << '\n';
	while(Q--)
	{
		int N = genn(rng);
		cout << N << '\n';

		vector<int> V;
		for(int i=1; i<=N; i++)
		{
			V.push_back(i);
		}
		shuffle(V.begin(), V.end(), get_rng());

		for(int i=1; i<N; i++)
		{
			uniform_int_distribution<int> geni(0, i-1);

			cout << V[geni(rng)] << ' ' << V[i] << '\n';
		}
	}

    return 0;
}