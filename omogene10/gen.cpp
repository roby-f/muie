
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

	uniform_int_distribution<int> gen(0,1);

	cout << N << '\n';
	while(N--)
	{
		cout << gen(rng) << ' ';
	}
	cout << '\n';
    
    return 0;
}