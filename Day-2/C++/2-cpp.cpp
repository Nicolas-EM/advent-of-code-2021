#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream in("Day-2\\input.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

	int x = 0, y = 0, aim = 0;

	while (true) {
		std::string command;
		int n;
		std::cin >> command >> n;
		if (!std::cin) break;
		else{
			switch(command[0]){
				case 'f':
					x += n;
                    y += (aim * n);
					break;
				case 'd':
					aim += n;
					break;
				case 'u':
					aim -= n;
					break;
				default:
					break;
			}
		}
	}
    
	std::cout << x * y << "\n";
}