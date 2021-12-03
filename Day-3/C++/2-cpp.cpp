#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

char getDigit(const std::vector<std::string> &v, const int pos) {
	std::multiset<char> s;
	for (int i = 0; i < v.size(); i++) s.insert(v[i][pos]);
	return (s.count('0') > s.count('1')) ? '0' : '1';
}

std::string solve(std::vector<std::string> &v, int ini, const bool o2) {
	if (v.size() == 1) return v[0];
	else {
		char max = getDigit(v, ini);
		std::vector<std::string> v2;
		for (int i = 0; i < v.size(); i++) {
			if (o2 && v[i][ini] == max) v2.push_back(v[i]);
			else if(!o2 && v[i][ini] != max) v2.push_back(v[i]);
		}
		return solve(v2, ++ini, o2);
	}
}

int main() {
	std::ifstream in("Day-3\\1-input.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	std::vector<std::string> v;

	while (true) {
		std::string x;
		std::cin >> x;

		if (!std::cin) break;

		v.push_back(x);
	}

	std::cout << std::stoi(solve(v, 0, true), nullptr, 2) * std::stoi(solve(v, 0, false), nullptr, 2) << "\n";
}