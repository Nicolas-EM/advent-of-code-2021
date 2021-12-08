#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int fuel(const vector<int> &v) {
	int median = v[v.size() / 2], cost = 0;
	cout << "Median: " << median << "\n";
	for(int i = 0; i < v.size(); i++) {
		if (v[i] > median) cost += (v[i] - median);
		else cost += (median - v[i]);
	}
	return cost;
}

int main() {
	ifstream in("Day-7\\input.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());

	vector<int> v;
	while (true) {
		int x;
		char c;

		cin >> x >> c;

		v.push_back(x);
		if (!cin) break;
	}

	sort(v.begin(), v.end());

	cout << fuel(v);
}