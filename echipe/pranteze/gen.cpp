
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

const char par[] = {"(){}[]"};
auto rng = get_rng();

int main(int argc, char *argv[]) {
	int NMAX = atoi(argv[1]);
	uniform_int_distribution<int> genn(1, NMAX);
	int N = genn(rng);

	uniform_int_distribution<int> genp(0, 5);

	cout << N << '\n';
	for(int i=1; i<=N; i++)
	{
		cout << par[genp(rng)];
	}
    
    return 0;
}