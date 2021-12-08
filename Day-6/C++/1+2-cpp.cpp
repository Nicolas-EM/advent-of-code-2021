#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

unsigned long long sum(unsigned long long count[9]) {
	unsigned long long x = 0;
	for (int i = 0; i < 9; i++) x += count[i];
	return x;
}

unsigned long long solve(unsigned long long count[9], int t) {
	if (t == 0) return sum(count);
	else {
		unsigned long long arr[9] = {};
		for (int i = 0; i < 9; i++) {
			if (count[i] > 0) {
				if (i == 0) {
					arr[6] += count[i];
					arr[8] += count[i];
				}
				else {
					arr[i - 1] += count[i];
				}
			}
		}
		return solve(arr, --t);
	}
}

int main() {
	ifstream in("Day-6\\input.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());

	unsigned long long count[9] = {};
	while (true) {
		int x;
		char c;

		cin >> x >> c;

		count[x] += 1;
		if (!cin) break;
	}

	cout << "After 80 days there are " << solve(count, 80) << " fish\n";
	cout << "After 256 days there are " << solve(count, 256) << " fish\n";
}