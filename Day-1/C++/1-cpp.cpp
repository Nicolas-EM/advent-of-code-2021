#include <iostream>
#include <fstream>

int main() {
	std::ifstream in("Day-1\\input.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	int n = 0, x1;
	std::cin >> x1;

	while (true) {
		int x2;
		std::cin >> x2;

		if (!std::cin) break;
		else if (x2 > x1) n++;
		
		x1 = x2;
	}

	std::cout << n;
}