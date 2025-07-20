
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
	long long VMAX = atoll(argv[2]);

	uniform_int_distribution<long long> genv(1, VMAX);
	uniform_int_distribution<int> genc(1, 2);

	int nrelem = 0;

	cout << Q << '\n';
	while(Q--)
	{
		int C = genc(rng);
		if(nrelem==0) C=1;

		cout << C;
		if(C==1)
		{
			nrelem++;
			cout << ' ' << genv(rng);
		}
		else nrelem--;

		cout << '\n';
	}
    return 0;
}