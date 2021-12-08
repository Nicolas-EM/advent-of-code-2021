#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int fuel(const vector<int> &v, const int sum) {
	int mean = sum / v.size(), cost = 0;
	cout << "Mean: " << mean << "\n";
	for(int i = 0; i < v.size(); i++) {
		int n;
		if (v[i] > mean) n = (v[i] - mean);
		else n = (mean - v[i]);
		cost += (n*(n + 1) / 2);
	}
	return cost;
}

int main() {
	ifstream in("Day-7\\input.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());

	vector<int> v;
	int s = 0;
	while (true) {
		int x;
		char c;

		cin >> x >> c;

		s += x;
		v.push_back(x);
		if (!cin) break;
	}

	sort(v.begin(), v.end());

	cout << fuel(v, s);
}