#include <iostream>
#include <fstream>
#include <vector>

int main() {
	std::ifstream in("Day-1\\2-input.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	int n = 0;
	std::vector<int> v;

	while (true) {
		int x;
		std::cin >> x;
		if (!std::cin) break;
		v.push_back(x);
	}

	int count = v[0] + v[1] + v[2];
	for (int i = 3; i < v.size(); i++) {
		if (count < count + v[i] - v[i - 3]) n++;
		count += (v[i] - v[i - 3]);
	}

	std::cout << n;
}