#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

int main() {
	std::ifstream in("Day-3\\input.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	std::vector<std::string> v;
	std::string f, b;

	while (true) {
		std::string x;
		std::cin >> x;

		if (!std::cin) break;

		v.push_back(x);
	}

	for (int i = 0; i < v[0].size(); i++) {
		std::multiset<int> s;
		for (int x = 0; x < v.size(); x++) {
			s.insert((v[x][i] - '0'));
		}
		if (s.count(0) < s.count(1)) {
			f += '1';
			b += '0';
		}
		else {
			f += '0';
			b += '1';
		}
	}

	std::cout << std::stoi(f, nullptr, 2) * std::stoi(b, nullptr, 2) << "\n";
}