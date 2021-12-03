#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream in("Day-2\\input.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	int x = 0, y = 0;

	while (true) {
		std::string command;
		int n;
		std::cin >> command >> n;
		if (!std::cin) break;
		else{
			switch(command[0]){
				case 'f':
					x += n;
					break;
				case 'd':
					y += n;
					break;
				case 'u':
					y -= n;
					break;
				default:
					break;
			}
		}
	}
    
	std::cout << x * y << "\n";
}